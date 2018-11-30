TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += msvc

msvc {
    QMAKE_CXXFLAGS += /source-charset:utf-8
}

HEADERS += *.h
SOURCES += *.cpp
