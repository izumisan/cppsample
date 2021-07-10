# FooApp1
#
# qmake使用時と同様の感覚でcmakeファイルを構成してみたサンプル (appプロジェクト側)
#
# ディレクトリ単位で作成するpriファイルをincludeするように、
# ディレクトリ単位で作成したcmakeファイルをincludeしてみた.
#
cmake_minimum_required(VERSION 3.0.0)
project(FooApp1 VERSION 0.1.0)

set(CMAKE_CXX_EXTENSIONS OFF)

# qmake(FooApp1.pro)の場合
# include(../foo/src/src.pri)
include(../foo/src/src.cmake)

add_executable(FooApp1 
    main.cpp
    ${FOO_HEADERS}
    ${FOO_SOURCES}
    )

target_compile_features( ${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17 )
