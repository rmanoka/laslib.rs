#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
include!("bindings.rs");
// include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

use std::os::raw::*;
pub const LASZIP_DECOMPRESS_SELECTIVE_ALL: c_uint = 0xFFFFFFFF;
pub const LAS_TOOLS_IO_IBUFFER_SIZE: c_int = 262144;

pub use root::LASreaderLAS;

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
