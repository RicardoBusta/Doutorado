#include "lu_tab.h"
#include "ui_lu_tab.h"

#include "corefunctions.h"
#include "mainwindow.h"
#include "structures/simplematrix.h"

#include <QDebug>

LUTab::LUTab(MainWindow *w, QWidget *parent) : QWidget(parent),
                                               ui(new Ui::LUTab), A(nullptr), B(nullptr), C(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
  QObject::connect(ui->deco_pushButton, SIGNAL(clicked(bool)), this, SLOT(DecomposePressed()));
  QObject::connect(this, SIGNAL(Error(QString)), w, SLOT(ErrorMessage(QString)));

  ui->deco_pushButton->setEnabled(false);
}

LUTab::~LUTab() {
  delete ui;
}

void LUTab::GeneratePressed() {
  int m = ui->m_spinBox->value();

  SimpleMatrix::CreateMatrix(m, m, &A);
  SimpleMatrix::CreateMatrix(m, m, &B);
  SimpleMatrix::CreateMatrix(m, m, &C);

  A->Randomize();
  B->Zero();
  C->Zero();

  Core::SetMatrixToWidget(ui->A_tableWidget, *A);

  ui->deco_pushButton->setEnabled(true);
}

void LUTab::DecomposePressed() {
  if (A == nullptr) {
    emit Error("Matrizes nulas.");
    return;
  }
  bool ok;
  Core::GetMatrixFromWidget(ui->A_tableWidget, *A, &ok);
  if (!ok) {
    emit Error("Algum valor inválido em A.");
    return;
  }

  double thresh = 0.0001;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->cols; j++) {
      if (i > j) {
        double sum = A->getData(i, j);
        for (int k = 0; k < j; k++) {
          sum -= B->getData(i, k) * C->getData(k, j);
        }
        sum = sum / C->getData(j, j);
        if (qAbs(sum) < thresh) {
          sum = 0;
        }
        B->setData(i, j, sum);
      } else {
        double sum = A->getData(i, j);
        qDebug() << sum << i << j;
        for (int k = 0; k < i; k++) {
          sum -= B->getData(i, k) * C->getData(k, j);
          qDebug() << sum << i << j;
        }
        if (qAbs(sum) < thresh) {
          sum = 0;
        }
        C->setData(i, j, sum);
      }
    }
  }

  Core::SetMatrixToWidget(ui->B_tableWidget, *B);
  Core::SetMatrixToWidget(ui->C_tableWidget, *C);
}
