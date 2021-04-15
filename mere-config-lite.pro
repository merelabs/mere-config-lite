QT      = core

CONFIG += c++11
CONFIG += shared
CONFIG += object_parallel_to_source

TARGET = mere-config-lite
VERSION= 0.0.1
TEMPLATE = lib

DEFINES += LIB_CODE=\\\"config-lite\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS MERE_CONFIG_LITE_LIB

#SOURCES += \
#    src/parser/config.cpp \
#    src/parser/groupconfig.cpp \
#    src/parser/groupparser.cpp \
#    src/parser/iniparser.cpp \
#    src/parser/kvparser.cpp \
#    src/parser/parser.cpp \
#    src/parser/propertyconfig.cpp \
#    src/parser/propertyparser.cpp \
#    src/parser/dotparser.cpp \
#    src/builder.cpp \
#    src/config.cpp \
#    src/configtraverser.cpp \
#    src/dotconfig.cpp \
#    src/exception.cpp \
#    src/group.cpp \
#    src/groupconfig.cpp \
#    src/homespec.cpp \
#    src/iniconfig.cpp \
#    src/key.cpp \
#    src/kvconfig.cpp \
#    src/pathresolver.cpp \
#    src/property.cpp \
#    src/propertyconfig.cpp \
#    src/reader.cpp \
#    src/traverser.cpp \
#    src/value.cpp \
#    src/writer.cpp

#HEADERS += \
#    src/parser/config.h \
#    src/parser/dotparser.h \
#    src/parser/groupconfig.h \
#    src/parser/groupparser.h \
#    src/parser/iniparser.h \
#    src/parser/kvparser.h \
#    src/parser/parser.h \
#    src/parser/propertyconfig.h \
#    src/parser/propertyparser.h \
#    src/builder.h \
#    src/config.h \
#    src/configtraverser.h \
#    src/dotconfig.h \
#    src/exception.h \
#    src/group.h \
#    src/groupconfig.h \
#    src/homespec.h \
#    src/iniconfig.h \
#    src/key.h \
#    src/kvconfig.h \
#    src/pathresolver.h \
#    src/global.h \
#    src/property.h \
#    src/propertyconfig.h \
#    src/reader.h \
#    src/traverser.h \
#    src/value.h \
#    src/writer.h

INCLUDEPATH += /usr/local/include


LIBS += -lmere-utils

include(mere-config-lite-src.pri)

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
