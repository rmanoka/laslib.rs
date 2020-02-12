#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
include!("bindings.rs");

pub mod hacks {
    extern "C" {
        pub fn LASreader_read_point(self_: *mut ::std::os::raw::c_void) -> bool;
    }
}
mod point;

use std::os::raw::*;
pub const LASZIP_DECOMPRESS_SELECTIVE_ALL: c_uint = 0xFFFFFFFF;
pub const LAS_TOOLS_IO_IBUFFER_SIZE: c_int = 262144;

pub use root::LASreaderLAS;
pub use root::LASreader;
pub use root::LASpoint;
pub use root::LASquantizer;

// Calling destructor leads to in-explicable segfaults
// impl LASreaderLAS {
//     fn destruct(&mut self) {
//         unsafe {
//             root::LASreaderLAS_LASreaderLAS_destructor(self as *mut LASreaderLAS);
//         }
//     }
// }
// impl Drop for LASreaderLAS {
//     fn drop(&mut self) { self.destruct() }
// }

// Apparently the derived class destructor calls the parent class
// Calling this too leads to SIGABRT
// impl LASreader {
//     fn destruct(&mut self) {
//         unsafe {
//             root::LASreader_LASreader_destructor(self);
//         }
//     }
// }
// impl Drop for LASreader {
//     fn drop(&mut self) { self.destruct() }
// }
