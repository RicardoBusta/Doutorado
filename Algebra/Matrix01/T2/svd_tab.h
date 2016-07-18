#ifndef SVD_TAB_H
#define SVD_TAB_H

#include <QWidget>

namespace Ui {
class SVDTab;
}

class SVDTab : public QWidget
{
  Q_OBJECT

public:
  explicit SVDTab(QWidget *parent = 0);
  ~SVDTab();

private:
  Ui::SVDTab *ui;
};

#endif // SVD_TAB_H
