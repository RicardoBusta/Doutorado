#ifndef CSGOBJECT_H
#define CSGOBJECT_H

#include "object/object.h"
#include <QVector>
#include <QVector3D>

class CSGObject:public Object
{
public:
  CSGObject();

  QVector3D bb1;
  QVector3D bb2;

  virtual bool ConditionInside(const QVector3D &p) const =0;

  QVector<QVector3D> dots;

  void Init();
  virtual void Draw() const;
};

#endif // CSGOBJECT_H
