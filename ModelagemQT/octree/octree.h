#ifndef OCTREE_H
#define OCTREE_H

#include <QRgb>
#include <QVector3D>

#include "object/object.h"

class OctreeNode {
public:
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const = 0;
  virtual void UpdatePRec(const QVector3D &np1, const QVector3D &np2);
  void DrawBox() const;
  QVector3D p1, p2;
};

class OctreeFull : public OctreeNode {
public:
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
};

class OctreeEmpty : public OctreeNode {
public:
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
};

class OctreePartial : public OctreeNode {
public:
  OctreePartial();
  virtual ~OctreePartial();
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
  virtual void UpdatePRec(const QVector3D &np1, const QVector3D &np2);
public:
  OctreeNode *nodes[8];
};

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
