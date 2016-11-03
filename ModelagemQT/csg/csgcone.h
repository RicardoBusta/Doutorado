#ifndef CSGCONE_H
#define CSGCONE_H

#include "csg/csgobject.h"

class CSGCone : public CSGObject
{
public:
  CSGCone(float radius, float height);

  float radius;
  float height;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;
};

#endif // CSGCONE_H
