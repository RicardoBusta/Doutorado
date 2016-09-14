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
    octree/octree.cpp \
    object/object.cpp \
    scene.cpp \
    application.cpp \
    globaloptions.cpp \
    octree/octreenode.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    octree/octree.h \
    object/object.h \
    scene.h \
    application.h \
    globaloptions.h \
    octree/octreenode.h

FORMS    += mainwindow.ui

LIBS += -lopengl32
