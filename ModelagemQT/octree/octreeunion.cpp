#include "octreeunion.h"

#include "octree/octree.h"

OctreeUnion::OctreeUnion(Octree *oc1, Octree *oc2, const QVector3D &p1, const QVector3D &p2)
    :OctreeShape(),oc1(oc1),oc2(oc2),p1(p1),p2(p2)
{

}

bool OctreeUnion::ConditionInside(const QVector3D &p)
{
    return true;
}

OctreeNode* OctreeUnion::GenRecur(int max_depth, int depth)
{
    if(depth<max_depth){
        OctreeNode *node = new OctreePartial();
    }else{
        return new OctreeFull();
    }
    OctreeNode *n = new OctreeFull();
    n->p1 = p1;
    n->p2 = p2;
    return n;
}
