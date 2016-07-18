#include "vector_norm_tab.h"
#include "ui_vector_norm_tab.h"

#include "corefunctions.h"
#include "structures/simplematrix.h"

#include <QDebug>

VectorNormTab::VectorNormTab(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::VectorNormTab),
      V(nullptr), A(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateVector()));
  QObject::connect(ui->calc_pushButton, SIGNAL(clicked(bool)), this, SLOT(Calculate()));
}

VectorNormTab::~VectorNormTab() {
  delete ui;
}

double VectorNormTab::CalcVectorPNorm(SimpleMatrix &x, int p) {
  double sum = 0;
  for (int i = 0; i < x.rows; i++) {
    double d = x.getData(i, 0);
    sum += pow(d, p);
  }
  sum = pow(sum, 1.0 / (double)p);

  return sum;
}

double VectorNormTab::CalcVectorInfNorm(SimpleMatrix &x) {
  double maxVal = -9999;
  for (int i = 0; i < x.rows; i++) {
    double d = abs(x.getData(i, 0));
    if(d>maxVal){
      maxVal = d;
    }
  }
  maxVal = pow(maxVal, 0.5);

  return maxVal;
}

double VectorNormTab::CalcVectorANorm(SimpleMatrix &x, SimpleMatrix &A) {
  SimpleMatrix xt(x.cols,x.rows);
  xt.CopyTransposed(&x);
  SimpleMatrix::MultiplyByCol(xt,A,xt);
  SimpleMatrix::MultiplyByCol(xt,x,xt);
  double d = xt.getData(0,0);
  d = sqrt(d);
  return d;
}

void VectorNormTab::GenerateVector() {
  int vector_size = ui->vsize_spinBox->value();
  SimpleMatrix::CreateMatrix(vector_size, 1, &V);
  SimpleMatrix::CreateMatrix(vector_size, vector_size, &A);
  V->Randomize();
  A->Randomize();
  Core::SetMatrixToWidget(ui->A_tableWidget, *A);
  Core::SetMatrixToWidget(ui->V_tableWidget, *V);
}

void VectorNormTab::Calculate() {
  ui->norm1_label->setText(QString::number((CalcVectorPNorm(*V, 1))));
  ui->norm2_label->setText(QString::number((CalcVectorPNorm(*V, 2))));
  ui->norm3_label->setText(QString::number((CalcVectorPNorm(*V, 3))));
  ui->norm4_label->setText(QString::number((CalcVectorPNorm(*V, 4))));
  ui->normInf_label->setText(QString::number((CalcVectorInfNorm(*V))));
  ui->normA_label->setText(QString::number((CalcVectorANorm(*V, *A))));
}
