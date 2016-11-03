#include "csgcylinder.h"

CSGCylinder::CSGCylinder(float radius, float height)
  :CSGObject(),
  radius(radius),
  height(height)
{
  Rename("CSG Cylinder");
  float side = qMax(height/2,radius);
  bb1 = QVector3D(-side,-side,-side);
  bb2 = QVector3D(side,side,side);
}

HitInfo CSGCylinder::RayCast(const Ray &r, const HitInfo &hitinfo)
{
return hitinfo;
}

bool CSGCylinder::ConditionInside(const QVector3D &p) const
{
  QVector3D cp = p;
  if(cp.y()<=height/2.0f && cp.y()>=-height/2.0f){
    if(cp.x()*cp.x()+cp.z()*cp.z() <= radius*radius){
      return true;
    }
  }
  return false;
}
