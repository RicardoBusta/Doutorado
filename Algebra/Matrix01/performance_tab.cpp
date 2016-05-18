#include "performance_tab.h"
#include "ui_performance_tab.h"

#include <QDebug>
#include <QElapsedTimer>

#include "corefunctions.h"

PerformanceTab::PerformanceTab(QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::PerformanceTab) {
  ui->setupUi(this);

  QObject::connect(ui->generate_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
  QObject::connect(ui->calculate_pushButton, SIGNAL(clicked(bool)), this, SLOT(CalculatePressed()));
}

PerformanceTab::~PerformanceTab() {
  delete ui;
}

void PerformanceTab::GeneratePressed() {
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();
  int p = ui->p_spinBox->value();

  SimpleMatrix::CreateMatrix(m, n, &A);
  SimpleMatrix::CreateMatrix(n, p, &B);
  SimpleMatrix::CreateMatrix(m, p, &C);

  A->Randomize();
  B->Randomize();

  Core::SetMatrixToWidget(ui->A_tableWidget, *A);
  Core::SetMatrixToWidget(ui->B_tableWidget, *B);
  ui->C_tableWidget->clear();
  ui->C_tableWidget->setRowCount(0);
  ui->C_tableWidget->setColumnCount(0);
}

void PerformanceTab::CalculatePressed() {
  if(A==nullptr || B==nullptr || C==nullptr){
    return;
  }
  QElapsedTimer timer;
  timer.start();
  SimpleMatrix::MultiplyByRow(*A, *B, *C);
  qint64 t1 = timer.elapsed();
  timer.start();
  SimpleMatrix::MultiplyByCol(*A, *B, *C);
  qint64 t2 = timer.elapsed();

  Core::SetMatrixToWidget(ui->C_tableWidget, *C);

  ui->row_label->setText(QString::number(t1));
  ui->col_label->setText(QString::number(t2));
}
