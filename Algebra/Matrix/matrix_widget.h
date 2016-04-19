/*--------------------------------------------------------------------------#
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
#--------------------------------------------------------------------------*/

#ifndef MATRIX_WIDGET_H
#define MATRIX_WIDGET_H

#include <QWidget>
#include "matrix_size.h"

namespace Ui {
class MatrixWidget;
}

class MatrixWidget : public QWidget {
  Q_OBJECT

 public:
  explicit MatrixWidget(const QString &name, const MatrixSize &matrix_size, QWidget *parent = 0);
  explicit MatrixWidget(QWidget *parent = 0);
  ~MatrixWidget();

  QString name() const;

 private:
  Ui::MatrixWidget *ui;

  QString name_;
};

#endif  // MATRIX_WIDGET_H
