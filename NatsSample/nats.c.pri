# nats.c.pri

NATS_TOP = $${PWD}/nats.c-2.2.0/

NATS_INCLUDE_DIR = $${NATS_TOP}/src/
NATS_DEBUG_LIB_DIR = $${NATS_TOP}/build/src/Debug/
NATS_RELEASE_LIB_DIR = $${NATS_TOP}/build/src/Release/

INCLUDEPATH += $${NATS_INCLUDE_DIR}
HEADERS += $${NATS_INCLUDE_DIR}/*.h

CONFIG(debug, debug|release){
    LIBS += -L$${NATS_DEBUG_LIB_DIR}
    LIBS += -lnats_staticd
} else {
    LIBS += -L$${NATS_RELEASE_LIB_DIR}
    LIBS += -lnats_static
}
