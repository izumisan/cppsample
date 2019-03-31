QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

SOURCES += tst_jsonformoderncppsample2.cpp

msvc: include(../msvc.pri)
include(../jsonformoderncpp/jsonformoderncpp.pri)
include(../messagepack/messagepack.pri)
