#include "octreecone.h"

OctreeCone::OctreeCone(float radius, float height, const QVector3D &center)
    : radius(radius), height(height), center(center) {
}

bool OctreeCone::ConditionInside(const QVector3D &p) {
  QVector3D cp = p - center;
  float h = height/2.0f;
  if (cp.y() <= h && cp.y() >= -h) {
    float r = radius*(((cp.y()-h)/(height)));
    if (cp.x() * cp.x() + cp.z() * cp.z() <= r * r) {
      return true;
    }
  }
  return false;
}
