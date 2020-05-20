cmake_minimum_required(VERSION 3.12)

project( Foo CXX )

add_subdirectory( src )

add_library( ${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES} )

# ライブラリ出力先
set( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/ )

# "PUBLIC"とすることで、
# ターゲット(Fooライブラリ)とFooライブラリを利用する側に対し、インクルードディレクトリを指定する.
# (Fooライブラリ利用側でインクルードディレクトリをする必要はない)
# - PRIVATEを指定すると、Fooライブラリのみ指定
# - INTERFACEを指定すると、Fooライブラリには指定せず、Fooライブラリを利用する側に指定する
target_include_directories( Foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/ )
