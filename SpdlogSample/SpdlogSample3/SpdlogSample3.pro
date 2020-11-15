QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

include(../spdlog-1.8.1/spdlog.pri)

SOURCES +=  tst_spdlogsampl3.cpp
