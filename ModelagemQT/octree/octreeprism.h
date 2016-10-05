#ifndef OCTREEPRISM_H
#define OCTREEPRISM_H

#include "octreeshape.h"

#include <QVector>
#include <QVector3D>

class OctreePrism:public OctreeShape
{
public:
  OctreePrism(float r, float h, int s);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float r, h;
  int s;
  QVector<QVector3D> points;
  QVector3D normal;
};

#endif // OCTREEPRISM_H
