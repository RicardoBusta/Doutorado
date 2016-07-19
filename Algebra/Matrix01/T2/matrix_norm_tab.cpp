#include "matrix_norm_tab.h"
#include "ui_matrix_norm_tab.h"

#include "corefunctions.h"
#include "structures/simplematrix.h"

MatrixNormTab::MatrixNormTab(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::MatrixNormTab),
                                                M(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->calc_pushButton, SIGNAL(clicked(bool)), this, SLOT(Calculate()));
  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateMatrix()));
}

MatrixNormTab::~MatrixNormTab() {
  delete ui;
}

double MatrixNormTab::CalcMatrixForbNorm(SimpleMatrix &x) {
  double sum = 0;
  for (int c = 0; c < x.cols; c++) {
    for (int r = 0; r < x.rows; r++) {
      double d = x.getData(r, c);
      sum += d * d;
    }
  }
  sum = sqrt(sum);
  return sum;
}

double MatrixNormTab::CalcMatrix1Norm(SimpleMatrix &x) {
  double maxSum = -1;
  for (int c = 0; c < x.cols; c++) {
    double sum = 0;
    for (int r = 0; r < x.rows; r++) {
      sum += abs(x.getData(r, c));
    }
    if (sum > maxSum) {
      maxSum = sum;
    }
  }
  return maxSum;
}

double MatrixNormTab::CalcMatrixInfNorm(SimpleMatrix &x) {
  double maxSum = -1;
  for (int r = 0; r < x.rows; r++) {
    double sum = 0;
    for (int c = 0; c < x.cols; c++) {
      sum += abs(x.getData(r, c));
    }
    if (sum > maxSum) {
      maxSum = sum;
    }
  }
  return maxSum;
}

void MatrixNormTab::GenerateMatrix() {
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();
  SimpleMatrix::CreateMatrix(m, n, &M);
  M->Randomize();
  Core::SetMatrixToWidget(ui->M_tableWidget, *M);
}

void MatrixNormTab::Calculate() {
  if (M == nullptr)
    return;
  ui->normInf_label->setText(QString::number((CalcMatrixInfNorm(*M))));
  ui->normForb_label->setText(QString::number((CalcMatrixForbNorm(*M))));
  ui->norm1_label->setText(QString::number((CalcMatrix1Norm(*M))));
}
