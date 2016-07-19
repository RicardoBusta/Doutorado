#include "gauss_tab.h"
#include "ui_gauss_tab.h"

#include "corefunctions.h"
#include "mainwindow.h"
#include "structures/simplematrix.h"
#include <QDebug>

GaussTab::GaussTab(MainWindow *w, QWidget *parent) : QWidget(parent),
                                                     ui(new Ui::GaussTab),
                                                     A1(nullptr), C1(nullptr),
                                                     A2(nullptr), C2(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
  QObject::connect(ui->eli_pushButton, SIGNAL(clicked(bool)), this, SLOT(EliminatePressed()));
  QObject::connect(ui->sol_pushButton, SIGNAL(clicked(bool)), this, SLOT(CalculatePressed()));
  QObject::connect(this, SIGNAL(Error(QString)), w, SLOT(ErrorMessage(QString)));

  ui->eli_pushButton->setEnabled(false);
  ui->sol_pushButton->setEnabled(false);
}

GaussTab::~GaussTab() {
  delete ui;
}

void GaussTab::GeneratePressed() {
  int m = ui->m_spinBox->value();

  SimpleMatrix::CreateMatrix(m, m, &A1);
  SimpleMatrix::CreateMatrix(m, 1, &C1);

  SimpleMatrix::CreateMatrix(m, m, &A2);
  SimpleMatrix::CreateMatrix(m, 1, &C2);

  A1->Randomize();
  C1->Randomize();

  ui->B1_tableWidget->clear();
  ui->B1_tableWidget->setRowCount(m);
  ui->B1_tableWidget->setColumnCount(1);
  keys.clear();
  for (int i = 0; i < m; i++) {
    QString key = "x" + QString::number(i);
    keys.push_back(key);
    ui->B1_tableWidget->setItem(i, 0, new QTableWidgetItem(key));
  }

  Core::SetMatrixToWidget(ui->A1_tableWidget, *A1);
  Core::SetMatrixToWidget(ui->C1_tableWidget, *C1);

  ui->eli_pushButton->setEnabled(true);
}

void GaussTab::EliminatePressed() {
  bool ok;
  Core::GetMatrixFromWidget(ui->A1_tableWidget, *A1, &ok);
  if (!ok) {
    emit Error("Algum valor inválido em A1.");
    return;
  }
  Core::GetMatrixFromWidget(ui->C1_tableWidget, *C1, &ok);
  if (!ok) {
    emit Error("Algum valor inválido em C1.");
    return;
  }

  double zeroPrecision = 0.00001;
  A2->Copy(A1);
  C2->Copy(C1);
  // Coluna atual
  for (int j = 0; j < A2->cols; j++) {
    // Linha que vai ser zerada
    for (int i = j + 1; i < A2->rows; i++) {
      // Elemento que será zerado dividido pelo pivot
      if (A2->data[i][j] == 0) {
        // Pivotação Vertical
        if (ui->vert_checkBox->isChecked()) {
          for (int k = i + 1; k < A2->rows; k++) {
          }
        }
        emit Error("O pivot deu zero!");
        return;
      }
      double alpha = A2->data[i][j] / A2->data[j][j];
      for (int k = j; k < A2->cols; k++) {
        double val = A2->data[i][k];
        val -= alpha * A2->data[j][k];
        A2->setData(i, k, qAbs(val) < zeroPrecision ? 0 : val);
      }
      double val = C2->data[i][0];
      val -= alpha * C2->data[j][0];
      C2->setData(i, 0, qAbs(val) < zeroPrecision ? 0 : val);
    }
  }

  ui->B2_tableWidget->clear();
  ui->B2_tableWidget->setRowCount(keys.size());
  ui->B2_tableWidget->setColumnCount(1);
  for (int i = 0; i < keys.size(); i++) {
    ui->B2_tableWidget->setItem(i, 0, new QTableWidgetItem(keys[i]));
  }

  Core::SetMatrixToWidget(ui->A2_tableWidget, *A2);
  Core::SetMatrixToWidget(ui->C2_tableWidget, *C2);

  ui->sol_pushButton->setEnabled(true);
}

void GaussTab::CalculatePressed() {
  solution.resize(keys.size());
  solution.fill(0);
  for (int i = A2->rows - 1; i >= 0; i--) {
    solution[i] = C2->getData(i, 0) / A2->getData(i, i);
    qDebug() << solution[i] << C2->getData(i, 0) << A2->getData(i, i);
    for (int j = i + 1; j < A2->cols; j++) {
      solution[i] -= A2->getData(i, j) * solution[j];
    }
  }

  ui->sol_tableWidget->clear();
  ui->sol_tableWidget->setRowCount(1);
  ui->sol_tableWidget->setColumnCount(solution.size());
  for (int i = 0; i < solution.size(); i++) {
    ui->sol_tableWidget->setItem(0, i, new QTableWidgetItem(QString("%1 = %2").arg(keys[i]).arg(solution[i])));
  }
}
