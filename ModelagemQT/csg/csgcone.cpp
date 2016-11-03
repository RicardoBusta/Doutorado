#include "csgcone.h"

CSGCone::CSGCone(float radius, float height)
  :CSGObject(),
    radius(radius),
    height(height)
{
  Rename("CSG Cone");
  float side = qMax(height/2,radius);
  bb1 = QVector3D(-side,-side,-side);
  bb2 = QVector3D(side,side,side);
}

HitInfo CSGCone::RayCast(const Ray &r, const HitInfo &hitinfo)
{
  return hitinfo;
}

bool CSGCone::ConditionInside(const QVector3D &p) const
{
  QVector3D cp = p;
  float h = height/2.0f;
  if (cp.y() <= h && cp.y() >= -h) {
    float r = radius*(((cp.y()-h)/(height)));
    if (cp.x() * cp.x() + cp.z() * cp.z() <= r * r) {
      return true;
    }
  }
  return false;
}
