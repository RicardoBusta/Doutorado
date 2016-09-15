#ifndef OCTREESPHERE_H
#define OCTREESPHERE_H

#include "octreeshape.h"

class OctreeSphere : public OctreeShape
{
public:
  OctreeSphere(float radius, const QVector3D &center);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float radius;
  QVector3D center;
};

#endif // OCTREESPHERE_H
