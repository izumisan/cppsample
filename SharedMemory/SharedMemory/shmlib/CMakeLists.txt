cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_EXTENSIONS OFF)
cmake_policy(SET CMP0076 NEW)

project(shmlib LANGUAGES CXX)
add_library(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

file(GLOB ${PROJECT_NAME}_HEADERS shm/*.h)
file(GLOB ${PROJECT_NAME}_SOURCES shm/*.cpp)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        shm
    )

target_sources(
    ${PROJECT_NAME}
    PUBLIC
        ${${PROJECT_NAME}_HEADERS}
    PRIVATE
        ${${PROJECT_NAME}_SOURCES}
    )
