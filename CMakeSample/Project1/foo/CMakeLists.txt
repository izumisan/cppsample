cmake_minimum_required(VERSION 3.0.0)
project(foo VERSION 0.1.0)

set(CMAKE_CXX_EXTENSIONS OFF)

include(src/src.cmake)

include_directories( ${FOO_INCLUDEPATH} )

add_library( ${CMAKE_PROJECT_NAME}
    STATIC
    ${FOO_HEADERS}
    ${FOO_SOURCES} 
    )

target_compile_features( ${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17 )

message("FOO_INCLUDEPATH: ${FOO_INCLUDEPATH}")
message("FOO_HEADERS: ${FOO_HEADERS}")
message("FOO_SOURCES: ${FOO_SOURCES}")
