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
  void GenText(const QString &text);
//  OctreeNode * GenTextRec(const QString &text, const int index_start, int *index_end);

  void UpdateP();

  void SetP(const QVector3D &p1, const QVector3D &p2);

  void SetSpread(float spread);

  void UpdateSpecific();

  QString SaveSpecific();
  QString ObjectType();

  QVector3D bb1, bb2;

  Object *Duplicate();

  bool IsInside(const QVector3D &p) const;

  HitInfo RayCast(const Ray &ray, const HitInfo &hitinfo);
private:
  float spread;
  QVector3D p1, p2;
  OctreeNode *root;
};

#endif // OCTREE_H
