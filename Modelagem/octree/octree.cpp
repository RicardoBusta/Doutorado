#include "octree.h"

#include <QtOpenGL>

Octree::Octree(OctreeNode *root) : root(root) {
}

Octree::~Octree() {
  delete root;
}

void Octree::Draw(float spread) {
  if (root != nullptr) {
    root->DrawRec(QVector3D(-1, 1, 1), QVector3D(1, -1, -1));
  }
}

void OctreeFull::DrawRec(const QVector3D &p1, const QVector3D &p2) {
  glBegin(GL_QUADS);
  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());

  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p2.z());

  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p1.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glEnd();
}

void OctreeEmpty::DrawRec(const QVector3D &p1, const QVector3D &p2) {
  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glBegin(GL_QUADS);
  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());

  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p2.z());

  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p1.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glEnd();

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
}

OctreePartial::OctreePartial() {
  for(int i=0;i<8;i++){
    nodes[i] = nullptr;
  }
}

OctreePartial::~OctreePartial() {
}

void OctreePartial::DrawRec(const QVector3D &p1, const QVector3D &p2) {
  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glBegin(GL_QUADS);
  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());

  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p2.z());

  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p1.z());

  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glEnd();

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }

  QVector3D p3 = (p1 + p2) / 2;
  nodes[0]->DrawRec(p1, p3);
  nodes[1]->DrawRec(p3, p2);
}
