#-------------------------------------------------
#
# Project created by QtCreator 2016-08-24T08:29:07
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modelagem
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    octree/octree.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    octree/octree.h

FORMS    += mainwindow.ui

LIBS += -lopengl32
