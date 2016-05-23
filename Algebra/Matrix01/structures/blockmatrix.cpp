#include "blockmatrix.h"

#include <QtMath>

BlockMatrix::BlockMatrix(int m, int n, int r, int s) {
  rows = m * r;
  cols = n * s;
  rr = r;
  cc = s;
  mm = m;
  nn = n;

  data = new SimpleMatrix **[rr];
  for (int i = 0; i < rr; i++) {
    data[i] = new SimpleMatrix *[cc];
    for (int j = 0; j < cc; j++) {
      data[i][j] = new SimpleMatrix(m, n);
    }
  }
}

BlockMatrix::~BlockMatrix() {
  for (int i = 0; i < rr; i++) {
    for (int j = 0; j < cc; j++) {
      delete data[i][j];
    }
    delete[] data[i];
  }
  delete[] data;
}

SimpleMatrix *BlockMatrix::getData(int i, int j) const {
  return data[i][j];
}

void BlockMatrix::Randomize() {
  for (int i = 0; i < rr; i++) {
    for (int j = 0; j < cc; j++) {
      data[i][j]->Randomize();
    }
  }
}

void BlockMatrix::Zero() {
  for (int i = 0; i < rr; i++) {
    for (int j = 0; j < cc; j++) {
      data[i][j]->Zero();
    }
  }
}

void BlockMatrix::CreateMatrix(int m, int n, int r, int s, BlockMatrix **M) {
  if ((*M) != nullptr) {
    delete (*M);
  }
  (*M) = new BlockMatrix(m,n,r,s);
}
