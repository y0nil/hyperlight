/// Definitions for common functions to be exposed in the guest
pub(crate) mod exports;
/// Represents a function call.
pub(crate) mod function_call;
/// Types used to pass data to/from the guest.
pub(crate) mod guest;
/// Definitions and functionality to enable guest-to-host function calling,
/// also called "host functions"
///
/// This module includes functionality to do the following
///
/// - Define several prototypes for what a host function must look like,
/// including the number of arguments (arity) they can have, supported argument
/// types, and supported return types
/// - Registering host functions to be callable by the guest
/// - Dynamically dispatching a call from the guest to the appropriate
/// host function
pub(crate) mod host;
/// Definitions and functionality for supported parameter types
pub(crate) mod param_type;
/// Definitions and functionality for supported return types
pub(crate) mod ret_type;
/// Definitions for types related to functions used by both the guest and the
/// host. This includes the types of parameters and return values that are
/// supported in Hyperlight.
pub(crate) mod types;