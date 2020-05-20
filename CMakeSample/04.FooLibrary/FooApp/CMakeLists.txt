cmake_minimum_required( VERSION 3.12 )

project( FooApp CXX )

# ライブラリパスを設定する
# - ターゲット指定(今回はadd_executable())より前に指定しないと有効にならない
# - 逆にいうと、これ以降に作成されたターゲットに対して適用される
link_directories( ${PROJECT_SOURCE_DIR}/../Foo/lib/Debug/ )

add_executable( FppApp src/main.cpp )

# インクルードパス
include_directories( ${PROJECT_SOURCE_DIR}/../Foo/src/ )

# リンクするライブラリを指定する
target_link_libraries( FppApp Foo )
