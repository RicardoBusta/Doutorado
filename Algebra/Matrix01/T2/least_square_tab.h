#ifndef LEAST_SQUARE_TAB_H
#define LEAST_SQUARE_TAB_H

#include <QWidget>

namespace Ui {
class LeastSquareTab;
}

class LeastSquareTab : public QWidget {
  Q_OBJECT

public:
  explicit LeastSquareTab(QWidget *parent = 0);
  ~LeastSquareTab();

private:
  Ui::LeastSquareTab *ui;
};

#endif // LEAST_SQUARE_TAB_H
