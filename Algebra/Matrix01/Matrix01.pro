#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T12:42:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Matrix01
TEMPLATE = app


SOURCES += \
    main.cpp\
    mainwindow.cpp \
    T1/performance_tab.cpp \
    T1/gauss_tab.cpp \
    T1/lu_tab.cpp \
    T1/cholesky_tab.cpp \
    T1/block_tab.cpp \
    corefunctions.cpp \
    structures/simplematrix.cpp \
    structures/blockmatrix.cpp \
    T2/qr_tab.cpp \
    T2/vector_norm_tab.cpp \
    T2/matrix_norm_tab.cpp

HEADERS  += \
    mainwindow.h \
    T1/performance_tab.h \
    T1/gauss_tab.h \
    T1/lu_tab.h \
    T1/cholesky_tab.h \
    T1/block_tab.h \
    corefunctions.h \
    structures/simplematrix.h \
    structures/blockmatrix.h \
    T2/qr_tab.h \
    T2/vector_norm_tab.h \
    T2/matrix_norm_tab.h

FORMS    += \
    mainwindow.ui \
    T1/performance_tab.ui \
    T1/gauss_tab.ui \
    T1/lu_tab.ui \
    T1/cholesky_tab.ui \
    T1/block_tab.ui \
    T2/qr_tab.ui \
    T2/vector_norm_tab.ui \
    T2/matrix_norm_tab.ui
