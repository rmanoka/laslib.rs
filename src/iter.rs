use super::{LasReader, LasPoint};

use std::marker::PhantomData;
pub struct PointsIter<'a, F, T> {
    reader: &'a mut LasReader,
    producer: &'a mut F,
    _phantom: PhantomData<fn(T) -> T>
}

impl<'a, F, T> PointsIter<'a, F, T>
where F: for<'b> FnMut(&'b LasPoint) -> T {
    pub fn from(reader: &'a mut LasReader, producer: &'a mut F) -> Self {
        PointsIter {reader, producer, _phantom: PhantomData}
    }
}

impl<'a, F, T> Iterator for PointsIter<'a, F, T>
where F: for<'b> FnMut(&'b LasPoint) -> T {
    type Item = T;
    fn next(&mut self) -> Option<T> {
        if self.reader.read_point() {
            Some((self.producer)(self.reader.point()))
        } else {
            None
        }
    }
    fn size_hint(&self) -> (usize, Option<usize>) {
        let rem = self.reader.len() - self.reader.point_index();
        let rem = rem as usize;
        (rem, Some(rem))
    }
}

impl<'a, F, T> ExactSizeIterator for PointsIter<'a, F, T>
where F: for<'b> FnMut(&'b LasPoint) -> T {}
