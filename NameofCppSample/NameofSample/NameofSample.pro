QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

CONFIG += c++17
QMAKE_CXXFLAGS += /source-charset:utf-8

NAMEOF_DIR = $${PWD}/../nameof-0.9.4/
INCLUDEPATH += $${NAMEOF_DIR}/include/
HEADERS += $${NAMEOF_DIR}/include/nameof.hpp
HEADERS += month.h
SOURCES +=  tst_nameofsample.cpp
