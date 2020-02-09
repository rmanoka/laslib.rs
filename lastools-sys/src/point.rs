use super::LASpoint;
use super::LASquantizer;

impl LASquantizer {
    #[inline]
    pub fn get_x(&self, x: i32) -> f64 {
        self.x_scale_factor * x as f64 + self.x_offset
    }
    #[inline]
    pub fn get_y(&self, y: i32) -> f64 {
        self.y_scale_factor * y as f64 + self.y_offset
    }
    #[inline]
    pub fn get_z(&self, z: i32) -> f64 {
        self.z_scale_factor * z as f64 + self.z_offset
    }
}

impl LASpoint {
    #[inline]
    pub fn get_x(&self) -> f64 {
        unsafe { &*self.quantizer } .get_x(self.X)
    }

    #[inline]
    pub fn get_y(&self) -> f64 {
        unsafe { &*self.quantizer } .get_y(self.Y)
    }

    #[inline]
    pub fn get_z(&self) -> f64 {
        unsafe { &*self.quantizer } .get_z(self.Z)
    }
}
