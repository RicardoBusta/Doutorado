#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
  Matrix(int r, int c);
  ~Matrix();

  int rows, cols;

  double getData(int i, int j) const;
  void setData(int i, int j, double value);
  void addData(int i, int j, double value);

  void Randomize();
  void Zero();
  void Identity();

  void Copy(Matrix *M);
  void CopyTransposed(Matrix *M);
  void Increment(Matrix *M);
  void Subtract(Matrix *M);
  void Multiply(double val);

  Matrix* GetColumn(int j);

  static void Multiply(const Matrix &A, const Matrix &B, Matrix &C);

  void Resize(int r, int c);

  double *data;
};

#endif // MATRIX_H
