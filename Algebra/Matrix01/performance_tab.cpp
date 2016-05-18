#include "performance_tab.h"
#include "ui_performance_tab.h"

#include <QDebug>
#include <QElapsedTimer>

#include "corefunctions.h"

PerformanceTab::PerformanceTab(QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::PerformanceTab) {
  ui->setupUi(this);

  QObject::connect(ui->generate_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
}

PerformanceTab::~PerformanceTab() {
  delete ui;
}

void PerformanceTab::GeneratePressed() {
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();
  int p = ui->p_spinBox->value();

  double **A;
  Core::CreateRandomMatrix(m, n, &A, true);

  double **B;
  Core::CreateRandomMatrix(n, p, &B, true);

  double **C;
  Core::CreateRandomMatrix(m, p, &C, false);

  QElapsedTimer timer;
  timer.start();
  Core::MultiplyByRow(m,n,p,A,B,&C);
  qint64 t1 = timer.elapsed();
  timer.start();
  Core::MultiplyByCol(m,n,p,A,B,&C);
  qint64 t2 = timer.elapsed();

  Core::SetMatrixToWidget(ui->A_tableWidget, m, n, A);
  Core::SetMatrixToWidget(ui->B_tableWidget, n, p, B);
  Core::SetMatrixToWidget(ui->C_tableWidget, m, p, C);

  ui->row_label->setText(QString::number(t1));
  ui->col_label->setText(QString::number(t2));
}
