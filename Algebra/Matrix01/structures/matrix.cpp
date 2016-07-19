#include "matrix.h"

#include <QtMath>

Matrix::Matrix(int r, int c)
    : rows(r), cols(c), data(nullptr) {
  data = new double[r * c];
}

Matrix::~Matrix() {
  delete[] data;
}

double Matrix::getData(int i, int j) const {
  return data[j + cols * i];
}

void Matrix::setData(int i, int j, double value) {
  data[j + cols * i] = value;
}

void Matrix::addData(int i, int j, double value) {
  data[j + cols * i] += value;
}

void Matrix::Randomize() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      setData(i, j, (qrand() % 101) / 100.0f);
    }
  }
}

void Matrix::Zero() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      setData(i, j, 0);
    }
  }
}

void Matrix::Identity() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      setData(i, j, (i == j) ? 1 : 0);
    }
  }
}

void Matrix::Copy(Matrix *M) {
  memcpy(data, M->data, M->rows * M->cols * sizeof(double));
}

void Matrix::CopyTransposed(Matrix *M) {
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->cols; j++) {
      data[j + cols * i] = M->data[i + M->cols * j ];
    }
  }
}

void Matrix::Increment(Matrix *M) {
  if (rows != M->rows || cols != M->cols)
    return;
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->cols; j++) {
      data[j + cols * i] += M->data[j + cols * i];
    }
  }
}

void Matrix::Subtract(Matrix *M) {
  if (rows != M->rows || cols != M->cols)
    return;
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->cols; j++) {
      data[j + cols * i] -= M->data[j + cols * i];
    }
  }
}

void Matrix::Multiply(double val) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      data[j + cols * i] *= val;
    }
  }
}

Matrix *Matrix::GetColumn(int j) {
  Matrix * m = new Matrix(rows,1);
  for(int i=0;i<rows;i++){
    m->setData(i,0,getData(i,j));
  }
  return m;
}

void Matrix::Multiply(const Matrix &A, const Matrix &B, Matrix &C) {
  if (A.cols != B.rows) {
    qFatal("Wrong matrix sizes");
  }
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.cols; j++) {
      double c = 0;
      for (int k = 0; k < A.cols; k++) {
        c += A.getData(i,k) * B.getData(k,j);
      }
      C.setData(i,j,c);
    }
  }
}

void Matrix::Resize(int r, int c) {
  delete[] data;
  data = new double[r * c];
}
