QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
include(../eigen.pri)

DEFINES += EIGEN_INITIALIZE_MATRICES_BY_ZERO

SOURCES +=  tst_initializemacrotest.cpp
