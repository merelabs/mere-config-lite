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
    src/dotconfig.cpp \
    src/dotparser.cpp \
    src/group.cpp \
    src/groupconfig.cpp \
    src/groupparser.cpp \
    src/homespec.cpp \
    src/iniconfig.cpp \
    src/iniparser.cpp \
    src/kvconfig.cpp \
    src/kvparser.cpp \
    src/parser.cpp \
    src/pathresolver.cpp \
    src/property.cpp \
    src/reader.cpp \
    src/traverser.cpp \
    src/writer.cpp

HEADERS += \
    src/config.h \
    src/dotconfig.h \
    src/dotparser.h \
    src/group.h \
    src/groupconfig.h \
    src/groupparser.h \
    src/homespec.h \
    src/iniconfig.h \
    src/iniparser.h \
    src/kvconfig.h \
    src/kvparser.h \
    src/parser.h \
    src/pathresolver.h \
    src/global.h \
    src/property.h \
    src/reader.h \
    src/traverser.h \
    src/writer.h

INCLUDEPATH += /usr/local/include


LIBS += -lmere-xdg -lmere-utils

#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/config
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}
