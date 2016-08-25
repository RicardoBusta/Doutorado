#ifndef OCTREE_H
#define OCTREE_H

#include <QVector3D>

class OctreeNode{
public:
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2) = 0;
};

class OctreeFull : public OctreeNode {
public:
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2);
};

class OctreeEmpty : public OctreeNode {
public:
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2);
};

class OctreePartial : public OctreeNode {
public:
  OctreePartial();
  virtual ~OctreePartial();
  virtual void DrawRec(const QVector3D &p1, const QVector3D &p2);
public:
  OctreeNode * nodes[8];
};

class Octree {
public:
  Octree(OctreeNode * root);
  ~Octree();

  void Draw(float spread);

private:
  OctreeNode * root;
};

#endif // OCTREE_H
