# foo
cmake_minimum_required(VERSION 3.13)
project(foo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF) # CMAKE_CXX_EXTENSIONS >= 3.1
# cmake_policy(SET CMP0076 NEW) # CMP0076 >= 3.13 なくてもよさそう...

add_library( ${CMAKE_PROJECT_NAME} )

# 以下はどちらでもOK
# (CMakeLists.txtとsrc.cmakeは微妙に記載内容を変える必要がある...?)
add_subdirectory( src )
# include(src/src.cmake)

target_compile_features( ${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17 )
