use lastools_sys::*;
use std::ffi::*;
use std::os::unix::ffi::*;

use std::path::Path;
use failure::bail;

use super::Result;
use super::point::LasPoint;

pub struct LasReader {
    handle: LasReaderH
}
impl LasReader {
    pub fn open(path: &Path) -> Result<Self> {
        let path_str = CString::new(
            path.as_os_str().as_bytes()).unwrap();

        let handle = unsafe{ LASreaderLAS_create() };
        let result = unsafe{ LASreaderLAS_open(
            handle,
            path_str.as_ptr() as *const c_void,
            LAS_TOOLS_IO_IBUFFER_SIZE,
            false,
            LASZIP_DECOMPRESS_SELECTIVE_ALL,
        )};
        if result {
            Ok(LasReader{handle})
        } else {
            bail!("couldn't open: {}", path.display())
        }
    }
    pub fn seek(&mut self, idx: i64) -> bool {
        unsafe {LASreaderLAS_seek(
            self.handle,
            idx,
        )}
    }
    pub fn len(&self) -> i64 {
        unsafe{ *LASreader_field_npoints(
            self.handle,
        )}
    }
    pub fn read_point(&mut self) -> bool {
        unsafe{LASreader_read_point(
            self.handle
        )}
    }

    pub fn next_point(&mut self) -> Option<LasPoint> {
        if self.read_point() {
            Some(LasPoint::from_reader_ptr(
                &*self,
                unsafe {LASreader_field_point(
                    self.handle,
                )}
            ))
        } else { None }
    }
    pub fn iter(&mut self) -> Iter {
        Iter{ reader: self, _phantom: PhantomData }
    }

    fn close(&self) {
        unsafe{ LASreaderLAS_close(
            self.handle,
            true,
        )}
    }
}

use std::marker::PhantomData;
pub struct Iter<'a> {
    reader: *mut LasReader,
    _phantom: PhantomData<&'a ()>,
}

impl<'a> Iterator for Iter<'a> {
    type Item = LasPoint<'a>;
    fn next(&mut self) -> Option<LasPoint<'a>> {
        let reader: &'a mut LasReader = unsafe { &mut *self.reader };
        reader.next_point()
    }
}

impl Drop for LasReader {
    fn drop(&mut self) {
        self.close();
        unsafe {
            LASreaderLAS_destroy(self.handle)
        }
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
            .expect("open las");
        let num = reader.len();

        eprintln!("Loaded {} with {} points", path.display(), num);
        eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());

        let last = 100.min(num);
        reader.seek(last);
        eprintln!("Seeked to idx {}", last);
        let mut count = 0;
        while reader.read_point() { count += 1; }
        eprintln!("Read {} points", count);
        eprintln!("  in {:.2} s", start.elapsed().as_secs_f32());
        assert_eq!(last + count, num);

    }
}
