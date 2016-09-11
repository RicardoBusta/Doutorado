#include "octree.h"

#include <QtOpenGL>

#define UB_COLOR(color) qRed(color), qGreen(color), qBlue(color)

const QVector3D kP1(-1, 1, 1);
const QVector3D kP2(1, -1, -1);

static int count = 0;

Octree::Octree(OctreeNode *root, QRgb line_color, QRgb fill_color)
    : Object(), root(root), line_color(line_color), fill_color(fill_color) {
  name = QString("Octree %1").arg(count++);
}

Octree::~Octree() {
  delete root;
}

void Octree::Draw() const {
  bool draw_lines = true;
  float spread = 0;
  if (root != nullptr) {
    root->DrawRec(spread, line_color, fill_color, draw_lines);
  }
}

void Octree::GenSphere(float radius, const QVector3D &center, int max_depth) {
  /*    int side = pow(2,max_depth);
    bool * matrix = new bool[side*side*side];
    for(int i=0;i<side;i++){
        float fi = (2*(float)i/(side-1))-1;
        for(int j=0;j<side;j++){
            float fj = (2*(float)j/(side-1))-1;
            for(int k=0;k<side;k++){
                float fj = (2*(float)j/(side-1))-1;
            }
        }
    }
    delete[] matrix;*/
}

void Octree::GenSphereRec(float radius, const QVector3D &center, int max_depth, int depth) {
  OctreeNode *node;
  if (depth == max_depth) {
    node = new OctreeFull();
    node = new OctreeEmpty();
  } else {
    node = new OctreePartial();
  }
}

void Octree::UpdateP() {
  root->UpdatePRec(kP1, kP2);
}

void OctreeFull::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  glPushMatrix();
  if (spread > 0) {
    QVector3D center = (p1 + p2) / 2;
    center.normalize();
    center *= spread;
    glTranslatef(center.x(), center.y(), center.z());
  }
  glColor3ub(UB_COLOR(fill));
  DrawBox();
  glPopMatrix();
}

void OctreeEmpty::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  if (!draw_lines) {
    return;
  }
  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox();

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
}

OctreePartial::OctreePartial() {
  for (int i = 0; i < 8; i++) {
    nodes[i] = nullptr;
  }
}

OctreePartial::~OctreePartial() {
}

void OctreePartial::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
  p1 = np1;
  p2 = np2;
  QVector3D p3 = (np1 + np2) / 2;
  QVector3D shift = p2 - p3;

  QVector3D s1 = QVector3D(shift.x(), 0, 0);
  QVector3D s2 = QVector3D(0, shift.y(), 0);
  QVector3D s3 = QVector3D(0, 0, shift.z());

  nodes[0]->UpdatePRec(p3-s3, p2-s3);
  nodes[1]->UpdatePRec(p3, p2);
  nodes[2]->UpdatePRec(p3-s1, p2-s1);
  nodes[3]->UpdatePRec(p1 + s2, p3 + s2);
  nodes[4]->UpdatePRec(p1 + s1, p3 + s1);
  nodes[5]->UpdatePRec(p3-s2, p2-s2);
  nodes[6]->UpdatePRec(p1 + s3, p3 + s3);
  nodes[7]->UpdatePRec(p1, p3);
}

void OctreePartial::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  //QRgb color[] = {0xff0000, 0xffff00, 0xffffff, 0x00ff00, 0x00ffff, 0x0000ff, 0xff00ff, 0x000000};
  for (int i = 0; i < 8; i++) {
    nodes[i]->DrawRec(spread, line, /*color[i]*/fill, draw_lines);
  }

  if (!draw_lines) {
    return;
  }

  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox();

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
}

void OctreeNode::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
  p1 = np1;
  p2 = np2;
}

void OctreeNode::DrawBox() const {
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
