cmake_minimum_required(VERSION 3.12)

project(BuildOptions CXX)

# GNU拡張をOFFにする
# デフォルトではONになっているため、GNU拡張が有効になってしまっているため、常にOFF推奨
set(CMAKE_CXX_EXTENSIONS OFF)  

add_executable(${PROJECT_NAME} main.cpp)

# 警告レベル
target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
# CMAKE_CXX_FLAGSにコンパイルオプションを直接指定してもよい（現在は、target_compile_optionsの使用が推奨されている）
# set(CMAKE_CXX_FLAGS "-Wall")

# C++17を有効にする
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
# 下記のようにCMAKE_CXX_FLAGSにオプションを直接設定したり、
# CMAKE_CXX_STANDARDを使用することでも指定できる.
# set(CMAKE_CXX_FLAGS "-std=c++17")
# set(CMAKE_CXX_STANDARD 17)
# (現在は、target_compile_featuresの使用が推奨されている)

# マクロ定義
target_compile_definitions(${PROJECT_NAME} PUBLIC FOO_DEFINITION)
