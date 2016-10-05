#include "octreetorus.h"

OctreeTorus::OctreeTorus(float r1, float r2, const QVector3D &center)
  :r1(r1),r2(r2),center(center)
{

}

bool OctreeTorus::ConditionInside(const QVector3D &p)
{
  QVector3D vxz = center-p;
  float distance_y = qAbs(vxz.y());
  if(distance_y<=r2){
    vxz.setY(0);
    float distance_xz = vxz.length();
    if(distance_xz <= r1+r2 && distance_xz >= r1-r2){
      float dist_r = sqrt(r2*r2 - distance_y*distance_y);
      if(distance_xz <= r1+dist_r && distance_xz >= r1-dist_r){
        return true;
      }
    }
  }
  return false;
}

