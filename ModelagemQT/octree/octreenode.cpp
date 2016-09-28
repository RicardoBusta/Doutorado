#include "octreenode.h"

#include <QtOpenGL>

#include "commondefs.h"

void OctreeFull::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  glPushMatrix();
  if (spread > 0) {
    QVector3D center = (p1 + p2) / 2;
    center.normalize();
    center *= spread;
    glTranslatef(center.x(), center.y(), center.z());
  }
  glColor3ub(UB_COLOR(fill));
  DrawBox(true);

    if (!draw_lines) {
      glPopMatrix();
      return;
    }
  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox(false);

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
  glPopMatrix();
}

OctreeType OctreeFull::GetType() {
  return OctreeType::Full;
}

void OctreeEmpty::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  if (!draw_lines) {
    return;
  }
  glPushMatrix();
  if (spread > 0) {
    QVector3D center = (p1 + p2) / 2;
    center.normalize();
    center *= spread;
    glTranslatef(center.x(), center.y(), center.z());
  }
  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox(false);

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
  glPopMatrix();
}

OctreeType OctreeEmpty::GetType() {
  return OctreeType::Empty;
}

OctreePartial::OctreePartial() {
  for (int i = 0; i < 8; i++) {
    nodes[i] = nullptr;
  }
}

OctreePartial::~OctreePartial() {
  for (int i = 0; i < 8; i++) {
    if (nodes[i] != nullptr) {
      delete nodes[i];
    }
  }
}

void OctreePartial::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
  p1 = np1;
  p2 = np2;
  QVector3D p3 = (np1 + np2) / 2;
  float shift = p3.x() - p1.x();

  for (int i = 0; i < 8; i++) {
    QVector3D slide = shift * kOctreeCoords[i];
    nodes[i]->UpdatePRec(p1 + slide, p3 + slide);
  }
}

OctreeType OctreePartial::GetType() {
  return OctreeType::Partial;
}

void OctreePartial::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  //QRgb color[] = {0xff0000, 0xffff00, 0xffffff, 0x00ff00, 0x00ffff, 0x0000ff, 0xff00ff, 0x000000};
  for (int i = 0; i < 8; i++) {
    nodes[i]->DrawRec(spread, line, /*color[i]*/ fill, draw_lines);
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
  DrawBox(false);

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

void OctreeNode::DrawBox(bool lighting) const {
  if (lighting) {
    glEnable(GL_LIGHTING);
  }
  glBegin(GL_QUADS);
  glNormal3f(0, 0, 1);
  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());

  glNormal3f(0, 0, -1);
  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());

  glNormal3f(0, 1, 0);
  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p1.y(), p2.z());

  glNormal3f(0, -1, 0);
  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p1.z());
  glVertex3f(p1.x(), p2.y(), p2.z());

  glNormal3f(-1, 0, 0);
  glVertex3f(p1.x(), p1.y(), p1.z());
  glVertex3f(p1.x(), p1.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p2.z());
  glVertex3f(p1.x(), p2.y(), p1.z());

  glNormal3f(1, 0, 0);
  glVertex3f(p2.x(), p2.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p2.z());
  glVertex3f(p2.x(), p1.y(), p1.z());
  glVertex3f(p2.x(), p2.y(), p1.z());
  glEnd();
  if (lighting) {
    glDisable(GL_LIGHTING);
  }
}
