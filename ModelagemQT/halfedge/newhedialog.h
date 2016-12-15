#ifndef NEWHEDIALOG_H
#define NEWHEDIALOG_H

#include <QDialog>

namespace Ui {
class NewHEDialog;
}

class Scene;

class NewHEDialog : public QDialog
{
  Q_OBJECT

public:
  explicit NewHEDialog(QWidget *parent = 0);
  ~NewHEDialog();

  void CreateHE(Scene *scene);
private:
  Ui::NewHEDialog *ui;

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
private slots:
  void SelectPrimitiveShape(bool checked);
};

#endif // NEWHEDIALOG_H
