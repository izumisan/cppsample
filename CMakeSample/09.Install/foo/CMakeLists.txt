cmake_minimum_required(VERSION 3.13)
project(foo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME} STATIC)
include(foo/foo.cmake)

target_compile_features( ${PROJECT_NAME} PRIVATE cxx_std_17 )
