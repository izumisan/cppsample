# nats.c.pri

# https://github.com/nats-io/nats.c

NATS_LIB_DIR = $${PWD}/nats.c-2.2.0/install/

INCLUDEPATH += $${NATS_LIB_DIR}/include

CONFIG(debug, debug|release){
    LIBS += -L$${NATS_LIB_DIR}/lib/
    LIBS += -lnats_staticd
} else {
    LIBS += -L$${NATS_LIB_DIR}/lib/
    LIBS += -lnats_static
}
