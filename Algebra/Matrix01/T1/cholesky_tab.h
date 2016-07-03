#ifndef CHOLESKY_TAB_H
#define CHOLESKY_TAB_H

#include <QWidget>

namespace Ui {
class CholeskyTab;
}

class MainWindow;
class SimpleMatrix;

class CholeskyTab : public QWidget {
  Q_OBJECT

public:
  explicit CholeskyTab(MainWindow *w, QWidget *parent = 0);
  ~CholeskyTab();

private:
  Ui::CholeskyTab *ui;

  SimpleMatrix *A;
  SimpleMatrix *B;
  SimpleMatrix *C;

  void FillCholesky(SimpleMatrix *M);

private slots:
  void GenerateClicked();
  void LoadExample();
  void DecomposeClicked();

signals:
  void Error(QString msg);
};

#endif // CHOLESKY_TAB_H
