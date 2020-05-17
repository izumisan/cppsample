# Foo/src/CMakeLists.txt

set( INCLUDEPATH
        ${INCLUDEPATH}
        ${CMAKE_CURRENT_SOURCE_DIR} 
        PARENT_SCOPE )

set( HEADERS 
        ${HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/foo.h 
        PARENT_SCOPE )

set( SOURCES 
        ${SOURCES} 
        ${CMAKE_CURRENT_SOURCE_DIR}/foo.cpp 
        PARENT_SCOPE )
