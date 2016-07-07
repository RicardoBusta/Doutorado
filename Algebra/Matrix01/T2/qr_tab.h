#ifndef QR_TAB_H
#define QR_TAB_H

#include <QWidget>

namespace Ui {
class QRTab;
}

class QRTab : public QWidget {
  Q_OBJECT

 public:
  explicit QRTab(QWidget *parent = 0);
  ~QRTab();

 private:
  Ui::QRTab *ui;
};

#endif  // QR_TAB_H
