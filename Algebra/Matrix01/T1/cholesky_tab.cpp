#include "cholesky_tab.h"
#include "ui_cholesky_tab.h"

#include "corefunctions.h"
#include "mainwindow.h"
#include "structures/simplematrix.h"
#include <QtMath>

#include "structures/simplematrix.h"

#include <QDebug>

CholeskyTab::CholeskyTab(MainWindow *w, QWidget *parent) : QWidget(parent),
                                                           ui(new Ui::CholeskyTab), A(nullptr), B(nullptr), C(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateClicked()));
  QObject::connect(ui->deco_pushButton, SIGNAL(clicked(bool)), this, SLOT(DecomposeClicked()));
  QObject::connect(ui->example_pushButton, SIGNAL(clicked(bool)), this, SLOT(LoadExample()));
  QObject::connect(this, SIGNAL(Error(QString)), w, SLOT(ErrorMessage(QString)));

  ui->deco_pushButton->setEnabled(false);
}

CholeskyTab::~CholeskyTab() {
  delete ui;
}

void CholeskyTab::FillCholesky(SimpleMatrix *M) {
  SimpleMatrix base(M->rows, M->cols);

  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j <= i; j++) {
      base.setData(i, j, rand() % 100);
    }
  }

  SimpleMatrix base_t(base.rows, base.cols);
  base_t.CopyTransposed(&base);

  SimpleMatrix::MultiplyByCol(base, base_t, *M);
}

void CholeskyTab::GenerateClicked() {
  int m = ui->m_spinBox->value();

  SimpleMatrix::CreateMatrix(m, m, &A);
  SimpleMatrix::CreateMatrix(m, m, &B);
  SimpleMatrix::CreateMatrix(m, m, &C);

  A->Randomize();

  Core::SetMatrixToWidget(ui->A_tableWidget, *A);

  ui->deco_pushButton->setEnabled(true);
}

void CholeskyTab::LoadExample() {
  SimpleMatrix::CreateMatrix(3, 3, &A);
  SimpleMatrix::CreateMatrix(3, 3, &B);
  SimpleMatrix::CreateMatrix(3, 3, &C);
  switch (qrand() % 2) {
  case 0: {
    double x[3][3] = {{1, 0, 3},
                      {0, 4, 2},
                      {3, 2, 11}};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        A->setData(i, j, x[i][j]);
      }
    }
    break;
  }
  case 1: {
    double x[3][3] = {{4, 12, -16},
                      {12, 37, -43},
                      {-16, -43, 98}};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        A->setData(i, j, x[i][j]);
      }
    }
    break;
  }
  }
  Core::SetMatrixToWidget(ui->A_tableWidget, *A);
  ui->deco_pushButton->setEnabled(true);
}

void CholeskyTab::DecomposeClicked() {
  if (A == nullptr || B == nullptr) {
    emit Error("Matrizes nulas.");
    return;
  }
  bool ok;
  Core::GetMatrixFromWidget(ui->A_tableWidget, *A, &ok);
  if (!ok) {
    emit Error("Algum valor inválido em A.");
    return;
  }

  B->Zero();
  for (int j = 0; j < A->cols; j++) {
    double B_jj = A->getData(j, j);
    for (int k = 0; k < j; k++) {
      B_jj -= qPow(B->getData(j, k), 2);
    }
    if (B_jj <= 0) {
      emit Error("Não é positiva definida." + QString::number(B_jj));
      Core::SetMatrixToWidget(ui->B_tableWidget, *B);
      return;
    }
    B_jj = qSqrt(B_jj);
    B->setData(j, j, B_jj);
    for (int i = j + 1; i < A->rows; i++) {
      double B_ij = A->getData(i, j);
      for (int k = 0; k < j; k++) {
        B_ij -= B->getData(i, k) * B->getData(j, k);
      }
      B_ij /= B_jj;
      B->setData(i, j, B_ij);
    }
  }
  C->CopyTransposed(B);

  Core::SetMatrixToWidget(ui->B_tableWidget, *B);
  Core::SetMatrixToWidget(ui->C_tableWidget, *C);
}
