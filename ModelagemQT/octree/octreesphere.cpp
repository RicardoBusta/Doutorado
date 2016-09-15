#include "octreesphere.h"

OctreeSphere::OctreeSphere(float radius, const QVector3D &center)
    : OctreeShape(),
      radius(radius),
      center(center) {
}

bool OctreeSphere::ConditionInside(const QVector3D &p)
{
  QVector3D cp = center - p;
  return QVector3D::dotProduct(cp, cp) <= (radius * radius);
}
