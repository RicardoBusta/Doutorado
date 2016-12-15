#include "halfedgeobject.h"

#include <QtOpenGL>
#include "commondefs.h"
#include <QDebug>

// inspired by http://www.cs.utah.edu/~xchen/euler-doc/

HalfEdge::HalfEdge()
  :Sv(-1),Ev(-1),next(-1),mate(-1){}

HalfEdgeObject::HalfEdgeObject()
  : selected_edge(-1)
{
  edgeCount = 0;
  faceCount = 0;
  verticeCount = 0;
  edges.resize(600);
  faces.resize(600);
  vertices.resize(600);
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

  for(int i=0;i<edgeCount;i++){
    if(i==selected_edge){
      glLineWidth(5);
      glBegin(GL_LINES);
      glColor3f(0,1,0);
      GLVERTEX3D(vertices[edges[selected_edge].Sv]);
      glColor3f(1,0,0);
      GLVERTEX3D(vertices[edges[selected_edge].Ev]);
      glEnd();

      glPointSize(10);
      glBegin(GL_POINTS);
      glColor3f(0,1,0);
      GLVERTEX3D(vertices[edges[selected_edge].Sv]);
      glColor3f(1,0,0);
      GLVERTEX3D(vertices[edges[selected_edge].Ev]);
      glEnd();
    }else{
      glColor3f(1,1,0);
      glLineWidth(1);
      glBegin(GL_LINES);
      GLVERTEX3D(vertices[edges[i].Sv]);
      GLVERTEX3D(vertices[edges[i].Ev]);
      glEnd();
    }
  }

  for(int i=0; i<faceCount;i++){
    //qDebug() << "face" << i;
    if(selected_edge>=0 && selected_edge<edgeCount && i==edges[selected_edge].face){
      glColor3f(0,0.8f,1);
    }else{
      glColor3f(0,0,0.8f);
    }
    DrawFace(i);
  }
}

void HalfEdgeObject::CreateBox(float w, float h, float d)
{
  MVFS_MEV(QVector3D(-w/2,-h/2,-d/2),QVector3D(-w/2,-h/2,d/2));
  MEV(0,QVector3D(w/2,-h/2,d/2));
  MEV(2,QVector3D(w/2,-h/2,-d/2));
  MEF(1,4);

  //qDebug() << "FINISH?";

  //MEV(1,QVector3D(-1,1,-1));
  ExtrudeFace(0,QVector3D(0,d,0));
}

void HalfEdgeObject::CreatePyramid(float r, float h, int s) {

}

void HalfEdgeObject::CreateSphere(float r) {

}

void HalfEdgeObject::CreatePrysm(float r, float h, int s) {
  Rename("HE Prysm");
  CreatePolyBase(r,-h/2,s);

  // Make extrusion
  ExtrudeFace(1,QVector3D(0,h,0));
}

void HalfEdgeObject::CreateTorus(float r1, float r2)
{

}

void HalfEdgeObject::CreatePolyBase(float r, float y, int s)
{
  float angle = 2*M_PI;
  float a0 = 0/float(s);
  float a1 = angle/float(s);
  MVFS_MEV(QVector3D(r*cos(a0),y,r*sin(a0)),QVector3D(r*cos(a1),y,r*sin(a1)));
  for(int i=2;i<s;i++){
    float a = float(i)/float(s);
    a = a*angle;
    MEV(edgeCount-2,QVector3D(r*cos(a),y,r*sin(a)));
  }
  MEF(1,edgeCount-2);
}

// MVFS + MEV
void HalfEdgeObject::MVFS_MEV(const QVector3D &nv1, const QVector3D &nv2)
{
  int v1 = verticeCount++;
  vertices[v1] = nv1;
  int v2 = verticeCount++;
  vertices[v2] = nv2;

  int e2 = edgeCount++;
  int e1 = edgeCount++;

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

  if(e1==e2){
    int e = e1;
    while(edges[e].next!=e1){
      e = edges[e].next;
    }
    edges[e].next = ne2;
  }else{
    e = e1;
    int prev2 = edges[e1].mate;
    while(e!=e2){
      prev2 = edges[e].mate;
      e = edges[edges[e].mate].next;
    }
    edges[prev2].next = ne2;
  }
}

void HalfEdgeObject::MEV(int e, const QVector3D &p)
{
  MEV(e,e,p);
}

void HalfEdgeObject::MEF(int e1, int e2) {
  int ne1 = edgeCount++;
  int ne2 = edgeCount++;

  int v1 = edges[e1].Sv;
  int v2 = edges[e2].Sv;

  int f = edges[e1].face;
  faces[f] = e1;

  int nf = faceCount++;
  faces[nf] = ne2;

  // Criar edges novas
  edges[ne1].Sv = v2;
  edges[ne1].Ev = v1;
  edges[ne1].face = f;
  edges[ne1].mate = ne2;
  edges[ne1].next = e1;

  edges[ne2].Sv = v1;
  edges[ne2].Ev = v2;
  edges[ne2].face = nf;
  edges[ne2].mate = ne1;
  edges[ne2].next = e2;

  //update face2 loop
  int e = e2;
  while(edges[e].next!=e1){
    edges[e].face = edges[ne2].face;
    e = edges[e].next;
  }
  edges[e].next = ne2;
  edges[e].face = nf;
  e = e1;
  while(edges[e].next!=e2){
    edges[e].face = edges[ne1].face;
    e = edges[e].next;
  }
  edges[e].next = ne1;
}

void HalfEdgeObject::ExtrudeFace(int face, const QVector3D &direction)
{
  int e0 = faces[face];

  MEV(e0,vertices[edges[e0].Sv]+direction);
  int e = edges[e0].next;
  int startEC = edgeCount-2;
  int endEC = startEC;
  while(edges[edges[e].next].next!=e0){
    MEV(e,vertices[edges[e].Sv]+direction);
    qDebug() <<  edgeCount-4 << edgeCount-2;
    endEC = edgeCount-2;
    e = edges[e].next;
  }
  qDebug() << startEC << endEC;

  for(int i=startEC;i<endEC;i+=2){
    MEF(i,i+2);
  }

  MEF(endEC,endEC+3);
  //  MEF(40,42);
  //  MEF(42,44);
  //  MEF(44,46);
  //  MEF(78,80);

  //  for(int i=0;i<faceCount;i++){
  //    qDebug() << i << faces[i];
  //  }
  //  MEF(10,8);
  //  MEF(12,10);
  //  MEF(17,12);
}

void HalfEdgeObject::DrawFace(int face) const{
  int edge = edges[faces[face]].next;
  glBegin(GL_TRIANGLE_FAN);
  //qDebug() << faces[face];
  GLVERTEX3D( vertices[edges[faces[face]].Ev]);
  while(edge!=faces[face]){
    //qDebug() << edge << edges[edge].face;
    GLVERTEX3D(vertices[edges[edge].Ev]);
    edge = edges[edge].next;
  }
  glEnd();
}
