#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H

class SimpleMatrix {
public:
  SimpleMatrix(int r, int c);
  ~SimpleMatrix();

  int rows, cols;

  double getData(int i, int j) const;
  void setData(int i, int j, double value);
  void addData(int i, int j, double value);

  void Randomize();
  void Zero();
  void Identity();

  void Copy(SimpleMatrix *M);
  void CopyTransposed(SimpleMatrix *M);
  void Increment(SimpleMatrix *M);

  static void MultiplyByRow(const SimpleMatrix &A, const SimpleMatrix &B, SimpleMatrix &C);
  static void MultiplyByCol(const SimpleMatrix &A, const SimpleMatrix &B, SimpleMatrix &C);

  static void CreateMatrix(int r, int c, SimpleMatrix **M);

  double **data;
};

#endif // SIMPLEMATRIX_H
