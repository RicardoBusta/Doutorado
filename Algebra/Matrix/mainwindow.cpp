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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "matrix_widget.h"
#include "matrix.h"

#include <QDebug>

static int matrix_index = 0;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->generate_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateMatrix()));
  connect(ui->exec_gauss_pushButton, SIGNAL(clicked(bool)), this, SLOT(GaussExecute()));
  connect(ui->op_exec_pushButton, SIGNAL(clicked(bool)), this, SLOT(OpsExecute()));
  connect(ui->matrix_listWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(SelectMatrix(QListWidgetItem *, QListWidgetItem *)));
  ui->tabWidget->setCurrentWidget(ui->generate_tab);
}

MainWindow::~MainWindow() {
  delete ui;
}

QString MatrixNameFromInt(int i) {
  QString out;
  int v = i;
  do {
    QChar c = (char)(v % 26 + (int)'A');
    out.push_front(c);
    v = v / 26;
  } while (float(v) / 26.0f > 0);
  return out;
}

void MainWindow::GenerateMatrix() {
  QString name = MatrixNameFromInt(matrix_index++);
  MatrixSize matrix_size(ui->row_spinBox->value(), ui->col_spinBox->value());
  Matrix *m = new Matrix(matrix_size);
  m->Randomize();
  matrix_map_.insert(name, m);

  AddMatrix(name, m);
}

MatrixWidget *MainWindow::AddMatrix(const QString &name, MatrixInterface *matrix) {
  if (matrix == nullptr) {
    qWarning() << "Tentando adicionar uma matriz nula";
    return nullptr;
  }
  QListWidgetItem *item = new QListWidgetItem;
  MatrixWidget *widget = new MatrixWidget(
      name,
      matrix->size());
  ui->matrix_listWidget->addItem(item);
  ui->matrix_listWidget->setItemWidget(item, widget);
  item->setSizeHint(widget->size());
  matrix_map_.insert(name, matrix);
  Refresh();
  ui->matrix_listWidget->setCurrentItem(item);
}

void MainWindow::ShowMatrix(QString matrix_name) {
  if (!matrix_map_.contains(matrix_name)) {
    qWarning() << "Não tem essa matriz";
    return;
  }

  MatrixInterface *matrix = matrix_map_[matrix_name];

  ui->tableWidget->setColumnCount(matrix->cols());
  ui->tableWidget->setRowCount(matrix->rows());

  for (int i = 0; i < matrix->rows(); i++) {
    for (int j = 0; j < matrix->cols(); j++) {
      QTableWidgetItem *item = new QTableWidgetItem(QString::number(matrix->data(i, j)));
      ui->tableWidget->setItem(i, j, item);
    }
  }
}

void MainWindow::Refresh() {
  ui->ops_1_comboBox->clear();
  ui->ops_2_comboBox->clear();
  ui->ops_1_comboBox->addItems(matrix_map_.keys());
  ui->ops_2_comboBox->addItems(matrix_map_.keys());
}

void MainWindow::SelectMatrix(QListWidgetItem *to, QListWidgetItem *from) {
  MatrixWidget *widget = dynamic_cast<MatrixWidget *>(ui->matrix_listWidget->itemWidget(to));
  if (widget != nullptr) {
    ShowMatrix(widget->name());
    qDebug() << "selecting matrix" << widget->name();
  }
}

void MainWindow::OpsExecute() {
  QString op1_name = ui->ops_1_comboBox->currentText();
  QString op2_name = ui->ops_2_comboBox->currentText();

  if (!(matrix_map_.contains(op1_name) && matrix_map_.contains(op2_name))) {
    qWarning() << "Escolha uma matriz existente";
  }

  if (ui->op_comboBox->currentIndex() == 0) {
    MatrixInterface *res = matrix_map_[op1_name]->Multiply(matrix_map_[op2_name]);
    AddMatrix(QString("(%1+%2)").arg(op1_name).arg(op2_name), res);
  } else {
    MatrixInterface *res = matrix_map_[op1_name]->Add(matrix_map_[op2_name]);
    AddMatrix(QString("(%1+%2)").arg(op1_name).arg(op2_name), res);
  }
}

void MainWindow::GaussExecute() {
  if (!matrix_map_.contains("A")) {
    qWarning() << "Selecione matriz existente";
    return;
  }
  MatrixInterface *result = matrix_map_["A"]->GaussianElimination(false, false);
  QString result_name = "Gauss(A)";

  AddMatrix(result_name, result);
}
