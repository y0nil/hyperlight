use hyperlight_flatbuffers::flatbuffer_wrappers::function_types::{ParameterValue, ReturnType};
use tracing::{span, Level};
extern crate hyperlight_host;
use hyperlight_host::{
    sandbox::uninitialized::UninitializedSandbox,
    sandbox_state::{sandbox::EvolvableSandbox, transition::Noop},
    GuestBinary, MultiUseSandbox, Result,
};
use hyperlight_testing::simple_guest_path;
use std::sync::{Arc, Mutex};
use std::thread::{spawn, JoinHandle};
use tracing_forest::ForestLayer;
use tracing_subscriber::{
    layer::SubscriberExt, util::SubscriberInitExt, EnvFilter, Layer, Registry,
};
use uuid::Uuid;

fn fn_writer(_msg: String) -> Result<i32> {
    Ok(0)
}

// Shows how to consume trace events from Hyperlight using the tracing-subscriber crate.
// and also how to consume logs as trace events.

fn main() -> Result<()> {
    // Set up the tracing subscriber.
    // tracing_forest uses the tracing subscriber, which, by default, will consume logs as trace events
    // unless the tracing-log feature is disabled.
    let layer = ForestLayer::default().with_filter(EnvFilter::from_default_env());
    Registry::default().with(layer).init();
    run_example()
}
fn run_example() -> Result<()> {
    // Get the path to a simple guest binary.
    let hyperlight_guest_path =
        simple_guest_path().expect("Cannot find the guest binary at the expected location.");

    let mut join_handles: Vec<JoinHandle<Result<()>>> = vec![];

    // Construct a new span named "hyperlight tracing example" with INFO  level.
    let span = span!(Level::INFO, "hyperlight tracing example",);
    let _entered = span.enter();

    for i in 0..10 {
        let path = hyperlight_guest_path.clone();
        let writer_func = Arc::new(Mutex::new(fn_writer));
        let handle = spawn(move || -> Result<()> {
            // Construct a new span named "hyperlight tracing example thread" with INFO  level.
            let id = Uuid::new_v4();
            let span = span!(
                Level::INFO,
                "hyperlight tracing example thread",
                context = format!("Thread number {}", i),
                uuid = %id,
            );
            let _entered = span.enter();

            // Create a new sandbox.
            let usandbox = UninitializedSandbox::new(
                GuestBinary::FilePath(path),
                None,
                None,
                Some(&writer_func),
            )?;

            // Initialize the sandbox.

            let no_op = Noop::<UninitializedSandbox, MultiUseSandbox>::default();

            let mut multiuse_sandbox = usandbox.evolve(no_op)?;

            // Call a guest function 5 times to generate some log entries.
            for _ in 0..5 {
                let result = multiuse_sandbox.call_guest_function_by_name(
                    "Echo",
                    ReturnType::String,
                    Some(vec![ParameterValue::String("a".to_string())]),
                );
                assert!(result.is_ok());
                multiuse_sandbox = result.unwrap().0;
            }

            // Define a message to send to the guest.

            let msg = "Hello, World!!\n".to_string();

            // Call a guest function that calls the HostPrint host function 5 times to generate some log entries.
            for _ in 0..5 {
                let result = multiuse_sandbox.call_guest_function_by_name(
                    "PrintOutput",
                    ReturnType::Int,
                    Some(vec![ParameterValue::String(msg.clone())]),
                );
                assert!(result.is_ok());
                multiuse_sandbox = result.unwrap().0;
            }
            Ok(())
        });
        join_handles.push(handle);
    }

    // Create a new sandbox.
    let usandbox = UninitializedSandbox::new(
        GuestBinary::FilePath(hyperlight_guest_path.clone()),
        None,
        None,
        None,
    )?;

    // Initialize the sandbox.

    let no_op = Noop::<UninitializedSandbox, MultiUseSandbox>::default();

    let mut multiuse_sandbox = usandbox.evolve(no_op)?;

    // Call a function that gets cancelled by the host function 5 times to generate some log entries.

    for i in 0..5 {
        let id = Uuid::new_v4();
        // Construct a new span named "hyperlight tracing call cancellation example thread" with INFO  level.
        let span = span!(
            Level::INFO,
            "hyperlight tracing call cancellation example thread",
            context = format!("Thread number {}", i),
            uuid = %id,
        );
        let _entered = span.enter();
        let mut ctx = multiuse_sandbox.new_call_context();

        let result = ctx.call("Spin", ReturnType::Void, None);
        assert!(result.is_err());
        let result = ctx.finish();
        assert!(result.is_ok());
        multiuse_sandbox = result.unwrap();
    }

    for join_handle in join_handles {
        let result = join_handle.join();
        assert!(result.is_ok());
    }

    Ok(())
}