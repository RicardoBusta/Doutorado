#include "csgsphere.h"

#include <QtOpenGL>
#include <QDebug>

CSGSphere::CSGSphere(float radius)
  : CSGObject(),
    radius(radius)
{
  Rename("CSG Sphere");
bb1 = QVector3D(-radius,-radius,-radius);
bb2 = QVector3D(radius,radius,radius);
}

HitInfo CSGSphere::RayCast(const Ray &r, const HitInfo &hitinfo)
{
  QVector3D center = Transform()*QVector3D(0,0,0);
  float dist = center.distanceToLine(r.o,r.d.normalized());
  qDebug() << dist << radius << r.o << r.d << center;
  if(dist < radius){
    HitInfo hit;
    hit.color = 0xffffffff;
    hit.t=1;
    hit.hit = true;
    return hit;
  }
  return hitinfo;
}

bool CSGSphere::ConditionInside(const QVector3D &p) const
{
  QVector3D cp = p;
  return QVector3D::dotProduct(cp, cp) <= (radius * radius);
}
