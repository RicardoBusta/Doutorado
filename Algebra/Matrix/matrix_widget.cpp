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

#include "matrix_widget.h"
#include "ui_matrix_widget.h"

MatrixWidget::MatrixWidget(const QString &name, const MatrixSize &matrix_size, QWidget *parent) : QWidget(parent),
                                                                                                  ui(new Ui::MatrixWidget),
                                                                                                  name_(name) {
  ui->setupUi(this);

  ui->name_label->setText(name);
  ui->size_label->setText(QString("%1x%2").arg(matrix_size.rows()).arg(matrix_size.cols()));
  ui->other_label->setText("full");
}

MatrixWidget::~MatrixWidget() {
  delete ui;
}

QString MatrixWidget::name() const {
  return name_;
}
