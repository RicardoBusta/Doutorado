#ifndef CSGPRISM_H
#define CSGPRISM_H

#include "csg/csgobject.h"

class CSGPrism : public CSGObject
{
public:
  CSGPrism(float r, float h, int s);

  float r, h;
  int s;
  QVector<QVector3D> points;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;
};

#endif // CSGPRISM_H
