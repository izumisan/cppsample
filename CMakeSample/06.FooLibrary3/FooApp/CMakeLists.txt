cmake_minimum_required( VERSION 3.12 )

project( FooApp CXX )

# CMakeListsで管理されている他プロジェクトライブラリを利用する場合
# add_subdirectory()でビルドディレクトリを指定する必要がある
#
# この例の場合
# FooAppのビルドディレクトリ下にFooディレクトリを生成し、
# そのディレクトリでFooライブラリをビルドする
# (FooAppのビルドディレクトリと異なるディレクトリでFooをビルドする)
add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/../Foo Foo )

add_executable( FppApp src/main.cpp )

target_link_libraries( FppApp Foo )
