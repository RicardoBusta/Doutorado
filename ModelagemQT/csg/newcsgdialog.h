#ifndef NEWCSGDIALOG_H
#define NEWCSGDIALOG_H

#include <QDialog>

namespace Ui {
class NewCSGDialog;
}

class Scene;

class NewCSGDialog : public QDialog
{
  Q_OBJECT

public:
  explicit NewCSGDialog(QWidget *parent = 0);
  ~NewCSGDialog();

  void CreateShape(Scene *scene);

  enum Shape{
    Invalid,
    Sphere,
    Cylinder,
    Box,
    Cone,
    Torus,
    Pyramid,
    Prism,
    Operation
  };

  Shape shape;
  double param[3];
private:
  Ui::NewCSGDialog *ui;

private slots:
  void SelectPrimitiveShape(bool checked);
};

#endif // NEWCSGDIALOG_H
