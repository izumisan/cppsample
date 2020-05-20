cmake_minimum_required(VERSION 3.12)

project(HelloWorld2, CXX)

# ソースファイルが複数ある場合は、
# add_executableにソースファイルを全て指定する
add_executable(
    HelloWorld2 
    main.cpp 
    foo.cpp
    )

# 上記の場合、VisualStudioのプロジェクトにヘッダーファイルは追加されない
# VisualStudioプロジェクトにヘッダーファイルを追加する場合は、
# add_executableにヘッダーファイルを追加すればよい
#add_executable(
#    HelloWorld2 
#    main.cpp 
#    foo.h
#    foo.cpp
#    )