cmake_minimum_required(VERSION 3.12)
project(Foo CXX)
add_executable(Foo main.cpp)

# ビルド後にfoo.txtを出力先にコピーする
add_custom_command(
    TARGET Foo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/foo.txt $<TARGET_FILE_DIR:Foo>
)
