#ifndef OCTREECYLINDER_H
#define OCTREECYLINDER_H

#include "octreeshape.h"

class OctreeCylinder : public OctreeShape {
public:
  OctreeCylinder(float radius, float height, const QVector3D &center);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float radius;
  float height;
  QVector3D center;
};

#endif // OCTREECYLINDER_H
