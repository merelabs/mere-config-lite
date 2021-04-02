QT += testlib
QT -= gui

CONFIG += qt console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  testgroupparser.cpp \
    testdotparser.cpp \
    testiniparser.cpp \
    testkvparser.cpp \
    testparser.cpp

INCLUDEPATH += /usr/local/include
LIBS += -lmere-config-lite
