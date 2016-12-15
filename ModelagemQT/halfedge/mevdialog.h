#ifndef MEVDIALOG_H
#define MEVDIALOG_H

#include <QDialog>

namespace Ui {
class MEVDialog;
}

class HalfEdgeObject;

class MEVDialog : public QDialog
{
  Q_OBJECT

public:
  explicit MEVDialog(QWidget *parent = 0);
  ~MEVDialog();

  void Apply(HalfEdgeObject *he);
private:
  Ui::MEVDialog *ui;
};

#endif // MEVDIALOG_H
