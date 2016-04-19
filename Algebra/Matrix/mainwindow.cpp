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
#include "create_matrix_dialog.h"

#include <QDebug>
#include <QMessageBox>

static int matrix_index = 0;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->generate_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateMatrix()));
  connect(ui->exec_gauss_pushButton, SIGNAL(clicked(bool)), this, SLOT(GaussExecute()));
  connect(ui->op_exec_pushButton, SIGNAL(clicked(bool)), this, SLOT(OpsExecute()));
  connect(ui->matrix_listWidget, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), this, SLOT(SelectMatrix(QListWidgetItem *, QListWidgetItem *)));
  connect(ui->gen_spec_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateSpecificMatrix()));
  ui->tabWidget->setCurrentWidget(ui->generate_tab);

  showMaximized();
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

void MainWindow::GenerateSpecificMatrix() {
  QString name = MatrixNameFromInt(matrix_index++);
  MatrixSize matrix_size(ui->row_spinBox->value(), ui->col_spinBox->value());
  Matrix *m = new Matrix(matrix_size);

  CreateMatrixDialog dialog(m, this);
  dialog.exec();

  if (dialog.result() == QDialog::Accepted) {
    QTableWidget *table = dialog.table();
    for (int i = 0; i < matrix_size.rows(); i++) {
      for (int j = 0; j < matrix_size.cols(); j++) {
        bool ok;
        double val = table->item(i, j)->text().toDouble(&ok);
        if (!ok) {
          ShowErrorMessage("O valor é inválido!");
          delete m;
          return;
        }
        m->setData(i, j, val);
      }
    }

    matrix_map_.insert(name, m);

    AddMatrix(name, m);
  } else {
    delete m;
  }
}

MatrixWidget *MainWindow::AddMatrix(const QString &name, MatrixInterface *matrix) {
  if (matrix == nullptr) {
    ShowErrorMessage("A matriz a ser adicionada na lista veio nula!");
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
    ShowErrorMessage("Essa matriz não existe!");
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
  ui->ops_1_comboBox->addItems(matrix_map_.keys());
  ui->ops_2_comboBox->clear();
  ui->ops_2_comboBox->addItems(matrix_map_.keys());
  ui->gauss_op1_comboBox->clear();
  ui->gauss_op1_comboBox->addItems(matrix_map_.keys());
  ui->gauss_op2_comboBox->clear();
  ui->gauss_op2_comboBox->addItems(matrix_map_.keys());
}

void MainWindow::SelectMatrix(QListWidgetItem *to, QListWidgetItem *from) {
  MatrixWidget *widget = dynamic_cast<MatrixWidget *>(ui->matrix_listWidget->itemWidget(to));
  if (widget != nullptr) {
    ShowMatrix(widget->name());
  }
}

void MainWindow::OpsExecute() {
  QString op1_name = ui->ops_1_comboBox->currentText();
  QString op2_name = ui->ops_2_comboBox->currentText();

  if (!(matrix_map_.contains(op1_name) && matrix_map_.contains(op2_name))) {
    ShowErrorMessage("Escolha uma matriz existente");
  }

  if (ui->op_comboBox->currentIndex() == 0) {
    MatrixInterface *res = matrix_map_[op1_name]->Multiply(matrix_map_[op2_name]);

    if (res == nullptr) {
      ShowErrorMessage(matrix_map_[op1_name]->error_message());
      return;
    }
    AddMatrix(QString("(%1x%2)").arg(op1_name).arg(op2_name), res);
  } else {
    MatrixInterface *res = matrix_map_[op1_name]->Add(matrix_map_[op2_name]);
    if (res == nullptr) {
      ShowErrorMessage(matrix_map_[op1_name]->error_message());
      return;
    }
    AddMatrix(QString("(%1+%2)").arg(op1_name).arg(op2_name), res);
  }
}

void MainWindow::GaussExecute() {
  QString op_name = ui->gauss_op1_comboBox->currentText();

  if (!matrix_map_.contains(op_name)) {
    ShowErrorMessage("Selecione uma matriz existente para a execução.");
    return;
  }
  MatrixInterface *result = matrix_map_[op_name]->GaussianElimination(ui->gauss_horz_checkBox->isChecked(), ui->gauss_vert_checkBox->isChecked());

  if (result == nullptr) {
      ShowErrorMessage(matrix_map_[op_name]->error_message());
      return;
  }

  QString result_name = QString("Gauss(%1)").arg(op_name);

  AddMatrix(result_name, result);
}

void MainWindow::ShowErrorMessage(QString error) {
  QMessageBox message;
  message.setText(error);
  message.exec();
}
