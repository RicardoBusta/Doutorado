#ifndef MEFDIALOG_H
#define MEFDIALOG_H

#include <QDialog>

namespace Ui {
class MEFDialog;
}

class HalfEdgeObject;

class MEFDialog : public QDialog
{
  Q_OBJECT

public:
  explicit MEFDialog(QWidget *parent = 0);
  ~MEFDialog();

  void Apply(HalfEdgeObject *he);
private:
  Ui::MEFDialog *ui;
};

#endif // MEFDIALOG_H
