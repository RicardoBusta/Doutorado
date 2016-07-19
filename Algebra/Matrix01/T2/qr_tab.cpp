#include "qr_tab.h"
#include "ui_qr_tab.h"

//baseado em https://rosettacode.org/wiki/QR_decomposition

#include "corefunctions.h"
#include "structures/matrix.h"

QRTab::QRTab(QWidget *parent) : QWidget(parent),
                                ui(new Ui::QRTab),
                                M(nullptr), Q(nullptr), R(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(Generate()));
  QObject::connect(ui->deco_pushButton, SIGNAL(clicked(bool)), this, SLOT(Calculate()));
}

QRTab::~QRTab() {
  delete ui;
}

void QRTab::GramSchmidt(Matrix &M, Matrix *Q, Matrix *R) {
  QList<Matrix> u;
  for(int i=0;i<M.cols;i++){
    Matrix * new_u = new Matrix(M.rows,1);
    //new_u->Copy();
  }
}

void QRTab::HouseHolder(Matrix &M, Matrix *Q, Matrix *R) {
  int m = M.rows;
  int n = M.cols;
  double mag, alpha;
  Matrix u(m, 1), v(m, 1);
  Matrix P(m, m), I(m, m);

  if (Q != nullptr)
    delete Q;
  Q = new Matrix(m, m);
  if (R != nullptr)
    delete R;
  R = new Matrix(M.rows, M.cols);

  for (int i = 0; i < n; i++) {
    u.Zero();
    v.Zero();

    mag = 0.0;
    for (int j = i; j < m; j++) {
      u.data[j] = R->data[j * n + i];
      mag += u.data[j] * u.data[j];
    }
    mag = sqrt(mag);

    alpha = u.data[i] < 0 ? mag : -mag;

    mag = 0.0;
    for (int j = i; j < m; j++) {
      v.data[j] = j == i ? u.data[j] + alpha : u.data[j];
      mag += v.data[j] * v.data[j];
    }
    mag = sqrt(mag);

    if (mag < 0.0000000001)
      continue;

    for (int j = i; j < m; j++)
      v.data[j] /= mag;

    //P = I - (v * v.transpose()) * 2.0;

    //R = P * R;
    //Q = Q * P;
  }
}

void QRTab::Generate() {
  if (M != nullptr) {
    delete M;
  }
  if (Q != nullptr) {
    delete Q;
  }
  if (R != nullptr) {
    delete R;
  }
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();

  M = new Matrix(m, n);
  M->Randomize();
  Core::SetMatrixToWidget(ui->M_tableWidget, *M);

  //Matrix::CreateMatrix(m, m, &Q);
  Q = new Matrix(m, m);
  Q->Zero();
  //Matrix::CreateMatrix(m, n, &R);
  R = new Matrix(m, n);
  R->Zero();
  Core::SetMatrixToWidget(ui->R_tableWidget, *R);
  Core::SetMatrixToWidget(ui->Q_tableWidget, *Q);
}

void QRTab::Calculate() {
  HouseHolder(*M, Q, R);
  Core::SetMatrixToWidget(ui->Q_tableWidget, *Q);
  Core::SetMatrixToWidget(ui->R_tableWidget, *R);
}
