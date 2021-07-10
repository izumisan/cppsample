# src.cmake

set( FOO_INCLUDEPATH
        ${FOO_INCLUDEPATH}
        ${CMAKE_CURRENT_LIST_DIR} 
        )
set( FOO_HEADERS 
        ${FOO_HEADERS}
        ${CMAKE_CURRENT_LIST_DIR}/foo.h 
        )
set( FOO_SOURCES
        ${FOO_SOURCES}
        ${CMAKE_CURRENT_LIST_DIR}/foo.cpp 
        )
