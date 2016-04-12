QT += core
QT -= gui

TARGET = Matrix
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    create.cpp

HEADERS += \
    create.h \
    common.h

