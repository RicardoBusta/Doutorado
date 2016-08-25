#ifndef OCTREE_H
#define OCTREE_H

#include <QVector3D>
#include <QRgb>

class OctreeNode{
public:
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2, const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const = 0;
    void DrawBox(const QVector3D &p1, const QVector3D &p2) const;
};

class OctreeFull : public OctreeNode {
public:
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2, const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
};

class OctreeEmpty : public OctreeNode {
public:
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2, const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
};

class OctreePartial : public OctreeNode {
public:
  OctreePartial();
  virtual ~OctreePartial();
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2, const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
public:
  OctreeNode * nodes[8];
};

class Octree {
public:
  Octree(OctreeNode * root, QRgb line_color, QRgb fill_color);
  ~Octree();

  void Draw(float spread, bool draw_lines) const;

  void GenSphere(float radius, const QVector3D &center, int max_depth);
private:
  QRgb line_color;
  QRgb fill_color;
  OctreeNode * root;
};

#endif // OCTREE_H
