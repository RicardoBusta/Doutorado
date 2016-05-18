#ifndef SIMPLEMATRIX_H
#define SIMPLEMATRIX_H


class SimpleMatrix
{
public:
  SimpleMatrix(int r, int c);
  ~SimpleMatrix();

  int rows,cols;

  double getData(int i, int j) const;
  void setData(int i, int j, double value);
  void addData(int i, int j, double value);

  void Randomize();

  static void MultiplyByRow(const SimpleMatrix &A, const SimpleMatrix &B, SimpleMatrix &C);
  static void MultiplyByCol(const SimpleMatrix &A, const SimpleMatrix &B, SimpleMatrix &C);

  static void CreateMatrix(int r, int c, SimpleMatrix **M);

private:
  double **data;
};

#endif // SIMPLEMATRIX_H
