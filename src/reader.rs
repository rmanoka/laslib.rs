use lastools_sys::*;
use std::ffi::*;
use std::os::unix::ffi::*;

use std::path::Path;

use super::{LasPoint, PointsIter};

pub struct LasReader {
    handle: LASreaderLAS,
    point_index: u64,
}
impl LasReader {
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
            Some(LasReader{
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
            self.point_index += idx;
        }
        flag
    }
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

    pub fn point(&self) -> &LasPoint {
        &self.handle._base.point
    }
    pub fn point_mut(&mut self) -> &mut LasPoint {
        &mut self.handle._base.point
    }
    pub fn point_index(&self) -> u64 {
        self.point_index
    }

    pub fn points_iter<'a, F, T>(&'a mut self, f: &'a mut F) -> PointsIter<'a, F, T>
    where F: for<'b> FnMut(&'b LasPoint) -> T {
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
impl Drop for LasReader {
    fn drop(&mut self) {
        self.close(true);
    }
}
unsafe impl Send for LasReader {}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    #[ignore]
    fn iterate_las() {
        use std::path::PathBuf;
        use std::time::Instant;
        let path: PathBuf = std::env::var_os("LASFILE")
            .expect("env LASFILE not set").into();

        let start = Instant::now();

        let mut reader = LasReader::open(&path)
            .expect("open las failed");
        let num = reader.len();

        eprintln!("Loaded {} with {} points", path.display(), num);

        let idx = 9_000_000.min(num);
        reader.seek(idx);
        eprintln!("Seeked to idx {}", idx);
        eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

        let count = reader.points_iter(&mut |_| ()).count()
            as u64;
        eprintln!("Read {} points", count);
        eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

        assert_eq!(count, num - idx);
    }
}
