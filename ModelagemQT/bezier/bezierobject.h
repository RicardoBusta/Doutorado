#ifndef BEZIEROBJECT_H
#define BEZIEROBJECT_H

#include "object/object.h"

class BezierObject : public Object
{
public:
  BezierObject(int x, int y);

  QVector< QVector<QVector3D> > control_points;
  QVector< QVector<QVector3D> > points;
  QVector< QVector<QVector3D> > normals;

  int slices;

  int current_cp_x;
  int current_cp_y;

  void Draw() const;

  void Calc();

  QVector3D BezierPoint(float x, float y) const;
  QVector3D BezierNormal(float x, float y) const;
  float B(int n, int i, float u)const;
  float Bx(int n, int i, float u)const;
  float Bin(int n, int i) const;
  float Fat(int n)const;
};

#endif // BEZIEROBJECT_H
