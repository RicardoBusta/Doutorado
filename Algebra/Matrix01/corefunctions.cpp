#include "corefunctions.h"

#include <QTableWidget>

namespace Core {
void CreateRandomMatrix(int m, int n, double ***A, bool rand) {
  (*A) = new double *[m];
  for (int i = 0; i < m; i++) {
    (*A)[i] = new double[n];
    for (int j = 0; j < n; j++) {
      (*A)[i][j] = rand ? (qrand() % 101) / 100.0f : 0;
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
}
