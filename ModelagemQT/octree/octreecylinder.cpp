#include "octreecylinder.h"

OctreeCylinder::OctreeCylinder(float radius, float height, const QVector3D &center)
    : OctreeShape(),
      radius(radius),
      height(height),
      center(center) {
}

bool OctreeCylinder::ConditionInside(const QVector3D &p) {
  QVector3D cp = p-center;
  if(cp.y()<=height/2.0f && cp.y()>=-height/2.0f){
    if(cp.x()*cp.x()+cp.z()*cp.z() <= radius*radius){
      return true;
    }
  }
  return false;
}
