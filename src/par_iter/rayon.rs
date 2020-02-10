use super::*;
use ::rayon::iter::plumbing::*;
use ::rayon::iter::*;

impl<'a, F, T> UnindexedProducer for ParPointsIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T + Sync,
      T: Send {
    type Item = T;

    fn split(mut self) -> (Self, Option<Self>) {
        let right = self.bisect();
        (self, right)
    }

    fn fold_with<FF: Folder<T>>(self, mut folder: FF) -> FF {
        let iter = IntoIterator::into_iter(self);
        if folder.full() { return folder; }
        for it in iter {
            folder = folder.consume(it);
            if folder.full() { return folder; }
        }
        folder
    }
}

impl<'a, F, T> ParallelIterator for ParPointsIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T + Sync,
      T: Send {
    type Item = T;
    fn drive_unindexed<C>(self, consumer: C) -> C::Result
    where C: UnindexedConsumer<Self::Item> {
        bridge_unindexed(self, consumer)
    }
}

impl<'a, F, T> DoubleEndedIterator for IntoIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T {
    fn next_back(&mut self) -> Option<T> {
        self.next()
    }
}

impl<'a, F, T> Producer for ParPointsIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T + Sync {
    type IntoIter = IntoIter<'a, F>;
    type Item = T;

    fn into_iter(self) -> IntoIter<'a, F> {
        std::iter::IntoIterator::into_iter(self)
    }
    fn split_at(mut self, idx: usize) -> (Self, Self) {
        let idx = idx as u64 + self.start;
        let right = ParPointsIter::split_at(&mut self, idx);
        (self, right.unwrap())
    }
}

impl<'a, F, T> IndexedParallelIterator for ParPointsIter<'a, F>
where F: for<'b> Fn(&'b Point) -> T + Sync,
      T: Send {
    fn len(&self) -> usize {
        ParPointsIter::len(self) as usize
    }

    fn with_producer<CB: ProducerCallback<Self::Item>>(
        self, callback: CB
    ) -> CB::Output {
        callback.callback(self)
    }

    fn drive<C>(self, consumer: C) -> C::Result
    where C: Consumer<Self::Item> {
        bridge(self, consumer)
    }
}
