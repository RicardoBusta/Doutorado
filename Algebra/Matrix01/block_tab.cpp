#include "block_tab.h"
#include "ui_block_tab.h"

#include "corefunctions.h"
#include "mainwindow.h"
#include <structures/blockmatrix.h>

BlockTab::BlockTab(MainWindow *w, QWidget *parent) : QWidget(parent),
                                      ui(new Ui::BlockTab) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
  QObject::connect(ui->calc_pushButton, SIGNAL(clicked(bool)), this, SLOT(CalculatePressed()));
  QObject::connect(this,SIGNAL(Error(QString)),w,SLOT(ErrorMessage(QString)));

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

  BlockMatrix *A = new BlockMatrix(m, n, r, s);
  BlockMatrix *B = new BlockMatrix(n, p, s, t);
  BlockMatrix *C = new BlockMatrix(m, p, r, t);

  Core::SetMatrixToWidget(ui->A_tableWidget, *A);
  Core::SetMatrixToWidget(ui->B_tableWidget, *B);
  Core::SetMatrixToWidget(ui->C_tableWidget, *C);

  ui->calc_pushButton->setEnabled(true);
}

void BlockTab::CalculatePressed() {
  emit Error("Não Implementado");
}
