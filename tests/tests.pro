QT += testlib
QT -= gui

CONFIG += qt console
CONFIG -= app_bundle
CONFIG += no_testcase_installs

TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/testgroupparser.cpp \
    src/testdotparser.cpp \
    src/testiniparser.cpp \
    src/testkvparser.cpp \
    src/testparser.cpp

HEADERS += \
    src/testdotparser.h \
    src/testgroupparser.h \
    src/testiniparser.h \
    src/testkvparser.h \
    src/testparser.h

INCLUDEPATH += /usr/local/include
LIBS += -lmere-config-lite

