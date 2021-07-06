cmake_minimum_required(VERSION 3.13)

project(FileGlob CXX)
add_executable(${PROJECT_NAME})

# file(GLOB)でソースファイルを探索し、変数"MYSOURCES"にセットする
# - IDE（VisualStudio等）によっては、上手く動作しないので、
#   横着せずに全てのファイルを記述する方を推奨している記事がある
#   - ソースファイルを追加してもCMakeCacheが更新されるわけではないので、
#     configure(?)を実行する必要がある
# - IDEからではなく、cmakeのコマンドラインから実行する場合には問題ないので、
#   file(GLOB)の使用を制限する必要はないように思うが...
file(GLOB MYSOURCES "*.cpp")
message(${MYSOURCES})

target_sources(${PROJECT_NAME} PRIVATE ${MYSOURCES})
