#ifndef QR_TAB_H
#define QR_TAB_H

#include <QWidget>

namespace Ui {
class QRTab;
}

class Matrix;

class QRTab : public QWidget {
  Q_OBJECT

public:
  explicit QRTab(QWidget *parent = 0);
  ~QRTab();

  void GramSchmidt(Matrix &M, Matrix *Q, Matrix *R);
  void HouseHolder(Matrix &M, Matrix *Q, Matrix *R);
private:
  Ui::QRTab *ui;

  Matrix *M;
  Matrix *Q;
  Matrix *R;

private slots:
  void Generate();
  void Calculate();
};

#endif // QR_TAB_H
