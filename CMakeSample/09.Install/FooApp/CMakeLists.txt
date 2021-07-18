cmake_minimum_required(VERSION 3.13)
project(FooApp VERSION 0.1.0)

# include(CTest)
# enable_testing()

add_executable(${PROJECT_NAME} main.cpp)
include(${CMAKE_CURRENT_SOURCE_DIR}/../foo/foo/foo.cmake)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
