#ifndef CSGBOX_H
#define CSGBOX_H

#include "csg/csgobject.h"

class CSGBox : public CSGObject
{
public:
  CSGBox(float w, float h, float d);

  float w,h,d;

  HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);
  virtual bool ConditionInside(const QVector3D &p) const;
};

#endif // CSGBOX_H
