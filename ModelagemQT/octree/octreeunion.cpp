#include "octreeunion.h"

#include "octree/octree.h"

OctreeUnion::OctreeUnion(Octree *oc1, Octree *oc2, const QVector3D &p1, const QVector3D &p2,int op)
  :OctreeShape(),oc1(oc1),oc2(oc2),p1(p1),p2(p2),op(op)
{
}

bool OctreeUnion::ConditionInside(const QVector3D &p)
{
  QVector3D p1_p = oc1->InvTransform()*p;
  QVector3D p2_p = oc2->InvTransform()*p;

  switch(op){
  case 0:
    //União
    if(oc1->IsInside(p1_p) || oc2->IsInside(p2_p)){
      return true;
    }
    break;
  case 1:
    //Interseção
    if(oc1->IsInside(p1_p) && oc2->IsInside(p2_p)){
      return true;
    }
    break;
  case 2:
    //Diferença
    if(oc1->IsInside(p1_p) && !oc2->IsInside(p2_p)){
      return true;
    }
    break;
  }
  return false;
}
