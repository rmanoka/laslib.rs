pub type Result<T> = std::result::Result<T, failure::Error>;

pub mod reader;
pub use reader::LasReader;

pub mod point;
