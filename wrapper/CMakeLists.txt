cmake_minimum_required(VERSION 3.10)

project(LastoolsSys)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(LASLIB REQUIRED)

option(GENERATE_WRAPPER "Generate C wrapper for las (needs clang, llvm libs)")

set(WRAPPER_NAME "cwrapper")
if(GENERATE_WRAPPER)
  message(STATUS "Generating C wrapper for las")

  find_package(Clang REQUIRED)
  message(STATUS "Found Clang in ${CLANG_INSTALL_PREFIX}")
  message(STATUS "Found Clang headers in ${CLANG_INCLUDE_DIRS}")
  message(STATUS "Found LLVM headers in ${LLVM_INCLUDE_DIRS}")

  include_directories("${LLVM_INCLUDE_DIRS}" "${CLANG_INCLUDE_DIRS}")
  add_executable(generate
    EXCLUDE_FROM_ALL
    generate.cpp)
  target_link_libraries(generate
    PRIVATE
    clangTooling
    clangBasic
    clangASTMatchers
    )

  configure_file(lib.hpp lib.hpp)
  add_custom_command(OUTPUT "${WRAPPER_NAME}.cpp" "${WRAPPER_NAME}.h"
    COMMAND ./generate lib.hpp
    DEPENDS generate lib.hpp
    )
else()
  message(STATUS "Using pre-generated C wrapper ${WRAPPER_NAME}")
endif()

# add_custom_target(generate_wrapper ALL
#   DEPENDS cwrapper.cpp cwrapper.h
#   )

configure_file("${WRAPPER_NAME}.h" "${WRAPPER_NAME}.h")
add_library(laslib-wrapper "${WRAPPER_NAME}.cpp")
target_link_libraries(laslib-wrapper PRIVATE las)
set_target_properties(laslib-wrapper PROPERTIES PUBLIC_HEADER "${WRAPPER_NAME}.h")

install(TARGETS laslib-wrapper
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
  )
