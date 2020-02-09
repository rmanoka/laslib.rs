cmake_minimum_required(VERSION 3.10)

project(LastoolsRsHacks)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(LASLIB REQUIRED)

add_library(laslib-hacks cwrapper.cpp)
target_link_libraries(laslib-hacks PRIVATE las)
set_target_properties(laslib-hacks PROPERTIES PUBLIC_HEADER cwrapper.h)

install(TARGETS laslib-hacks
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include
  )
