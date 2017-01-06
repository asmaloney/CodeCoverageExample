QT += core testlib
QT -= gui

CONFIG += c++11

TARGET = CodeCoverageExample
CONFIG -= app_bundle

TEMPLATE = app

if ( !include( ./asmExample.pri ) ) {
    error( Could not find the asmExample.pri file. )
}

HEADERS += \
    test/asmTestSuite.h

SOURCES += \
    test/main.cpp \
    test/asmTestSuite.cpp \
    test/asmExampleClass_test.cpp

mac {
    # use code coverage on macOS
    QMAKE_CXXFLAGS += --coverage
    QMAKE_LFLAGS += --coverage
}
