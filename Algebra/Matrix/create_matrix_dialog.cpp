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

#include "create_matrix_dialog.h"
#include "ui_create_matrix_dialog.h"

#include "matrix_interface.h"

#include <QDebug>

CreateMatrixDialog::CreateMatrixDialog(MatrixInterface *matrix, QWidget *parent) : QDialog(parent),
                                                                                   ui(new Ui::CreateMatrixDialog) {
  ui->setupUi(this);

  if (matrix == nullptr) {
    qWarning() << "matriz nula";
    return;
  }

  matrix_ = matrix;

  ui->tableWidget->setRowCount(matrix->rows());
  ui->tableWidget->setColumnCount(matrix->cols());

  for (int i = 0; i < matrix->rows(); i++) {
    for (int j = 0; j < matrix->cols(); j++) {
      QTableWidgetItem *item = new QTableWidgetItem(i == j ? "1" : "0");
      ui->tableWidget->setItem(i, j, item);
    }
  }
}

CreateMatrixDialog::~CreateMatrixDialog() {
    delete ui;
}

QTableWidget *CreateMatrixDialog::table()
{
    return ui->tableWidget;
}
