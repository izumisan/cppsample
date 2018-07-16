TEMPLATE = app
TARGET = GoogleTestSample2qt
CONFIG += console
CONFIG -= app_bundle

include(googletest/googletest.pri)

SOURCES += src/*.cpp
