#ifndef CSGCYLINDER_H
#define CSGCYLINDER_H

#include "csg/csgobject.h"

class CSGCylinder : public CSGObject
{
public:
  CSGCylinder(float radius, float height);

  float radius;
  float height;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;
};

#endif // CSGCYLINDER_H
