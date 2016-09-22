#include "octreebox.h"

OctreeBox::OctreeBox(float w, float h, float d, const QVector3D &center)
    : w(w), h(h), d(d), center(center) {
}

bool OctreeBox::ConditionInside(const QVector3D &p) {
  QVector3D cp = p - center;
  if (cp.x() <= (w / 2) && cp.x() >= (-w / 2)) {
    if (cp.y() <= (h / 2) && cp.y() >= (-h / 2)) {
      if (cp.z() <= (d / 2) && cp.z() >= (-d / 2)) {
        return true;
      }
    }
  }
  return false;
}
