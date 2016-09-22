#ifndef OCTREESHAPE_H
#define OCTREESHAPE_H

#include <QVector3D>
#include "octreenode.h"

class OctreeShape
{
public:
  OctreeShape();

  virtual bool ConditionInside(const QVector3D &p)=0;
  OctreeNode* GenRec(int max_depth, int depth, float size, const QVector3D &p1, const QVector3D &p2);
};

#endif // OCTREESHAPE_H
