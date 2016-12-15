#include "halfedgeobject.h"

#include <QtOpenGL>
#include "commondefs.h"
#include <QDebug>

// inspired by http://www.cs.utah.edu/~xchen/euler-doc/

HalfEdge::HalfEdge()
  :Sv(-1),Ev(-1),next(-1),mate(-1){}

HalfEdgeObject::HalfEdgeObject()
  : selected_edge(-1),
    selected_face(-1)
{
  edgeCount = 0;
  faceCount = 0;
  verticeCount = 0;
  edges.resize(100);
  faces.resize(100);
  vertices.resize(100);
}

void HalfEdgeObject::Draw() const
{
  if(hide){
    return;
  }

  glColor3f(1,0,0);
  glPointSize(2);
  glBegin(GL_POINTS);
  for(int i=0;i<verticeCount;i++){
    GLVERTEX3D(vertices[i]);
  }
  glEnd();


  glLineWidth(1);
  glBegin(GL_LINES);
  for(int i=0;i<edgeCount;i++){
    glColor3f(1,1,0);
    GLVERTEX3D(vertices[edges[i].Sv]);
    GLVERTEX3D(vertices[edges[i].Ev]);
  }
  glEnd();
  if(selected_edge>=0 && selected_edge<edgeCount){
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    GLVERTEX3D(vertices[edges[selected_edge].Sv]);
    glColor3f(0,1,0);
    GLVERTEX3D(vertices[edges[selected_edge].Ev]);
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    GLVERTEX3D(vertices[edges[selected_edge].Sv]);
    glColor3f(0,1,0);
    GLVERTEX3D(vertices[edges[selected_edge].Ev]);
    glEnd();
  }

  for(int i=0; i<faceCount;i++){
    if(i==selected_face){
      glColor3f(1,0,0);
    }else{
      glColor3f(0,0,1);
    }
    DrawFace(faces[i]);
  }
}

void HalfEdgeObject::CreateCube()
{
  MVFS_MEV(QVector3D(-1,-1,-1),QVector3D(-1,-1,1));
  MEV(1,QVector3D(-1,1,1));
  MEV(2,QVector3D(-1,1,-1));
  qDebug() << "FINISH?";
//  //MEV(6,QVector3D(1,1,-1));
//  MEF(0,4);
  //  MakeTriangle(
  //        QVector3D(-1,-1,-1),
  //        QVector3D(-1,-1,1),
  //        QVector3D(-1,1,1)
  //        );
}

// MVFS + MEV
void HalfEdgeObject::MVFS_MEV(const QVector3D &nv1, const QVector3D &nv2)
{
  qDebug() << "MVFS";
  qDebug() << "MEV";
  int v1 = verticeCount++;
  vertices[v1] = nv1;
  int v2 = verticeCount++;
  vertices[v2] = nv2;

  int e1 = edgeCount++;
  int e2 = edgeCount++;

  int f = faceCount++;
  faces[f] = e1;

  edges[e1].Sv = v1;
  edges[e1].Ev = v2;
  edges[e1].face = f;
  edges[e1].mate = e2;
  edges[e1].next = e2;

  edges[e2].Sv = v2;
  edges[e2].Ev = v1;
  edges[e2].face = f;
  edges[e2].mate = e1;
  edges[e2].next = e1;
}

void HalfEdgeObject::MEV(int e1, int e2, const QVector3D &p)
{
  qDebug() << "MEV";
  // Achar o começo
  int v = edges[e1].Sv;
  int nv = verticeCount++;
  vertices[nv] = p;

  int ne1 = edgeCount++;
  int ne2 = edgeCount++;

  // Criar edges novas
  edges[ne1].Sv = nv;
  edges[ne1].Ev = v;
  edges[ne1].face = edges[e1].face;
  edges[ne1].mate = ne2;
  edges[ne1].next = e1;

  edges[ne2].Sv = v;
  edges[ne2].Ev = nv;
  edges[ne2].face = edges[e2].face;
  edges[ne2].mate = ne1;
  edges[ne2].next = e2; // pode mudar se e1!=e2

  // Atualizar estrutura
  int e = e2;
  int prev1 = ne2;
  while(e!=e1){
    prev1 = edges[e].mate;
    edges[e].Sv = nv;
    edges[edges[e].mate].Ev = nv;
    e = edges[edges[e].mate].next;
  }
  edges[prev1].next = ne1; // Se e1==e2 então ne2.next = ne1.

  e = e1;
  int prev2 = edges[e1].mate;
  while(e!=e2){
    prev2 = edges[e].mate;
    e = edges[edges[e].mate].next;
  }
  edges[prev2].next = ne2;
}

void HalfEdgeObject::MEV(int e, const QVector3D &p)
{
  MEV(e,e,p);
}

void HalfEdgeObject::MEF(int e1, int e2) {
  //  int ne1 = edges.size();
  //  edges.resize(edges.size()+1);
  //  edges.push_back(HalfEdge());
  //  int ne2 = edges.size();
  //  edges.push_back(HalfEdge());

  //  int v1 = edges[e1].Sv;
  //  int v2 = edges[e2].Sv;

  //  int f = edges[e1].face;

  //  int nf = faces.size();
  //  faces.push_back(ne2);

  //  // Criar edges novas
  //  edges[ne1].Sv = v2;
  //  edges[ne1].Ev = v1;
  //  edges[ne1].face = f;
  //  edges[ne1].mate = ne2;
  //  edges[ne1].next = e1;

  //  edges[ne2].Sv = v1;
  //  edges[ne2].Ev = v2;
  //  edges[ne2].face = nf;
  //  edges[ne2].mate = ne1;
  //  edges[ne2].next = e2;

  // update face2 loop
  //  int e = e2;
  //  while(edges[e].next!=e1){
  //    edges[e].face = nf;
  //    e = edges[e].next;
  //  }
  //  edges[e].next = ne2;
  //  e = e1;
  //  while(edges[e].next!=e2){
  //    e = edges[e].next;
  //  }
  //  edges[e].next = ne1;
}

void HalfEdgeObject::DrawFace(int face) const{
  int edge = edges[faces[face]].next;
  glBegin(GL_TRIANGLES);
  GLVERTEX3D( vertices[edges[faces[face]].Ev]);
  while(edge!=faces[face]){
    GLVERTEX3D(vertices[edges[edge].Ev]);
    edge = edges[edge].next;
  }
  glEnd();
}
