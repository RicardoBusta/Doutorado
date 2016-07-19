#ifndef PERFORMANCE_TAB_H
#define PERFORMANCE_TAB_H

#include <QWidget>

#include "structures/simplematrix.h"

namespace Ui {
class PerformanceTab;
}

class MainWindow;

class PerformanceTab : public QWidget {
  Q_OBJECT

public:
  explicit PerformanceTab(MainWindow *w, QWidget *parent = 0);
  ~PerformanceTab();

private:
  Ui::PerformanceTab *ui;

  SimpleMatrix *A, *B, *C;

private slots:
  void GeneratePressed();
  void CalculatePressed();

signals:
  void Error(QString msg);
};

#endif // PERFORMANCE_TAB_H
