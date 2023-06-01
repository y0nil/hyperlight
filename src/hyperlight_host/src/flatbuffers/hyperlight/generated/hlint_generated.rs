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
pub enum hlintOffset {}
#[derive(Copy, Clone, PartialEq)]

pub struct hlint<'a> {
  pub _tab: flatbuffers::Table<'a>,
}

impl<'a> flatbuffers::Follow<'a> for hlint<'a> {
  type Inner = hlint<'a>;
  #[inline]
  unsafe fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
    Self { _tab: flatbuffers::Table::new(buf, loc) }
  }
}

impl<'a> hlint<'a> {
  pub const VT_VALUE: flatbuffers::VOffsetT = 4;

  #[inline]
  pub unsafe fn init_from_table(table: flatbuffers::Table<'a>) -> Self {
    hlint { _tab: table }
  }
  #[allow(unused_mut)]
  pub fn create<'bldr: 'args, 'args: 'mut_bldr, 'mut_bldr>(
    _fbb: &'mut_bldr mut flatbuffers::FlatBufferBuilder<'bldr>,
    args: &'args hlintArgs
  ) -> flatbuffers::WIPOffset<hlint<'bldr>> {
    let mut builder = hlintBuilder::new(_fbb);
    builder.add_value(args.value);
    builder.finish()
  }


  #[inline]
  pub fn value(&self) -> i32 {
    // Safety:
    // Created from valid Table for this object
    // which contains a valid value in this slot
    unsafe { self._tab.get::<i32>(hlint::VT_VALUE, Some(0)).unwrap()}
  }
}

impl flatbuffers::Verifiable for hlint<'_> {
  #[inline]
  fn run_verifier(
    v: &mut flatbuffers::Verifier, pos: usize
  ) -> Result<(), flatbuffers::InvalidFlatbuffer> {
    use self::flatbuffers::Verifiable;
    v.visit_table(pos)?
     .visit_field::<i32>("value", Self::VT_VALUE, false)?
     .finish();
    Ok(())
  }
}
pub struct hlintArgs {
    pub value: i32,
}
impl<'a> Default for hlintArgs {
  #[inline]
  fn default() -> Self {
    hlintArgs {
      value: 0,
    }
  }
}

pub struct hlintBuilder<'a: 'b, 'b> {
  fbb_: &'b mut flatbuffers::FlatBufferBuilder<'a>,
  start_: flatbuffers::WIPOffset<flatbuffers::TableUnfinishedWIPOffset>,
}
impl<'a: 'b, 'b> hlintBuilder<'a, 'b> {
  #[inline]
  pub fn add_value(&mut self, value: i32) {
    self.fbb_.push_slot::<i32>(hlint::VT_VALUE, value, 0);
  }
  #[inline]
  pub fn new(_fbb: &'b mut flatbuffers::FlatBufferBuilder<'a>) -> hlintBuilder<'a, 'b> {
    let start = _fbb.start_table();
    hlintBuilder {
      fbb_: _fbb,
      start_: start,
    }
  }
  #[inline]
  pub fn finish(self) -> flatbuffers::WIPOffset<hlint<'a>> {
    let o = self.fbb_.end_table(self.start_);
    flatbuffers::WIPOffset::new(o.value())
  }
}

impl core::fmt::Debug for hlint<'_> {
  fn fmt(&self, f: &mut core::fmt::Formatter<'_>) -> core::fmt::Result {
    let mut ds = f.debug_struct("hlint");
      ds.field("value", &self.value());
      ds.finish()
  }
}
