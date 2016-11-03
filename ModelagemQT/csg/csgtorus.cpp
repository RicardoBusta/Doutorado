#include "csgtorus.h"

CSGTorus::CSGTorus(float r1, float r2)
  : CSGObject(),
    r1(r1),
    r2(r2)
{
  Rename("CSG Torus");
  float side = r1+r2;
  bb1 = QVector3D(-side,-side,-side);
  bb2 = QVector3D(side,side,side);
}

HitInfo CSGTorus::RayCast(const Ray &r, const HitInfo &hitinfo)
{
  return hitinfo;
}

bool CSGTorus::ConditionInside(const QVector3D &p) const
{
  QVector3D vxz = p;
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
