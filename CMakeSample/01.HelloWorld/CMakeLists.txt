# CMakeのバージョンを設定する
cmake_minimum_required(VERSION 3.12)

# プロジェクト名と使用するプログラム言語を設定する
# (ここで指定したプロジェクト名は、VisualStudioのソリューション名となる)
project(HelloWorld, CXX)

# 実行ファイル名とソースファイルを指定する
add_executable(HelloWorld main.cpp)
