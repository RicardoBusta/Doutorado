#ifndef BLOCKMATRIX_H
#define BLOCKMATRIX_H

#include "simplematrix.h"

class BlockMatrix
{
public:
  BlockMatrix(int m, int n, int r, int s);
  ~BlockMatrix();

  SimpleMatrix * getData(int i, int j) const;

  int rows,cols;
  int rr,cc;
  int mm,nn;

private:
  SimpleMatrix ***data;
};

#endif // BLOCKMATRIX_H
