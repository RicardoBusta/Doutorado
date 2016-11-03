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
  Ray(const QVector3D &o, const QVector3D &d);

  QVector3D o;
  QVector3D d;

  Ray Transformed(const QMatrix4x4 &transform) const;
};

#endif // RAY_H
