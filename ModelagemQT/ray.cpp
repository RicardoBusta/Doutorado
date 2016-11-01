#include "ray.h"

Ray::Ray(const QVector3D &p, const QVector3D &d)
  :p(p),d(d)
{

}

HitInfo::HitInfo()
  :hit(false),
    t(999999),
    color(0xff000000)
{

}
