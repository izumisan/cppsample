cmake_minimum_required( VERSION 3.12 )

project( FooApp CXX )

add_executable( FppApp src/main.cpp )

# リンクするライブラリを指定する
target_link_libraries( FppApp Foo )
