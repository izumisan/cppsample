# src.cmake
target_include_directories( ${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )

file(GLOB HEADERS "${CMAKE_CURRENT_LIST_DIR}/*.h")
file(GLOB SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

target_sources( ${PROJECT_NAME}
    PRIVATE
        ${HEADERS}
        ${SOURCES}
    )

source_group("foo/bar" FILES ${HEADERS} ${SOURCES})