use crate::func::guest::GuestFunction;
use anyhow::Result;

use super::mem_mgr::MemMgr;

/// Enables the host to call functions in the guest and have the sandbox state reset at the start of the call
pub(crate) trait CallGuestFunction<'a>: MemMgr {
    fn call_guest_function<T, R>(&self, function: T) -> Result<R>
    where
        T: GuestFunction<R>,
    {
        // TODO: call reset_state() here

        function.call()
        // ^^^ ensures that only one call can be made concurrently
        // because `GuestFunction` is implemented for `Arc<Mutex<T>>`
        // so we'll be locking on the function call. There are tests
        // below that demonstrate this.
    }
}

#[cfg(test)]
mod tests {
    use crate::testing::simple_guest_path;
    use crate::UninitializedSandbox;

    use super::*;
    use std::{
        sync::{Arc, Mutex},
        thread,
    };

    // simple function
    fn test_function0() -> Result<i32> {
        Ok(42)
    }

    struct GuestStruct;

    // function that return type unsupported by the host
    fn test_function1() -> Result<GuestStruct> {
        Ok(GuestStruct)
    }

    // function that takes a parameter
    fn test_function2(param: i32) -> Result<i32> {
        Ok(param)
    }

    #[test]
    fn test_call_guest_function() {
        let uninitialized_sandbox = || {
            UninitializedSandbox::new(
                simple_guest_path().expect("Guest Binary Missing"),
                None,
                None,
            )
            .unwrap()
        };
        fn init(_: &mut UninitializedSandbox) -> Result<()> {
            Ok(())
        }

        // test_function0
        {
            let usbox = uninitialized_sandbox();
            let sandbox = usbox
                .initialize(Some(init))
                .expect("Failed to initialize sandbox");
            let result = sandbox.call_guest_function(Arc::new(Mutex::new(test_function0)));
            assert_eq!(result.unwrap(), 42);
        }

        // test_function1
        {
            let usbox = uninitialized_sandbox();
            let sandbox = usbox
                .initialize(Some(init))
                .expect("Failed to initialize sandbox");
            let result = sandbox.call_guest_function(Arc::new(Mutex::new(test_function1)));
            assert!(result.is_ok());
        }

        // test_function2
        {
            let usbox = uninitialized_sandbox();
            let sandbox = usbox
                .initialize(Some(init))
                .expect("Failed to initialize sandbox");
            let result =
                sandbox.call_guest_function(Arc::new(Mutex::new(move || test_function2(42))));
            assert_eq!(result.unwrap(), 42);
        }

        // test concurrent calls with a local closure that returns current count
        {
            let usbox = uninitialized_sandbox();
            let sandbox = usbox
                .initialize(Some(init))
                .expect("Failed to initialize sandbox");

            let count = Arc::new(Mutex::new(0));
            let order = Arc::new(Mutex::new(vec![]));

            let mut handles = vec![];

            for _ in 0..10 {
                let sandbox = sandbox.clone();
                let count = Arc::clone(&count);
                let order = Arc::clone(&order);
                let handle = thread::spawn(move || {
                    let result = sandbox.call_guest_function(Arc::new(Mutex::new(move || {
                        let mut num = count.lock().unwrap();
                        *num += 1;
                        Ok(*num)
                    })));
                    order.lock().unwrap().push(result.unwrap());
                });
                handles.push(handle);
            }

            for handle in handles {
                handle.join().unwrap();
            }

            // Check if the order of operations is sequential
            let order = order.lock().unwrap();
            for i in 0..10 {
                assert_eq!(order[i], i + 1);
            }
        }

        // TODO: Add tests to ensure State has been reset.
    }
}
