# CMakeLists.txt
cmake_minimum_required(VERSION 3.13)
project(FooApps)

set(CMAKE_INSTALL_PREFIX "install")  # install path prefix 指定がメンドウなので...

add_subdirectory(foo)
add_subdirectory(FooApp)

# foo.lib
install(TARGETS foo 
    ARCHIVE DESTINATION "lib/debug"
    CONFIGURATIONS debug)
install(TARGETS foo 
    ARCHIVE DESTINATION "lib/release"
    CONFIGURATIONS release)
install(DIRECTORY "foo/foo/" DESTINATION "include"
    FILES_MATCHING PATTERN "*.h" )
install(FILES "foo/README.md" DESTINATION ".")

# FooApp.exe
install(TARGETS FooApp
    RUNTIME DESTINATION "bin/debug"
    CONFIGURATIONS debug)
install(TARGETS FooApp
    RUNTIME DESTINATION "bin/release"
    CONFIGURATIONS release)
