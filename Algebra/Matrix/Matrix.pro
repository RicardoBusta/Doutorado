#---------------------------------------------------------------------------#
#  Copyright (C) 2015  Ricardo Bustamante de Queiroz (ricardo@busta.com.br) #
#                                                                           #
#  This program is free software: you can redistribute it and/or modify     #
#  it under the terms of the GNU General Public License as published by     #
#  the Free Software Foundation, either version 3 of the License, or        #
#  (at your option) any later version.                                      #
#                                                                           #
#  This program is distributed in the hope that it will be useful,          #
#  but WITHOUT ANY WARRANTY; without even the implied warranty of           #
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
#  GNU General Public License for more details.                             #
#                                                                           #
#  You should have received a copy of the GNU General Public License        #
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.    #
#---------------------------------------------------------------------------#

lessThan(QT_MAJOR_VERSION,5){
  error(Must have at least Qt 5)
}

QT += core gui widgets

TARGET = Matrix
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp \
    matrix_interface.cpp \
    matrix.cpp \
    mainwindow.cpp \
    matrix_widget.cpp \
    matrix_size.cpp \
    create_matrix_dialog.cpp

HEADERS += \
    matrix_interface.h \
    matrix.h \
    mainwindow.h \
    matrix_widget.h \
    matrix_size.h \
    create_matrix_dialog.h

FORMS += \
    mainwindow.ui \
    matrix_widget.ui \
    create_matrix_dialog.ui

