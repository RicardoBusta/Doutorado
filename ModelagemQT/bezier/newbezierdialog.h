#ifndef NEWBEZIERDIALOG_H
#define NEWBEZIERDIALOG_H

#include <QDialog>

namespace Ui {
class NewBezierDialog;
}

class Scene;

class NewBezierDialog : public QDialog
{
  Q_OBJECT

public:
  explicit NewBezierDialog(QWidget *parent = 0);
  ~NewBezierDialog();

  void Create(Scene *scene);
private:
  Ui::NewBezierDialog *ui;
};

#endif // NEWBEZIERDIALOG_H
