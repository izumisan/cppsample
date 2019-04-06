QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

SOURCES += tst_inlinevariabletest.cpp \
    foo.cpp \
    bar.cpp

HEADERS += \
    inline_variable.h \
    foo.h \
    bar.h
