#[cfg(feature = "rayon")]
pub mod rayon;

use super::{Reader, Point};

use std::path::Path;
pub fn par_points_iter<'a, F, T>(
    path: &'a Path, prod: &'a F, start: u64, end: Option<u64>
) -> Option<ParPointsIter<'a, F>>
where F: for<'b> Fn(&'b Point) -> T + Sync, T: Send {

    let end = end.or_else(|| {
        let reader = Reader::open(path)?;
        Some(reader.len())
    })?;

    Some(ParPointsIter{
        path, prod, start, end,
    })

}

pub struct ParPointsIter<'a, F> {
    pub path: &'a Path,
    pub prod: &'a F,
    pub start: u64,
    pub end: u64,
}

impl<'a, F> Clone for ParPointsIter<'a, F> {
    fn clone(&self) -> Self {
        ParPointsIter {
            path: &self.path,
            prod: &self.prod,
            start: self.start,
            end: self.end,
        }
    }
}

impl<'a, F> ParPointsIter<'a, F> {
    #[inline]
    pub fn len(&self) -> u64 {
        self.end - self.start.min(self.end)
    }

    pub fn bisect(&mut self) -> Option<Self> {
        if self.len() < 2 {
            None
        } else {
            let mid = self.start + (self.end - self.start) / 2;
            self.split_at(mid)
        }
    }

    pub fn split_at(&mut self, idx: u64) -> Option<Self> {
        if idx <= self.start || idx >= self.end {
            None
        } else {
            let mut right = self.clone();
            right.start = idx;
            self.end = idx;
            Some(right)
        }
    }
}

pub struct IntoIter<'a, F> {
    reader: Reader,
    prod: &'a F,
    start: u64,
    end: u64,
}

impl<'a, F, T> From<ParPointsIter<'a, F>> for IntoIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T {
    fn from(inp: ParPointsIter<'a, F>) -> Self {
        let mut reader = Reader::open(&inp.path)
            .expect("opening reader");
        assert!(reader.seek(inp.start), "unable to seek to start");
        IntoIter { reader, prod: inp.prod, start: inp.start, end: inp.end }
    }
}

impl<'a, F, T> Iterator for IntoIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T {
    type Item = T;
    fn next(&mut self) -> Option<T> {
        if self.start >= self.end {
            None
        } else if !self.reader.read_point() {
            panic!("failed to read point");
        } else {
            self.start += 1;
            Some((self.prod)(self.reader.point()))
        }
    }
    fn size_hint(&self) -> (usize, Option<usize>) {
        let len = self.end - self.start.min(self.end);
        let len = len as usize;
        (len, Some(len))
    }
}

impl<'a, F, T> ExactSizeIterator for IntoIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T {}

impl<'a, F, T> IntoIterator for ParPointsIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T {
    type IntoIter = IntoIter<'a, F>;
    type Item = T;
    fn into_iter(self) -> IntoIter<'a, F> {
        self.into()
    }
}
