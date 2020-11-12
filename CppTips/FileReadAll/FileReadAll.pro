QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += /source-charset:utf-8

SOURCES +=  tst_filereadall.cpp

OTHER_FILES += foo.json
