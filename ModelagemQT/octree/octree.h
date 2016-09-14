#ifndef OCTREE_H
#define OCTREE_H

#include <QRgb>
#include <QVector3D>

#include "object/object.h"
#include "octreenode.h"

class Octree : public Object {
public:
  Octree(OctreeNode *root, QRgb line_color, QRgb fill_color);
  ~Octree();

  void Draw() const;

  void GenSphere(float radius, const QVector3D &center, int max_depth);
  void UpdateP();

  void SetSpread(float spread);
private:
  float spread;
  QRgb line_color;
  QRgb fill_color;
  OctreeNode *root;

  OctreeNode* GenSphereRec(float radius, const QVector3D &center, int max_depth, int depth, const QVector3D &p1, const QVector3D &p2);
};

#endif // OCTREE_H
