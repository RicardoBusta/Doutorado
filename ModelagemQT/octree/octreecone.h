#ifndef OCTREECONE_H
#define OCTREECONE_H

#include "octreeshape.h"

class OctreeCone : public OctreeShape
{
public:
  OctreeCone(float radius, float height, const QVector3D &center);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float radius;
  float height;
  QVector3D center;
};

#endif // OCTREECONE_H
