QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

FOO_DIR = $${PWD}/foo
INCLUDEPATH += $${FOO_DIR}
HEADERS += $${FOO_DIR}/*.h
SOURCES += $${FOO_DIR}/*.cpp

SOURCES +=  tst_singletonclasstest.cpp
