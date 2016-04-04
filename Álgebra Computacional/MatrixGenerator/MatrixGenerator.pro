QT += core
QT -= gui

TARGET = MatrixGenerator
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    create.cpp

HEADERS += \
    create.h \
    common.h

