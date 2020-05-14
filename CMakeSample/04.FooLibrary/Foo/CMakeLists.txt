cmake_minimum_required(VERSION 3.12)

project( Foo CXX )

add_subdirectory( src )

# add_library()に"STATIC"を指定することで、スタティックライブラリとしてビルドする
# ("SHARED"を指定するとダイナミックライブラリとしてビルドされる)
add_library( ${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES} )

# ライブラリ出力先は、"LIBRARY_OUTPUT_PATH"にパスを設定することで指定できる
set( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/ )
