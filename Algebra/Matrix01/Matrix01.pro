#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T12:42:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Matrix01
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    performance_tab.cpp \
    gauss_tab.cpp \
    lu_tab.cpp \
    cholesky_tab.cpp \
    block_tab.cpp \
    corefunctions.cpp

HEADERS  += mainwindow.h \
    performance_tab.h \
    gauss_tab.h \
    lu_tab.h \
    cholesky_tab.h \
    block_tab.h \
    corefunctions.h

FORMS    += mainwindow.ui \
    performance_tab.ui \
    gauss_tab.ui \
    lu_tab.ui \
    cholesky_tab.ui \
    block_tab.ui
