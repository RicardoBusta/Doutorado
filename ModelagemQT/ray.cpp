#include "ray.h"

Ray::Ray(const QVector3D &p, const QVector3D &d)
  :o(p),d(d)
{

}

Ray Ray::Transformed(const QMatrix4x4 &transform) const
{
  Ray out(transform*o,transform*d);
  return out;
}

HitInfo::HitInfo()
  :hit(false),
    t(999999),
    color(0xff000000)
{

}
