# foo
cmake_minimum_required(VERSION 3.13)
project(foo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF) # CMAKE_CXX_EXTENSIONS >= 3.1
cmake_policy(SET CMP0076 NEW) # CMP0076 >= 3.13

add_library( ${CMAKE_PROJECT_NAME} )
add_subdirectory( src )
# Note:
# include(src/src.cmake) で読み込んだcmakeファイル内で`target_sources()`でソースを指定していても
# `add_library()`でソースが指定されていないというエラーになる

target_compile_features( ${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17 )
