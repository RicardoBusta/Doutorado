#ifndef OCTREEBOX_H
#define OCTREEBOX_H

#include "octreeshape.h"

class OctreeBox : public OctreeShape
{
public:
  OctreeBox(float w, float h, float d, const QVector3D &center);

  virtual bool ConditionInside(const QVector3D &p);
private:
  float w;
  float h;
  float d;
  QVector3D center;
};

#endif // OCTREEBOX_H
