QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SRCDIR = $${PWD}/src/
INCLUDEPATH += $${SRCDIR}
HEADERS += $${SRCDIR}/*.h
SOURCES += $${SRCDIR}/*.cpp

SOURCES +=  tst_singletontemplatetest.cpp
