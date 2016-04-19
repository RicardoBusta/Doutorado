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

#ifndef CREATE_MATRIX_DIALOG_H
#define CREATE_MATRIX_DIALOG_H

#include <QDialog>

class MatrixInterface;

namespace Ui {
class CreateMatrixDialog;
}
class QTableWidget;

class CreateMatrixDialog : public QDialog {
  Q_OBJECT

 public:
  explicit CreateMatrixDialog(MatrixInterface *matrix, QWidget *parent = 0);
  ~CreateMatrixDialog();

 QTableWidget * table();

 private:
  Ui::CreateMatrixDialog *ui;

  MatrixInterface *matrix_;
};

#endif  // CREATE_MATRIX_DIALOG_H
