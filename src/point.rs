use lastools_sys::*;

use super::reader::LasReader;

pub struct LasPoint<'a> {
    handle: LasPointH,
    _owner: &'a LasReader
}

macro_rules! field_getter {
    ($name:ident, $ret:ty, $bind:ident) => {
            pub fn $name(&self) -> $ret {
                unsafe{ *$bind(self.handle) }
            }
    }
}

impl LasPoint<'_> {
    field_getter!(get_x, i32, LASpoint_field_X);
    field_getter!(get_y, i32, LASpoint_field_Y);
    field_getter!(get_z, i32, LASpoint_field_Z);
    field_getter!(get_intensity, u16, LASpoint_field_intensity);

    pub fn get_rgba(&self) -> [u16; 4] {
        use std::convert::TryInto;
        unsafe{std::slice::from_raw_parts(
            LASpoint_field_rgb(self.handle) as *const u16,
            4,
        )}.try_into().unwrap()
    }

    pub(crate) fn from_reader_ptr(_owner: &LasReader, handle: LasPointH) -> LasPoint {
        LasPoint {_owner, handle}
    }
}
