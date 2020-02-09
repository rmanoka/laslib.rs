#include <lasreader.hpp>
#include "cwrapper.h"

extern "C" {
  bool LASreader_read_point(void *self){
    return reinterpret_cast<LASreader *>(self)->read_point();
  }
}
