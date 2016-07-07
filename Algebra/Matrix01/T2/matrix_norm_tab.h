#ifndef MATRIX_NORM_TAB_H
#define MATRIX_NORM_TAB_H

#include <QWidget>

namespace Ui {
class MatrixNormTab;
}

class MatrixNormTab : public QWidget {
  Q_OBJECT

 public:
  explicit MatrixNormTab(QWidget *parent = 0);
  ~MatrixNormTab();

 private:
  Ui::MatrixNormTab *ui;
};

#endif  // MATRIX_NORM_TAB_H
