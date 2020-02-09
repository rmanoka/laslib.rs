use lastools_sys::*;
use std::ffi::*;
use std::os::unix::ffi::*;

use std::path::Path;
use failure::bail;

use super::Result;
// use super::point::LasPoint;

pub struct LasReader {
    handle: LASreaderLAS,
}
impl LasReader {
    pub fn open(path: &Path) -> Result<Self> {
        let path_str = CString::new(
            path.as_os_str().as_bytes()).unwrap();

        let handle = unsafe{ LASreaderLAS::new() };
        let result = unsafe{ handle.open(
            path_str.as_ptr(),
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
    // pub fn seek(&mut self, idx: i64) -> bool {
    //     unsafe {LASreaderLAS_seek(
    //         self.handle,
    //         idx,
    //     )}
    // }
    // pub fn len(&self) -> i64 {
    //     unsafe{ *LASreader_field_npoints(
    //         self.handle,
    //     )}
    // }
    // pub fn next_point(&mut self) -> Option<LasPoint> {
    //     let flag = unsafe{LASreader_read_point(
    //         self.handle
    //     )};
    //     if flag {
    //         Some(LasPoint::from_reader_ptr(
    //             &*self,
    //             unsafe {LASreader_field_point(
    //                 self.handle,
    //             )}
    //         ))
    //     } else { None }
    // }
    // pub fn iter(&mut self) -> Iter {
    //     Iter{ reader: self, _phantom: PhantomData }
    // }

    // fn close(&self) {
    //     unsafe{ LASreaderLAS_close(
    //         self.handle,
    //         true,
    //     )}
    // }
}

// use std::marker::PhantomData;
// pub struct Iter<'a> {
//     reader: *mut LasReader,
//     _phantom: PhantomData<&'a ()>,
// }

// impl<'a> Iterator for Iter<'a> {
//     type Item = LasPoint<'a>;
//     fn next(&mut self) -> Option<LasPoint<'a>> {
//         let reader: &'a mut LasReader = unsafe { &mut *self.reader };
//         reader.next_point()
//     }
// }

// impl Drop for LasReader {
//     fn drop(&mut self) {
//         self.close();
//         unsafe {
//             LASreaderLAS_destroy(self.handle)
//         }
//     }
// }

// unsafe impl Send for LasReader {}

// #[cfg(test)]
// mod tests {
//     use super::*;
//     #[test]
//     #[ignore]
//     fn iterate_las() {
//         let path = std::env::var_os("LASFILE")
//             .expect("env LASFILE not set");
//         let mut reader = LasReader::open(Path::new(&path))
//             .expect("open las");

//         let num = reader.len();
//         let last = 100.max(num);
//         reader.seek(num - last);
//         let count = reader.iter().count() as i64;
//         assert_eq!(count, last);
//     }
// }
