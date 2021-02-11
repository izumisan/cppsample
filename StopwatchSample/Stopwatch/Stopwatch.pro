TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt

SRCDIR = $${PWD}/src
INCLUDEPATH += $${SRCDIR}
HEADERS += $${SRCDIR}/*.h
SOURCES += $${SRCDIR}/*.cpp
