TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

include(../../nats.c.pri)

SOURCES += \
        main.cpp
