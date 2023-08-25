use super::hypervisor::HypervisorWrapperMgr;
#[cfg(target_os = "windows")]
use crate::func::exports::get_os_page_size;
#[cfg(target_os = "windows")]
use crate::hypervisor::handlers::OutBHandlerCaller;
#[cfg(target_os = "windows")]
use crate::mem::ptr::RawPtr;
use crate::sandbox::mem_mgr::MemMgrWrapperGetter;
use crate::{hypervisor::handlers::OutBHandlerWrapper, Sandbox, UninitializedSandbox};
#[cfg(target_os = "linux")]
use anyhow::bail;
use anyhow::Result;
#[cfg(target_os = "windows")]
use std::os::raw::c_void;
#[cfg(target_os = "windows")]
use std::sync::{Arc, Mutex};
use tracing::instrument;

pub(super) type CBFunc<'a> = Box<dyn FnOnce(&mut UninitializedSandbox<'a>) -> Result<()> + 'a>;

/// The implementation for evolving `UninitializedSandbox`es to
/// `Sandbox`es.
///
/// Note that `cb_opt`'s type has been carefully considered.
/// Particularly, it's not using a constrained generic to define
/// the type of the callback because if it did, you'd have to provide
/// type hints to the compiler if you want to pass `None` to the function.
/// With this type signature, you can pass `None` without having to do that.
///
/// If this doesn't make sense and you want to change this type,
/// please reach out to a Hyperlight developer before making the change.
#[instrument(err(Debug), skip_all)]
pub(super) fn evolve_impl<'a>(
    mut u_sbox: UninitializedSandbox<'a>,
    cb_opt: Option<CBFunc<'a>>,
) -> Result<Sandbox<'a>> {
    let outb_wrapper = u_sbox.get_hypervisor_wrapper().get_outb_hdl_wrapper();
    let run_from_proc_mem = u_sbox.run_from_process_memory;
    if run_from_proc_mem {
        evolve_in_proc(&mut u_sbox, outb_wrapper)?;
    } else {
        let mem_mgr = {
            // we are gonna borrow u_sbox mutably below in our
            // get_hypervisor_mut call, so we need to borrow it
            // immutably here, and disallow that borrow to escape this scope
            // so we can do the mutable borrow later.
            //
            // luckily, cloning SandboxMemoryManagers is cheap, so we can do
            // that and avoid the borrow going out of this scope by moving the
            // clone
            let mgr = u_sbox.mgr.as_ref();
            mgr.clone()
        };

        {
            let hv = &mut u_sbox.hv;
            hv.initialise(&mem_mgr)
        }?;
    }
    if let Some(cb) = cb_opt {
        cb(&mut u_sbox)?;
    }

    Ok(Sandbox::from(u_sbox))
}

#[cfg(target_os = "windows")]
// This function allows us to call the OutBHandler from the guest when running in process
// As it is only called from the guest we need to allow dead code
// NOTE: This is not part of the C Hyperlight API , it is intended only to be called in proc through a pointer passed to the guest
extern "C" fn call_outb(ptr: *mut Arc<Mutex<dyn OutBHandlerCaller>>, port: u16, data: u64) {
    let outb_handlercaller = unsafe { Box::from_raw(ptr) };
    let res = outb_handlercaller
        .lock()
        .expect("Error Locking")
        .call(port, data);
    assert!(res.is_ok());
    // Leak the box so that it is not dropped when the function returns
    // the box will be dropped when the sandbox is dropped
    Box::leak(outb_handlercaller);
}

fn evolve_in_proc(
    u_sbox: &mut UninitializedSandbox<'_>,
    outb_hdl: OutBHandlerWrapper,
) -> Result<()> {
    #[cfg(target_os = "linux")]
    {
        // Note from old C# implementation of this function:
        //
        // This code is unstable, it causes segmentation faults so for now we
        // are throwing an exception if we try to run in process in Linux.
        // I think this is due to the fact that the guest binary is built for
        // windows x64 compilation for windows uses fastcall which is different
        // on windows and linux dotnet will default to the calling convention
        // for the platform that the code is running on.
        // so we need to set the calling convention to the one for which the
        // guest binary is build (windows x64 calling convention docs:
        // https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention?view=msvc-170
        // ).
        // on linux however, this isn't possible (see this document for more
        // details: https://docs.microsoft.com/en-us/dotnet/api/system.runtime.interopservices.callingconvention?view=net-6.0
        //.
        //
        // Alternatives:
        //
        // 1. build the binary for windows and linux and then run the correct
        // version for the platform on which we're running.
        //
        // 2. alter the calling convention of the guest binary and then tell
        // dotnet to use that calling convention. the only option for this
        // seems to be vectorcall
        // (https://docs.microsoft.com/en-us/cpp/cpp/vectorcall?view=msvc-170).
        // cdecl and stdcall are not possible using CL on x64 platform.
        // vectorcall is not supported by dotnet
        // (see https://github.com/dotnet/runtime/issues/8300)
        //
        // 3. write our own code to correct the calling convention
        //
        // 4. write epilog/prolog code in the guest binary.
        //
        // also see https://www.agner.org/optimize/calling_conventions.pdf
        // and https://eli.thegreenplace.net/2011/09/06/stack-frame-layout-on-x86-64/

        // the following lines are here to ensure clippy/rustc doesn't
        // complain about the following parameters:
        //
        // - u_sbox being marked mut and unused
        // - outb_hdl being unused
        let _ = u_sbox.get_mem_mgr_wrapper_mut();
        let _ = outb_hdl;
        bail!("in-process execution is not supported on linux");
    }
    #[cfg(target_os = "windows")]
    {
        // To be able to call outb from the guest we need to provide both the address of the function and a pointer to
        // OutBHandlerWrapper, the guest can then call call_outb passing he pointer to OutBHandlerWrapper as the first argument

        // The box we create here is evenutally dropped in the Sandbox drop function
        let context = Box::into_raw(Box::new(outb_hdl)) as u64;
        let outb_ptr = call_outb as *const c_void as u64;

        let mgr = u_sbox.get_mem_mgr_wrapper_mut().as_mut();
        mgr.set_outb_address_and_context(outb_ptr, context)?;
        let peb_address = {
            let base_addr = u64::try_from(mgr.shared_mem.base_addr())?;
            mgr.get_peb_address(base_addr)
        }?;
        let page_size = u32::try_from(get_os_page_size())?;
        let seed = {
            use rand::Rng;
            let mut rng = rand::thread_rng();
            rng.gen::<u64>()
        };
        unsafe { u_sbox.call_entry_point(RawPtr::from(peb_address), seed, page_size) }
    }
}

#[cfg(test)]
mod tests {
    use super::evolve_impl;
    use crate::{sandbox::uninitialized::GuestBinary, UninitializedSandbox};
    use anyhow::anyhow;
    use hyperlight_testing::{callback_guest_path, simple_guest_path};

    #[test]
    fn test_evolve() {
        let guest_bin_paths = vec![simple_guest_path().unwrap(), callback_guest_path().unwrap()];
        for guest_bin_path in guest_bin_paths {
            let u_sbox = UninitializedSandbox::new(
                GuestBinary::FilePath(guest_bin_path.clone()),
                None,
                None,
            )
            .unwrap();
            evolve_impl(u_sbox, None)
                .map_err(|e| {
                    anyhow!("error evolving sandbox with guest binary {guest_bin_path}: {e:?}")
                })
                .unwrap();
        }
    }

    #[test]
    fn test_evolve_in_proc() {
        use crate::SandboxRunOptions;

        let guest_bin_paths = vec![simple_guest_path().unwrap(), callback_guest_path().unwrap()];
        for guest_bin_path in guest_bin_paths {
            let u_sbox: UninitializedSandbox<'_> = UninitializedSandbox::new(
                GuestBinary::FilePath(guest_bin_path.clone()),
                None,
                Some(SandboxRunOptions::RUN_IN_PROCESS),
            )
            .unwrap();
            #[cfg(target_os = "windows")]
            {
                let err = format!("error evolving sandbox with guest binary {guest_bin_path}");
                let err_str = err.as_str();
                evolve_impl(u_sbox, None).expect(err_str);
            }
            #[cfg(target_os = "linux")]
            {
                let res = evolve_impl(u_sbox, None);
                assert!(res.is_err());
            }
        }
    }
}