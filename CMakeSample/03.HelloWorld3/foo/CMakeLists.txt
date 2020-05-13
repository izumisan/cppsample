# foo/CMakeLists.txt

# PARENT_SCOPE を指定することで、
# 親のCMakeListsから参照できるようになる（親スコープの変数に反映される）
# (PARENT_SCOPE を指定しない場合はローカルスコープになるので
#  親のCMakeListsの変数とは別スコープになる)

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
