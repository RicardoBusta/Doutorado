#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include "object/object.h"

class Scene : public QObject {
  Q_OBJECT
public:
  explicit Scene(QObject *parent = 0);

  Object * current_object;

  QVector<Object*> objects;


  void Render();
private:
  bool make_parent;

signals:
  void UpdateObjList();
public slots:
  void UpdateMakeParent(bool val);
  void CreateObject();
  void CreateOctree();

  void CreateObjectGeneric(Object *obj);

  void ChangeOctreeSpread(int spread);
};

#endif // SCENE_H
