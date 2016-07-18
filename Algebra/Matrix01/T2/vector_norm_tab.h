#ifndef VECTOR_NORM_TAB_H
#define VECTOR_NORM_TAB_H

#include <QWidget>

namespace Ui {
class VectorNormTab;
}

class SimpleMatrix;

class VectorNormTab : public QWidget {
  Q_OBJECT

 public:
  explicit VectorNormTab(QWidget *parent = 0);
  ~VectorNormTab();

 private:
  Ui::VectorNormTab *ui;

  SimpleMatrix *V;
  SimpleMatrix *A;

  double CalcVectorPNorm(SimpleMatrix &x, int p);
  double CalcVectorInfNorm(SimpleMatrix &x);
  double CalcVectorANorm(SimpleMatrix &x, SimpleMatrix &A);

 private slots:
  void GenerateVector();
  void Calculate();
};

#endif  // VECTOR_NORM_TAB_H
