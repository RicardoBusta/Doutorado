#ifndef OCTREE_H
#define OCTREE_H

#include <QRgb>
#include <QVector3D>

#include "object/object.h"
#include "octreenode.h"

class Octree : public Object {
public:
  Octree(QString name, OctreeNode *root, QRgb line_color, QRgb fill_color);
  ~Octree();

  void Draw() const;

  void GenSphere(float radius, const QVector3D &center, int max_depth);
  void GenCylinder(float radius, float height, const QVector3D &center, int max_depth);
  void GenCone(float radius, float height, const QVector3D &center, int max_depth);
  void GenBox(float w, float h, float d, const QVector3D &center, int max_depth);
  void GenTorus(float r1, float r2, const QVector3D &center, int max_depth);
  void GenPrism(float r, float h, float s,QVector3D &center, int max_depth);
  void GenPyramid(float r, float h, float s,QVector3D &center, int max_depth);
  void UpdateP();

  void SetP(const QVector3D &p1, const QVector3D &p2);

  void SetSpread(float spread);

  void UpdateSpecific();

  QString SaveSpecific();
  QString SaveRec();
  QString ObjectType();

  QVector3D bb1, bb2;

  Octree * Duplicate();

  bool IsInside(const QVector3D &p) const;
private:
  float spread;
  QRgb line_color;
  QRgb fill_color;
  QVector3D p1, p2;
  OctreeNode *root;
};

#endif // OCTREE_H
