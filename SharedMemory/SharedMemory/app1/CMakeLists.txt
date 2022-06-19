cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_EXTENSIONS OFF)

project(app1 LANGUAGES CXX)
add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} shmlib)

target_sources(
    ${PROJECT_NAME}
    PUBLIC
        main.cpp
    )
