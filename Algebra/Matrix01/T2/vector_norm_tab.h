#ifndef VECTOR_NORM_TAB_H
#define VECTOR_NORM_TAB_H

#include <QWidget>

namespace Ui {
class VectorNormTab;
}

class VectorNormTab : public QWidget
{
  Q_OBJECT

public:
  explicit VectorNormTab(QWidget *parent = 0);
  ~VectorNormTab();

private:
  Ui::VectorNormTab *ui;
};

#endif // VECTOR_NORM_TAB_H
