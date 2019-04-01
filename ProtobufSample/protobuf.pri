INCLUDEPATH += $${PWD}/protobuf-3.7.1/include

LIBS += -L$${PWD}/protobuf-3.7.1/lib
CONFIG( debug, debug|release ) {
    LIBS += -llibprotobufd
} else {
    LIBS += -llibprotobuf
}
