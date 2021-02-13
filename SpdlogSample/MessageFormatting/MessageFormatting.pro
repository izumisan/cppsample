TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

include(../spdlog-1.8.1/spdlog.pri)
msvc: QMAKE_CXXFLAGS += /source-charset:utf-8

SOURCES += \
        main.cpp
