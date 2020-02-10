pub type Point = lastools_sys::LASpoint;

pub mod reader;
pub use reader::Reader;

pub mod iter;
pub use iter::PointsIter;

#[cfg(test)]
mod tests;
