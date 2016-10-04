#ifndef OCTREEUNION_H
#define OCTREEUNION_H

#include "octreeshape.h"

class Octree;

class OctreeUnion : public OctreeShape
{
public:
    OctreeUnion(Octree *oc1, Octree *oc2, const QVector3D &p1, const QVector3D &p2);

    virtual bool ConditionInside(const QVector3D &p);

    OctreeNode *GenRecur(int max_depth,int depth);
private:
    Octree *oc1;
    Octree *oc2;
    QVector3D p1;
    QVector3D p2;
};

#endif // OCTREEUNION_H
