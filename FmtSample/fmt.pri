# {fmt}
# https://github.com/fmtlib/fmt

# ヘッダーオンリーでは使用できず、format.ccをプロジェクトに含める必要がある

FMTDIR = $${PWD}/fmt-7.1.3/
INCLUDEPATH += $${FMTDIR}/include
HEADERS += $${FMTDIR}/include/fmt/*.h
SOURCES += $${FMTDIR}/src/format.cc
