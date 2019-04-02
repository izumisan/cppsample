QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += *.pb.h
SOURCES += *.pb.cc
SOURCES +=  tst_protobuftest.cpp
OTHER_FILES += *.proto

include(../protobuf.pri)
