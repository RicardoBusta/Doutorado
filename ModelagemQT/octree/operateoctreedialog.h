#ifndef OPERATEOCTREEDIALOG_H
#define OPERATEOCTREEDIALOG_H

#include <QDialog>
#include <QVector>

namespace Ui {
class OperateOctreeDialog;
}

class Scene;
class Object;
class Octree;

class OperateOctreeDialog : public QDialog
{
  Q_OBJECT

public:
  explicit OperateOctreeDialog(Scene *scene, QWidget *parent = 0);
  ~OperateOctreeDialog();

    void Operate();
private:
  Ui::OperateOctreeDialog *ui;

  Scene *scene;

  QVector<Octree*>objects_ref;

  void GetOctreesRec(Object *obj);
};

#endif // OPERATEOCTREEDIALOG_H
