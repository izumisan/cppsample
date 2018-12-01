TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

msvc: QMAKE_CXXFLAGS += /source-charset:utf-8

HEADERS += \
    foo.h

SOURCES += \
    main.cpp \
    foo.cpp
