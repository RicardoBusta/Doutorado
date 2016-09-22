#ifndef OCTREETORUS_H
#define OCTREETORUS_H

#include "octreeshape.h"

class OctreeTorus : public OctreeShape
{
public:
  OctreeTorus(float r1, float r2, const QVector3D &center);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float r1;
  float r2;
  QVector3D center;
};

#endif // OCTREETORUS_H
