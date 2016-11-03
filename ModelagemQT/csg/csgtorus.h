#ifndef CSGTORUS_H
#define CSGTORUS_H

#include "csg/csgobject.h"

class CSGTorus : public CSGObject
{
public:
  CSGTorus(float r1, float r2);

  float r1,r2;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;
};

#endif // CSGTORUS_H
