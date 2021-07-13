# foo
#
# qmake使用時と同様の感覚でcmakeファイルを構成してみたサンプル (libプロジェクト側)
# - foo.pro -> CMakeLists.txt
# - src/src.pri -> src/src.cmake
#
cmake_minimum_required(VERSION 3.0.0)
project(foo VERSION 0.1.0)

set(CMAKE_CXX_EXTENSIONS OFF)

include(src/src.cmake)

add_library( ${CMAKE_PROJECT_NAME}
    STATIC
    ${FOO_HEADERS}
    ${FOO_SOURCES} 
    )

target_compile_features( ${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17 )

message("FOO_INCLUDEPATH: ${FOO_INCLUDEPATH}")
message("FOO_HEADERS: ${FOO_HEADERS}")
message("FOO_SOURCES: ${FOO_SOURCES}")

install( TARGETS ${CMAKE_PROJECT_NAME} 
    ARCHIVE DESTINATION lib/debug 
    CONFIGURATIONS debug )
install( TARGETS ${CMAKE_PROJECT_NAME} 
    ARCHIVE DESTINATION lib/release 
    CONFIGURATIONS release )

# ファイル単位でコピーする場合
# install( FILES src/foo.h DESTINATION include )

# ディレクトリ単位でコピーする場合
# 「src/」と指定した場合、srcディレクトリの"中身"がincludeディレクトリ下にコピーされる
# install( DIRECTORY src/ DESTINATION include )

# 「src」と'/'なしで指定した場合、srcディレクトリ"自体"がincludeディレクトリ下にコピーされる
# install( DIRECTORY src DESTINATION include )

# "FILES_MATCHING"でフィルタリング可能
install( DIRECTORY src/ DESTINATION include
    FILES_MATCHING PATTERN "*.h" )
