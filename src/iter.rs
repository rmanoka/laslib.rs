use super::{Reader, Point};

pub struct PointsIter<'a, F> {
    reader: &'a mut Reader,
    producer: &'a mut F,
}

impl<'a, F, T> PointsIter<'a, F>
where F: for<'b> FnMut(&'b Point) -> T {
    pub fn from(reader: &'a mut Reader, producer: &'a mut F) -> Self {
        PointsIter {reader, producer}
    }
}

impl<'a, F, T> Iterator for PointsIter<'a, F>
where F: for<'b> FnMut(&'b Point) -> T {
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

impl<'a, F, T> ExactSizeIterator for PointsIter<'a, F>
where F: for<'b> FnMut(&'b Point) -> T {}
