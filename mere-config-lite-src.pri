SOURCES += \
    $$PWD/src/parser/commentconfig.cpp \
    $$PWD/src/parser/config.cpp \
    $$PWD/src/parser/configex.cpp \
    $$PWD/src/parser/documentconfig.cpp \
    $$PWD/src/parser/documentparser.cpp \
    $$PWD/src/parser/dotconfig.cpp \
    $$PWD/src/parser/dotparser.cpp \
    $$PWD/src/parser/groupconfig.cpp \
    $$PWD/src/parser/groupparser.cpp \
    $$PWD/src/parser/iniparser.cpp \
    $$PWD/src/parser/keyconfig.cpp \
    $$PWD/src/parser/kvparser.cpp \
    $$PWD/src/parser/parser.cpp \
    $$PWD/src/parser/propertyconfig.cpp \
    $$PWD/src/parser/propertyparser.cpp \
    $$PWD/src/parser/valueconfig.cpp \
    $$PWD/src/builder.cpp \
    $$PWD/src/config.cpp \
    $$PWD/src/crossconfig.cpp \
    $$PWD/src/document.cpp \
    $$PWD/src/dotconfig.cpp \
    $$PWD/src/exception.cpp \
    $$PWD/src/group.cpp \
    $$PWD/src/groupconfig.cpp \
    $$PWD/src/homespec.cpp \
    $$PWD/src/iniconfig.cpp \
    $$PWD/src/key.cpp \
    $$PWD/src/kvconfig.cpp \
    $$PWD/src/pathresolver.cpp \
    $$PWD/src/property.cpp \
    $$PWD/src/propertyconfig.cpp \
    $$PWD/src/rootgroup.cpp \
    $$PWD/src/value.cpp

HEADERS += \
    $$PWD/src/parser/commentconfig.h \
    $$PWD/src/parser/config.h \
    $$PWD/src/parser/documentconfig.h \
    $$PWD/src/parser/documentparser.h \
    $$PWD/src/parser/dotconfig.h \
    $$PWD/src/parser/dotparser.h \
    $$PWD/src/parser/exconfig.h \
    $$PWD/src/parser/groupconfig.h \
    $$PWD/src/parser/groupparser.h \
    $$PWD/src/parser/iniparser.h \
    $$PWD/src/parser/keyconfig.h \
    $$PWD/src/parser/kvparser.h \
    $$PWD/src/parser/parser.h \
    $$PWD/src/parser/propertyconfig.h \
    $$PWD/src/parser/propertyparser.h \
    $$PWD/src/parser/valueconfig.h \
    $$PWD/src/builder.h \
    $$PWD/src/config.h \
    $$PWD/src/crossconfig.h \
    $$PWD/src/document.h \
    $$PWD/src/dotconfig.h \
    $$PWD/src/exception.h \
    $$PWD/src/global.h \
    $$PWD/src/group.h \
    $$PWD/src/groupconfig.h \
    $$PWD/src/homespec.h \
    $$PWD/src/iniconfig.h \
    $$PWD/src/key.h \
    $$PWD/src/kvconfig.h \
    $$PWD/src/pathresolver.h \
    $$PWD/src/property.h \
    $$PWD/src/propertyconfig.h \
    $$PWD/src/rootgroup.h \
    $$PWD/src/value.h

INCLUDEPATH += /usr/local/include

LIBS += -lmere-utils
