GoogleTestTop = $${PWD}/googletest-release-1.8.0/googletest/

INCLUDEPATH += \
    $${GoogleTestTop} \
    $${GoogleTestTop}/include/

SOURCES += $${GoogleTestTop}/src/gtest-all.cc
SOURCES += $${GoogleTestTop}/src/gtest_main.cc
