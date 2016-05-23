#include "block_tab.h"
#include "ui_block_tab.h"

#include "corefunctions.h"
#include "mainwindow.h"
#include <structures/blockmatrix.h>
#include <QDebug>

BlockTab::BlockTab(MainWindow *w, QWidget *parent) : QWidget(parent),
                                                     ui(new Ui::BlockTab), A(nullptr), B(nullptr), C(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
  QObject::connect(ui->calc_pushButton, SIGNAL(clicked(bool)), this, SLOT(CalculatePressed()));
  QObject::connect(this, SIGNAL(Error(QString)), w, SLOT(ErrorMessage(QString)));

  ui->calc_pushButton->setEnabled(false);
}

BlockTab::~BlockTab() {
  delete ui;
}

void BlockTab::GeneratePressed() {
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();
  int p = ui->p_spinBox->value();

  int r = ui->mb_spinBox->value();
  int s = ui->nb_spinBox->value();
  int t = ui->pb_spinBox->value();

  BlockMatrix::CreateMatrix(m, n, r, s, &A);
  BlockMatrix::CreateMatrix(n, p, s, t, &B);
  BlockMatrix::CreateMatrix(m, p, r, t, &C);

  A->Randomize();
  B->Randomize();
  C->Zero();

  Core::SetMatrixToWidget(ui->A_tableWidget, *A);
  Core::SetMatrixToWidget(ui->B_tableWidget, *B);

  ui->calc_pushButton->setEnabled(true);
}

void BlockTab::CalculatePressed() {
  for (int i = 0; i < A->rr; i++) {
    for (int j = 0; j < B->cc; i++) {
      qDebug() << i << j;
      SimpleMatrix * c_ptr = C->getData(i,j);
      SimpleMatrix accumulator(c_ptr->rows, c_ptr->cols);
      accumulator.Zero();
      c_ptr->Zero();
      for (int k = 0; k < A->cc; k++) {
        SimpleMatrix *a_ptr, *b_ptr;
        a_ptr = A->getData(i,k);
        b_ptr = B->getData(k,j);
        SimpleMatrix::MultiplyByRow(*a_ptr,*b_ptr, accumulator);
        c_ptr->Increment(&accumulator);
      }
    }
  }

  Core::SetMatrixToWidget(ui->C_tableWidget, *C);
}
