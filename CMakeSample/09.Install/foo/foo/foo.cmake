# foo.cmake
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

# IDE(VisualStudio等)用フィルタ設定
# 下記はどちらも有効
source_group("foo" FILES ${HEADERS} ${SOURCES})
# source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/../ FILES ${HEADERS} ${SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/bar/bar.cmake)
