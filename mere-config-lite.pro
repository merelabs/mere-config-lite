QT      = core

CONFIG += c++11
CONFIG += shared

TARGET = mere-config-lite
VERSION= 0.0.1
TEMPLATE = lib

DEFINES += LIB_CODE=\\\"config-lite\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS MERE_CONFIG_LITE_LIB

SOURCES += \
    src/config.cpp \
    src/pathresolver.cpp

HEADERS += \
    src/config.h \
    src/pathresolver.h \
    src/global.h

INCLUDEPATH += /usr/local/include

#LIBS += -lmere-utils

#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/config-lite
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}
