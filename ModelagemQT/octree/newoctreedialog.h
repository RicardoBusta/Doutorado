#ifndef NEWOCTREEDIALOG_H
#define NEWOCTREEDIALOG_H

#include <QDialog>

namespace Ui {
class NewOctreeDialog;
}

class Scene;

class NewOctreeDialog : public QDialog
{
  Q_OBJECT

public:
  explicit NewOctreeDialog(QWidget *parent = 0);
  ~NewOctreeDialog();

  enum Shape{
    Invalid,
    Sphere,
    Cylinder,
    Box,
    Cone,
    Torus,
    Pyramid,
    Prism
  };

  Shape shape;
  double param[3];

  void CreateShape(Scene *scene);
private:
  Ui::NewOctreeDialog *ui;

  QRgb face;
  QRgb line;
private slots:
  void SelectPrimitiveShape(bool checked);
  void SelectFaceColor();
  void SelectLineColor();
};

#endif // NEWOCTREEDIALOG_H
