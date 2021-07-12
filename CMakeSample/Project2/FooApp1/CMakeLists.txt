# FooApp1
cmake_minimum_required(VERSION 3.13)
project(FooApp1 VERSION 0.1.0)

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# Note:
# `add_subdirectory()`では、サブディレクトリしか指定できない.
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../foo/src)
include(../foo/src/src.cmake)

target_compile_features( ${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17 )
