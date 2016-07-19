#ifndef LU_TAB_H
#define LU_TAB_H

#include <QWidget>

namespace Ui {
class LUTab;
}

class MainWindow;
class SimpleMatrix;

class LUTab : public QWidget {
  Q_OBJECT

public:
  explicit LUTab(MainWindow *w, QWidget *parent = 0);
  ~LUTab();

private:
  Ui::LUTab *ui;

  SimpleMatrix *A;
  SimpleMatrix *B;
  SimpleMatrix *C;

private slots:
  void GeneratePressed();
  void DecomposePressed();

signals:
  void Error(QString msg);
};

#endif // LU_TAB_H
