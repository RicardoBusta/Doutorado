#ifndef CSGPYRAMID_H
#define CSGPYRAMID_H

#include "csg/csgobject.h"

class CSGPyramid : public CSGObject
{
public:
  CSGPyramid(float r, float h, int s);

  float r,h;
  int s;

  QVector<QVector3D> points;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;
};

#endif // CSGPYRAMID_H
