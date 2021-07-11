# src
target_include_directories( ${CMAKE_PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
target_sources( ${CMAKE_PROJECT_NAME}
    PRIVATE
        foo.h foo.cpp
    )
# Note:
# file(GLOB)を使用すると、ファイル追加時にVisualStudioからプロジェクト更新できない
# (ZERO_CHECKをビルドしても反映されない)ので、file(GLOB)の使用は非推奨と言われている
# - file(GLOB)+VisualStudioの場合、ファイル追加・削除・リネーム時にコマンドラインから
#   cmake configureする必要がある
# - QtCreator使用時は、特に問題なく動作している(ファイル追加・削除時に自動で反映される)
#
# file(GLOB HEADERS "*.h")
# file(GLOB SOURCES "*.cpp")
# target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${HEADERS} ${SOURCES})
