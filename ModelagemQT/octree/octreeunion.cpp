#include "octreeunion.h"

#include "octree/octree.h"

OctreeUnion::OctreeUnion(Octree *oc1, Octree *oc2, const QVector3D &p1, const QVector3D &p2)
  :OctreeShape(),oc1(oc1),oc2(oc2),p1(p1),p2(p2)
{
}

bool OctreeUnion::ConditionInside(const QVector3D &p)
{
  QVector3D p1_p = oc1->InvTransform()*p;
  QVector3D p2_p = oc2->InvTransform()*p;

  //qDebug() << p << oc1->Transform()*p;

//  qDebug() << oc1->bb1 << oc2->bb2 << p;
//  qDebug() << p1_p << oc1->bb1 << oc1->bb2;
  if(oc1->IsInside(p1_p) || oc2->IsInside(p2_p)){
//    qDebug() << "true";
    return true;
  }
  return false;

//  return true;
}
