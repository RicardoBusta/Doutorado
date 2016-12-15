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

  void CreateBox(float w, float h, float d);
  void CreatePyramid(float r, float h, int s);
  void CreateSphere(float r);
  void CreatePrysm(float r, float h, int s);
  void CreateTorus(float r1, float r2);

  void CreatePolyBase(float r, float y, int s);


  int selected_edge;

private:
//  void MakeTriangle(const QVector3D &v0, const QVector3D &v1, const QVector3D &v2);
  //void MVFS(const QString &vk, const QVector3D &v);
  void MVFS_MEV(const QVector3D &nv1, const QVector3D &nv2);
  void MEV(int e1, int e2, const QVector3D &p);
  void MEV(int e, const QVector3D &p);
  void MEF(int e1, int e2);

  void ExtrudeFace(int face, const QVector3D &direction);

  void DrawFace(int face) const;
  //void
};

#endif // HALFEDGEOBJECT_H
