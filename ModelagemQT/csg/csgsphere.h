#ifndef CSGSPHERE_H
#define CSGSPHERE_H

#include "csg/csgobject.h"

class CSGSphere : public CSGObject
{
public:
  CSGSphere(float radius);

  float radius;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;
};

#endif // CSGSPHERE_H
