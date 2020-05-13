cmake_minimum_required(VERSION 3.12)

project( HellowWorld3 CXX )

# add_subdirectory()で
# 指定したサブディレクトリのCMakeLists.txtを読み込む
add_subdirectory( foo )

set( SOURCES 
        ${SOURCES}
        main.cpp )

# project()で設定したプロジェクト名は PROJECT_NAME に設定されている
message( "PROJECT_NAME: ${PROJECT_NAME}" )

message( "INCLUDEPATH: ${INCLUDEPATH}" )
message( "HEADERS: ${HEADERS}" )
message( "SOURCES: ${SOURCES}" )

# include_directories()でインクルードパスを指定する
include_directories( ${INCLUDEPATH} )

add_executable( ${PROJECT_NAME} ${HEADERS} ${SOURCES} )
