#ifndef OCTREEPYRAMID_H
#define OCTREEPYRAMID_H

#include "octreeshape.h"

class OctreePyramid:public OctreeShape
{
public:
  OctreePyramid(float r, float h, float s);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float r, h, s;
};

#endif // OCTREEPYRAMID_H
