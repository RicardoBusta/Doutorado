#include "csgbox.h"

CSGBox::CSGBox(float w, float h, float d)
  : CSGObject(),
    w(w),
    h(h),
    d(d)
{
  Rename("CSG Box");
  float side = qMax(w,qMax(h,d));
  bb1 = QVector3D(-side,-side,-side);
  bb2 = QVector3D(side,side,side);
}

HitInfo CSGBox::RayCast(const Ray &r, const HitInfo &hitinfo)
{
 return hitinfo;
}

bool CSGBox::ConditionInside(const QVector3D &p) const
{
  QVector3D cp = p;
  if (cp.x() <= (w / 2) && cp.x() >= (-w / 2)) {
    if (cp.y() <= (h / 2) && cp.y() >= (-h / 2)) {
      if (cp.z() <= (d / 2) && cp.z() >= (-d / 2)) {
        return true;
      }
    }
  }
  return false;
}
