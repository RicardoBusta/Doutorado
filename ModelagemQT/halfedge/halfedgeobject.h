#ifndef HALFEDGEOBJECT_H
#define HALFEDGEOBJECT_H

#include "object/object.h"
#include <QVector>

class HalfEdge {
public:
  HalfEdge();
  int Sv;
  int Ev;
  int mate;
  int next;
  int face;
};

class HalfEdgeObject : public Object
{
public:
  HalfEdgeObject();

  QVector<HalfEdge> edges;
  int edgeCount;
  QVector<QVector3D> vertices;
  int verticeCount;
  QVector<int> faces;
  int faceCount;

  void Draw() const;

  void CreateCube();

  int selected_face;
  int selected_edge;

private:
//  void MakeTriangle(const QVector3D &v0, const QVector3D &v1, const QVector3D &v2);
  //void MVFS(const QString &vk, const QVector3D &v);
  void MVFS_MEV(const QVector3D &nv1, const QVector3D &nv2);
  void MEV(int e1, int e2, const QVector3D &p);
  void MEV(int e, const QVector3D &p);
  void MEF(int e1, int e2);

  void DrawFace(int face) const;
  //void
};

#endif // HALFEDGEOBJECT_H
