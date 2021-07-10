# src.cmake

include_directories( ${CMAKE_CURRENT_LIST_DIR} )

set( FOO_HEADERS 
        ${FOO_HEADERS}
        ${CMAKE_CURRENT_LIST_DIR}/foo.h 
        )
set( FOO_SOURCES
        ${FOO_SOURCES}
        ${CMAKE_CURRENT_LIST_DIR}/foo.cpp 
        )

# qmake(src.pri)の場合
#
# INCLUDEPATH += $${PWD}
# HEADERS += $${PWD}/foo.h
# SOURCES += $${PWD}/foo.cpp
