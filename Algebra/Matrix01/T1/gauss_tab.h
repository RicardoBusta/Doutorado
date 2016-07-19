#ifndef GAUSS_TAB_H
#define GAUSS_TAB_H

#include <QString>
#include <QVector>
#include <QWidget>

namespace Ui {
class GaussTab;
}

class MainWindow;
class SimpleMatrix;

class GaussTab : public QWidget {
  Q_OBJECT

public:
  explicit GaussTab(MainWindow *w, QWidget *parent = 0);
  ~GaussTab();

private:
  Ui::GaussTab *ui;

  SimpleMatrix *A1, *C1;
  SimpleMatrix *A2, *C2;

  QVector<QString> keys;
  QVector<double> solution;

private slots:
  void GeneratePressed();
  void EliminatePressed();
  void CalculatePressed();

signals:
  void Error(QString msg);
};

#endif // GAUSS_TAB_H
