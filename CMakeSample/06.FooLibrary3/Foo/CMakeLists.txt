cmake_minimum_required(VERSION 3.12)

project( Foo CXX )

add_subdirectory( src )

add_library( ${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES} )

# ライブラリ出力先
set( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/ )

target_include_directories( Foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/ )
