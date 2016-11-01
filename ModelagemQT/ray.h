#ifndef RAY_H
#define RAY_H

#include <QRgb>
#include <QVector3D>

class HitInfo{
public:
  HitInfo();
  bool hit;
  float t;
  QRgb color;
};

class Ray
{
public:
  Ray(const QVector3D &p, const QVector3D &d);

  QVector3D p;
  QVector3D d;
};

#endif // RAY_H
