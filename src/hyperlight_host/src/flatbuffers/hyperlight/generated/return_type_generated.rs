// automatically generated by the FlatBuffers compiler, do not modify
// @generated
extern crate alloc;
extern crate flatbuffers;
use alloc::boxed::Box;
use alloc::string::{String, ToString};
use alloc::vec::Vec;
use core::mem;
use core::cmp::Ordering;
use self::flatbuffers::{EndianScalar, Follow};
use super::*;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MIN_RETURN_TYPE: u8 = 0;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MAX_RETURN_TYPE: u8 = 5;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
#[allow(non_camel_case_types)]
pub const ENUM_VALUES_RETURN_TYPE: [ReturnType; 6] = [
  ReturnType::hlint,
  ReturnType::hllong,
  ReturnType::hlstring,
  ReturnType::hlbool,
  ReturnType::hlvoid,
  ReturnType::hlsizeprefixedbuffer,
];

#[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash, Default)]
#[repr(transparent)]
pub struct ReturnType(pub u8);
#[allow(non_upper_case_globals)]
impl ReturnType {
  pub const hlint: Self = Self(0);
  pub const hllong: Self = Self(1);
  pub const hlstring: Self = Self(2);
  pub const hlbool: Self = Self(3);
  pub const hlvoid: Self = Self(4);
  pub const hlsizeprefixedbuffer: Self = Self(5);

  pub const ENUM_MIN: u8 = 0;
  pub const ENUM_MAX: u8 = 5;
  pub const ENUM_VALUES: &'static [Self] = &[
    Self::hlint,
    Self::hllong,
    Self::hlstring,
    Self::hlbool,
    Self::hlvoid,
    Self::hlsizeprefixedbuffer,
  ];
  /// Returns the variant's name or "" if unknown.
  pub fn variant_name(self) -> Option<&'static str> {
    match self {
      Self::hlint => Some("hlint"),
      Self::hllong => Some("hllong"),
      Self::hlstring => Some("hlstring"),
      Self::hlbool => Some("hlbool"),
      Self::hlvoid => Some("hlvoid"),
      Self::hlsizeprefixedbuffer => Some("hlsizeprefixedbuffer"),
      _ => None,
    }
  }
}
impl core::fmt::Debug for ReturnType {
  fn fmt(&self, f: &mut core::fmt::Formatter) -> core::fmt::Result {
    if let Some(name) = self.variant_name() {
      f.write_str(name)
    } else {
      f.write_fmt(format_args!("<UNKNOWN {:?}>", self.0))
    }
  }
}
impl<'a> flatbuffers::Follow<'a> for ReturnType {
  type Inner = Self;
  #[inline]
  unsafe fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
    let b = flatbuffers::read_scalar_at::<u8>(buf, loc);
    Self(b)
  }
}

impl flatbuffers::Push for ReturnType {
    type Output = ReturnType;
    #[inline]
    unsafe fn push(&self, dst: &mut [u8], _written_len: usize) {
        flatbuffers::emplace_scalar::<u8>(dst, self.0);
    }
}

impl flatbuffers::EndianScalar for ReturnType {
  type Scalar = u8;
  #[inline]
  fn to_little_endian(self) -> u8 {
    self.0.to_le()
  }
  #[inline]
  #[allow(clippy::wrong_self_convention)]
  fn from_little_endian(v: u8) -> Self {
    let b = u8::from_le(v);
    Self(b)
  }
}

impl<'a> flatbuffers::Verifiable for ReturnType {
  #[inline]
  fn run_verifier(
    v: &mut flatbuffers::Verifier, pos: usize
  ) -> Result<(), flatbuffers::InvalidFlatbuffer> {
    use self::flatbuffers::Verifiable;
    u8::run_verifier(v, pos)
  }
}

impl flatbuffers::SimpleToVerifyInSlice for ReturnType {}
