#ifndef OPERATEOCTREEDIALOG_H
#define OPERATEOCTREEDIALOG_H

#include <QDialog>

namespace Ui {
class OperateOctreeDialog;
}

class Scene;
class Object;

class OperateOctreeDialog : public QDialog
{
  Q_OBJECT

public:
  explicit OperateOctreeDialog(Scene *scene, QWidget *parent = 0);
  ~OperateOctreeDialog();

private:
  Ui::OperateOctreeDialog *ui;

  Scene *scene;

  void GetOctreesRec(Object *obj);
};

#endif // OPERATEOCTREEDIALOG_H
