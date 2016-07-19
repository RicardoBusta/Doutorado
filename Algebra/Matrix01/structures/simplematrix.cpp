#include "simplematrix.h"

#include <QDebug>
#include <QtMath>

SimpleMatrix::SimpleMatrix(int r, int c)
    : rows(r), cols(c) {
  data = new double *[rows];
  for (int i = 0; i < rows; i++) {
    data[i] = new double[cols];
  }
}

SimpleMatrix::~SimpleMatrix() {
  for (int i = 0; i < rows; i++) {
    delete[] data[i];
  }
  delete[] data;
}

double SimpleMatrix::getData(int i, int j) const {
  return data[i][j];
}

void SimpleMatrix::setData(int i, int j, double value) {
  data[i][j] = value;
}

void SimpleMatrix::addData(int i, int j, double value) {
  data[i][j] += value;
}

void SimpleMatrix::Randomize() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      setData(i, j, (qrand() % 101) / 100.0f);
    }
  }
}

void SimpleMatrix::Zero() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      setData(i, j, 0);
    }
  }
}

void SimpleMatrix::Identity() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      setData(i, j, (i == j) ? 1 : 0);
    }
  }
}

void SimpleMatrix::Copy(SimpleMatrix *M) {
  memcpy(data, M->data, M->rows * M->cols * sizeof(double));
}

void SimpleMatrix::CopyTransposed(SimpleMatrix *M) {
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->cols; j++) {
      data[j][i] = M->data[i][j];
    }
  }
}

void SimpleMatrix::Increment(SimpleMatrix *M) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      data[i][j] += M->data[i][j];
    }
  }
}

void SimpleMatrix::MultiplyByRow(const SimpleMatrix &A, const SimpleMatrix &B, SimpleMatrix &C) {
  if (A.cols != B.rows) {
    qFatal("Wrong matrix sizes");
  }
  double **A_data = A.data;
  double **B_data = B.data;
  double **C_data = C.data;
  for (int i = 0; i < A.rows; i++) {
    double *A_row = A_data[i];
    double *C_row = C_data[i];
    for (int j = 0; j < B.cols; j++) {
      C_row[j] = 0;
      for (int k = 0; k < A.cols; k++) {
        C_row[j] += A_row[k] * B_data[k][j];
      }
    }
  }
}

void SimpleMatrix::MultiplyByCol(const SimpleMatrix &A, const SimpleMatrix &B, SimpleMatrix &C) {
  if (A.cols != B.rows) {
    qFatal("Wrong matrix sizes");
  }
  double **A_data = A.data;
  double **B_data = B.data;
  double **C_data = C.data;
  for (int j = 0; j < B.cols; j++) {
    for (int i = 0; i < A.rows; i++) {
      C_data[i][j] = 0;
      double *A_row = A_data[i];
      for (int k = 0; k < A.cols; k++) {
        C_data[i][j] += A_row[k] * B_data[k][j];
      }
    }
  }
}

void SimpleMatrix::CreateMatrix(int r, int c, SimpleMatrix **M) {
  if ((*M) != nullptr) {
    delete (*M);
  }
  (*M) = new SimpleMatrix(r, c);
}
