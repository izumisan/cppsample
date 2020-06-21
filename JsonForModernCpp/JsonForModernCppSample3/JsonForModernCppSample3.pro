QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../msvc.pri)
include(../jsonformoderncpp/jsonformoderncpp.pri)

HEADERS += *.h
SOURCES +=  tst_jsonformoderncppsample3.cpp
