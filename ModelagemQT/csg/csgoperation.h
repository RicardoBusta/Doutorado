#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csg/csgobject.h"

class CSGOPeration : public CSGObject
{
public:
  CSGOPeration(int op);

  int op;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;

  void Recalculate();
};

#endif // CSGOPERATION_H
