SOURCES += \
    $$PWD/src/parser/crossparser.cpp \
    $$PWD/src/spec/base.cpp \
    $$PWD/src/spec/baseex.cpp \
    $$PWD/src/spec/comment.cpp \
    $$PWD/src/spec/document.cpp \
    $$PWD/src/spec/dotted.cpp \
    $$PWD/src/spec/group.cpp \
    $$PWD/src/parser/ckparser.cpp \
    $$PWD/src/parser/gkparser.cpp \
    $$PWD/src/parser/documentparser.cpp \
    $$PWD/src/parser/dotparser.cpp \
    $$PWD/src/parser/groupparser.cpp \
    $$PWD/src/parser/iniparser.cpp \
    $$PWD/src/parser/kvparser.cpp \
    $$PWD/src/parser/parser.cpp \
    $$PWD/src/parser/propertyparser.cpp \
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
    $$PWD/src/spec/key.cpp \
    $$PWD/src/spec/property.cpp \
    $$PWD/src/spec/value.cpp \
    $$PWD/src/value.cpp

HEADERS += \
    $$PWD/src/parser/crossparser.h \
    $$PWD/src/spec/baseex.h \
    $$PWD/src/spec/base.h \
    $$PWD/src/spec/document.h \
    $$PWD/src/spec/dotted.h \
    $$PWD/src/spec/key.h \
    $$PWD/src/spec/comment.h \
    $$PWD/src/spec/group.h \
    $$PWD/src/spec/property.h \
    $$PWD/src/spec/value.h \
    $$PWD/src/parser/ckparser.h \
    $$PWD/src/parser/gkparser.h \
    $$PWD/src/parser/documentconfig.h \
    $$PWD/src/parser/documentparser.h \
    $$PWD/src/parser/dotparser.h \
    $$PWD/src/parser/groupparser.h \
    $$PWD/src/parser/iniparser.h \
    $$PWD/src/parser/kvparser.h \
    $$PWD/src/parser/parser.h \
    $$PWD/src/parser/propertyparser.h \
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
