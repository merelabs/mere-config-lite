QT += testlib
QT -= gui

CONFIG += qt console
CONFIG -= app_bundle
CONFIG += no_testcase_installs
CONFIG += object_parallel_to_source

TEMPLATE = app

SOURCES += \
    src/testgkparser.cpp \
    src/testdotparser.cpp \
    src/testiniconfig.cpp \
    src/main.cpp \
    src/testkvconfig.cpp \
    src/testiniparser.cpp \
    src/testgroupparser.cpp \
    src/testkvparser.cpp \
    src/testparser.cpp

HEADERS += \
    src/testgkparser.h \
    src/testdotparser.h \
    src/testiniconfig.h \
    src/testkvconfig.h \
    src/testiniparser.h \
    src/testgroupparser.h \
    src/testkvparser.h \
    src/testparser.h

include(../mere-config-lite-src.pri)

INCLUDEPATH += /usr/local/include

