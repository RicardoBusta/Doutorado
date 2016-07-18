#ifndef MATRIX_NORM_TAB_H
#define MATRIX_NORM_TAB_H

#include <QWidget>

namespace Ui {
class MatrixNormTab;
}

class SimpleMatrix;

class MatrixNormTab : public QWidget {
  Q_OBJECT

 public:
  explicit MatrixNormTab(QWidget *parent = 0);
  ~MatrixNormTab();

 private:
  Ui::MatrixNormTab *ui;

  SimpleMatrix *M;

  double CalcMatrixForbNorm(SimpleMatrix &x);
  double CalcMatrix1Norm(SimpleMatrix &x);
  double CalcMatrixInfNorm(SimpleMatrix &x);
private slots:
  void GenerateMatrix();
  void Calculate();
};

#endif  // MATRIX_NORM_TAB_H
