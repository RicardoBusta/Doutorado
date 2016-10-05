#ifndef OCTREEPYRAMID_H
#define OCTREEPYRAMID_H

#include "octreeshape.h"

#include <QVector3D>
#include <QVector>

class OctreePyramid:public OctreeShape
{
public:
  OctreePyramid(float r, float h, int s);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float r, h;
  int s;
  QVector<QVector3D> points;
};

#endif // OCTREEPYRAMID_H
