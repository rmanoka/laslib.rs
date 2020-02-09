#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

use std::os::raw::*;

pub const LASZIP_DECOMPRESS_SELECTIVE_ALL: c_uint = 0xFFFFFFFF;
pub const LAS_TOOLS_IO_IBUFFER_SIZE: c_int = 262144;

pub type LasReaderH = *mut c_void;
pub type LasPointH = *mut c_void;

pub use root::{
    LASpoint_field_X,
    LASpoint_field_Y,
    LASpoint_field_Z,
    LASpoint_field_intensity,
    LASpoint_field_scan_angle_rank,
    LASpoint_field_user_data,
    LASpoint_field_point_source_ID,
    LASpoint_field_extended_scan_angle,
    LASpoint_field_extended_classification,
    LASpoint_field_deleted_flag,
    LASpoint_field_dummy,
    LASpoint_field_gps_time_change,
    LASpoint_field_gps_time,
    LASpoint_field_rgb,
    LASpoint_field_wavepacket,
    LASpoint_field_extra_bytes,
    LASpoint_field_quantizer,
    LASpoint_field_coordinates,
    LASpoint_field_attributer,
    LASpoint_field_point,
    LASpoint_field_have_gps_time,
    LASpoint_field_have_rgb,
    LASpoint_field_have_nir,
    LASpoint_field_have_wavepacket,
};

pub use root::{
    LASreaderLAS_close,
    LASreaderLAS_create,
    LASreaderLAS_destroy,
    LASreaderLAS_open,
    LASreaderLAS_seek,
    LASreader_field_npoints,
    LASreader_field_point,
    LASreader_read_point,
};
