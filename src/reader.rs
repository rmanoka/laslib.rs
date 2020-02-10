use lastools_sys::*;
use std::ffi::*;
use std::os::unix::ffi::*;

use std::path::Path;

use super::{Point, PointsIter};

pub struct Reader {
    handle: LASreaderLAS,
    point_index: u64,
}
impl Reader {
    pub fn open(path: &Path) -> Option<Self> {
        let path_str = CString::new(
            path.as_os_str().as_bytes()).unwrap();

        let mut handle = unsafe{ LASreaderLAS::new() };
        let result = unsafe{ handle.open(
            path_str.as_ptr(),
            LAS_TOOLS_IO_IBUFFER_SIZE,
            false,
            LASZIP_DECOMPRESS_SELECTIVE_ALL,
        )};
        if result {
            Some(Reader{
                handle,
                point_index: 0,
            })
        } else {
            None
        }
    }
    pub fn seek(&mut self, idx: u64) -> bool {
        let flag = unsafe {root::LASreaderLAS_seek(
            &mut self.handle as *mut LASreaderLAS as *mut c_void,
            idx as i64,
        )};
        if flag {
            self.point_index = (self.point_index + idx) as u64;
        }
        flag
    }

    #[inline]
    pub fn len(&self) -> u64 {
        self.handle._base.npoints as u64
    }

    pub fn read_point(&mut self) -> bool {
        let flag = unsafe {
            hacks::LASreader_read_point(
                &mut self.handle._base as *mut LASreader
                    as *mut c_void
            )
        };
        if flag { self.point_index += 1; }
        flag
    }

    #[inline]
    pub fn point(&self) -> &Point {
        &self.handle._base.point
    }
    #[inline]
    pub fn point_mut(&mut self) -> &mut Point {
        &mut self.handle._base.point
    }
    #[inline]
    pub fn point_index(&self) -> u64 {
        self.point_index
    }

    pub fn points_iter<'a, F, T>(&'a mut self, f: &'a mut F) -> PointsIter<'a, F>
    where F: for<'b> FnMut(&'b Point) -> T {
        PointsIter::from(self, f)
    }

    fn close(&mut self, close_stream: bool) {
        unsafe {
            root::LASreaderLAS_close(
                &mut self.handle as *mut LASreaderLAS
                    as *mut c_void,
                close_stream,
            )
        }
    }
}
impl Drop for Reader {
    fn drop(&mut self) {
        self.close(true);
    }
}
unsafe impl Send for Reader {}
