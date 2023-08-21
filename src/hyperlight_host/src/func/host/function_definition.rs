use crate::{
    flatbuffers::hyperlight::generated::{
        HostFunctionDefinition as FbHostFunctionDefinition,
        HostFunctionDefinitionArgs as FbHostFunctionDefinitionArgs,
        ParameterType as FbParameterType,
    },
    func::types::{ParameterType, ReturnType},
};
use anyhow::Result;
use flatbuffers::{FlatBufferBuilder, WIPOffset};

/// The definition of a function exposed from the host to the guest
#[derive(Debug, Default, Clone, PartialEq, Eq)]
pub(crate) struct HostFunctionDefinition {
    /// The function name
    pub(crate) function_name: String,
    /// The type of the parameter values for the host function call.
    pub(crate) parameter_types: Option<Vec<ParameterType>>,
    /// The type of the return value from the host function call
    pub(crate) return_type: ReturnType,
}

impl HostFunctionDefinition {
    /// Create a new `HostFunctionDefinition`.
    pub(crate) fn new(
        function_name: String,
        parameter_types: Option<Vec<ParameterType>>,
        return_type: ReturnType,
    ) -> Self {
        Self {
            function_name,
            parameter_types,
            return_type,
        }
    }

    /// Convert this `HostFunctionDefinition` into a `WIPOffset<FbHostFunctionDefinition>`.
    pub(crate) fn convert_to_flatbuffer_def<'a>(
        &self,
        builder: &mut FlatBufferBuilder<'a>,
    ) -> Result<WIPOffset<FbHostFunctionDefinition<'a>>> {
        let host_function_name = builder.create_string(&self.function_name);
        let return_value_type = self.return_type.clone().into();
        let vec_parameters = match &self.parameter_types {
            Some(vec_pvt) => {
                let num_items = vec_pvt.len();
                let mut parameters: Vec<FbParameterType> = Vec::with_capacity(num_items);
                for pvt in vec_pvt {
                    let fb_pvt = pvt.clone().into();
                    parameters.push(fb_pvt);
                }
                Some(builder.create_vector(&parameters))
            }
            None => None,
        };

        let fb_host_function_definition: WIPOffset<FbHostFunctionDefinition> =
            FbHostFunctionDefinition::create(
                builder,
                &FbHostFunctionDefinitionArgs {
                    function_name: Some(host_function_name),
                    return_type: return_value_type,
                    parameters: vec_parameters,
                },
            );

        Ok(fb_host_function_definition)
    }
}

impl TryFrom<FbHostFunctionDefinition<'_>> for HostFunctionDefinition {
    type Error = anyhow::Error;
    fn try_from(value: FbHostFunctionDefinition) -> Result<Self> {
        let function_name = value.function_name().to_string();
        let return_type = value.return_type().try_into()?;
        let parameter_types = match value.parameters() {
            Some(pvt) => {
                let len = pvt.len();
                let mut pv: Vec<ParameterType> = Vec::with_capacity(len);
                for fb_pvt in pvt {
                    let pvt: ParameterType = fb_pvt.try_into()?;
                    pv.push(pvt);
                }
                Some(pv)
            }
            None => None,
        };

        Ok(Self::new(function_name, parameter_types, return_type))
    }
}

impl TryFrom<&[u8]> for HostFunctionDefinition {
    type Error = anyhow::Error;
    fn try_from(value: &[u8]) -> Result<Self> {
        let fb_host_function_definition = flatbuffers::root::<FbHostFunctionDefinition<'_>>(value)?;
        Self::try_from(fb_host_function_definition)
    }
}

impl TryFrom<&HostFunctionDefinition> for Vec<u8> {
    type Error = anyhow::Error;
    fn try_from(hfd: &HostFunctionDefinition) -> Result<Vec<u8>> {
        let mut builder = flatbuffers::FlatBufferBuilder::new();
        let host_function_definition = hfd.convert_to_flatbuffer_def(&mut builder)?;
        builder.finish_size_prefixed(host_function_definition, None);
        Ok(builder.finished_data().to_vec())
    }
}

impl TryFrom<HostFunctionDefinition> for Vec<u8> {
    type Error = anyhow::Error;
    fn try_from(value: HostFunctionDefinition) -> Result<Vec<u8>> {
        (&value).try_into()
    }
}
