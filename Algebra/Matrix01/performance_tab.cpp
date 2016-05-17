#include "performance_tab.h"
#include "ui_performance_tab.h"

#include <QDebug>
#include <QElapsedTimer>

PerformanceTab::PerformanceTab(QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::PerformanceTab) {
  ui->setupUi(this);

  QObject::connect(ui->generate_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
}

PerformanceTab::~PerformanceTab() {
  delete ui;
}

void CreateMatrix(int m, int n, double ***A, bool rand) {
  (*A) = new double *[m];
  for (int i = 0; i < m; i++) {
    (*A)[i] = new double[n];
    for (int j = 0; j < n; j++) {
      (*A)[i][j] = rand ? (qrand() % 100) : 0;
    }
  }
}

void SetMatrixToWidget(QTableWidget *widget, int m, int n, double **M) {
  widget->clear();
  widget->setRowCount(m);
  widget->setColumnCount(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      QTableWidgetItem *item = new QTableWidgetItem();
      widget->setItem(i, j, item);
      item->setText(QString::number(M[i][j]));
    }
  }
}

void MultiplyByRow(int m, int n, int p, double **A, double **B, double ***C) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      for (int k = 0; k < n; k++) {
        (*C)[i][j] += (A[i][k] * B[k][j]);
      }
    }
  }
}

void MultiplyByCol(int m, int n, int p, double **A, double **B, double ***C) {
  for (int j = 0; j < p; j++) {
    for (int i = 0; i < m; i++) {
      for (int k = 0; k < n; k++) {
        (*C)[i][j] += (A[i][k] * B[k][j]);
      }
    }
  }
}

void PerformanceTab::GeneratePressed() {
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();
  int p = ui->p_spinBox->value();

  double **A;
  CreateMatrix(m, n, &A, true);

  double **B;
  CreateMatrix(n, p, &B, true);

  double **C;
  CreateMatrix(m, p, &C, false);

  QElapsedTimer timer;
  timer.start();
  MultiplyByRow(m,n,p,A,B,&C);
  qint64 t1 = timer.elapsed();
  timer.start();
  MultiplyByCol(m,n,p,A,B,&C);
  qint64 t2 = timer.elapsed();

  SetMatrixToWidget(ui->A_tableWidget, m, n, A);
  SetMatrixToWidget(ui->B_tableWidget, n, p, B);
  SetMatrixToWidget(ui->C_tableWidget, m, p, C);

  ui->row_label->setText(QString::number(t1));
  ui->col_label->setText(QString::number(t2));
}
