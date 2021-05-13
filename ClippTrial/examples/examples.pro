QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../clipp-1.2.3/clipp.pri)

HEADERS += options.h
SOURCES += \
    options.cpp \
    tst_examples.cpp
