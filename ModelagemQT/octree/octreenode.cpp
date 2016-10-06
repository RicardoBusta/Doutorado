#include "octreenode.h"

#include <QtOpenGL>

#include "commondefs.h"

const QVector3D kP1(-1, 1, 1);
const QVector3D kP2(1, -1, -1);

void OctreeFull::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  glPushMatrix();
  //  if (spread > 0) {
  QVector3D center = (p1 + p2) / 2;
  float scale = qAbs(p1.x()-p2.x())/2*spread;
  glTranslatef(center.x(),center.y(),center.z());
  glScalef(scale,scale,scale);
  //}
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

QString OctreeFull::Save()
{
  return "w";
}

bool OctreeFull::IsInside(const QVector3D &p, int depth) const
{
  return true;
}

OctreeNode *OctreeFull::Copy()
{
  return new OctreeFull();
}

void OctreeEmpty::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  if (!draw_lines) {
    return;
  }
  glPushMatrix();

  QVector3D center = (p1 + p2) / 2;
  float scale = qAbs(p1.x()-p2.x())/2*spread;
  glTranslatef(center.x(),center.y(),center.z());
  glScalef(scale,scale,scale);

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

QString OctreeEmpty::Save()
{
  return "b";
}

bool OctreeEmpty::IsInside(const QVector3D &p, int depth) const
{
  return false;
}

OctreeNode *OctreeEmpty::Copy()
{
  return new OctreeEmpty();
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
  pc = (np1 + np2) / 2;
  float shift = pc.x() - p1.x();

  for (int i = 0; i < 8; i++) {
    QVector3D slide = shift * kOctreeCoords[i];
    nodes[i]->UpdatePRec(p1 + slide, pc + slide);
  }
}

OctreeType OctreePartial::GetType() {
  return OctreeType::Partial;
}

QString OctreePartial::Save()
{
  QString out = "(";
  for(int i=0;i<8;i++){
    out += nodes[i]->Save();
  }
  return out;
}

/*
  2---1
 /|  /|
3-+-0 |
| 6-+-5   y
|/  |/    |_x
7---4   z/
*/
bool OctreePartial::IsInside(const QVector3D &p,int depth) const
{
  //ebug() << depth << pc << p1 << p2;
  if(p.x() > pc.x()){
    //0,1,4,5
    if(p.y()<pc.y()){
      //0,1
      if(p.z()>pc.z()){
        return nodes[0]->IsInside(p,depth+1);
      }else{
        return nodes[1]->IsInside(p,depth+1);
      }
    }else{
      //4,5
      if(p.z()>pc.z()){
        return nodes[4]->IsInside(p,depth+1);
      }else{
        return nodes[5]->IsInside(p,depth+1);
      }
    }
  }else{
    //2,3,6,7
    if(p.y()<pc.y()){
      //2,3
      if(p.z()>pc.z()){
        return nodes[3]->IsInside(p,depth+1);
      }else{
        return nodes[2]->IsInside(p,depth+1);
      }
    }else{
      //6,7
      if(p.z()>pc.z()){
        return nodes[7]->IsInside(p,depth+1);
      }else{
        return nodes[6]->IsInside(p,depth+1);
      }
    }
  }
  return false;
}

OctreeNode *OctreePartial::Copy()
{
  OctreePartial *out = new OctreePartial();

  for(int i=0;i<8;i++){
    out->nodes[i] = nodes[i]->Copy();
  }

  return out;
}

void OctreePartial::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  for (int i = 0; i < 8; i++) {
    nodes[i]->DrawRec(spread, line, /*color[i]*/ fill, draw_lines);
  }
}

void OctreeNode::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
  p1 = np1;
  p2 = np2;
  pc = (p1+p2)/2.0f;
}

void OctreeNode::DrawBox(bool lighting) {
  if (lighting) {
    glEnable(GL_LIGHTING);
  }
  glBegin(GL_QUADS);
  glNormal3f(0, 0, 1);
  glVertex3f(kP1.x(), kP1.y(), kP1.z());
  glVertex3f(kP1.x(), kP2.y(), kP1.z());
  glVertex3f(kP2.x(), kP2.y(), kP1.z());
  glVertex3f(kP2.x(), kP1.y(), kP1.z());

  glNormal3f(0, 0, -1);
  glVertex3f(kP2.x(), kP2.y(), kP2.z());
  glVertex3f(kP1.x(), kP2.y(), kP2.z());
  glVertex3f(kP1.x(), kP1.y(), kP2.z());
  glVertex3f(kP2.x(), kP1.y(), kP2.z());

  glNormal3f(0, 1, 0);
  glVertex3f(kP1.x(), kP1.y(), kP1.z());
  glVertex3f(kP2.x(), kP1.y(), kP1.z());
  glVertex3f(kP2.x(), kP1.y(), kP2.z());
  glVertex3f(kP1.x(), kP1.y(), kP2.z());

  glNormal3f(0, -1, 0);
  glVertex3f(kP2.x(), kP2.y(), kP2.z());
  glVertex3f(kP2.x(), kP2.y(), kP1.z());
  glVertex3f(kP1.x(), kP2.y(), kP1.z());
  glVertex3f(kP1.x(), kP2.y(), kP2.z());

  glNormal3f(-1, 0, 0);
  glVertex3f(kP1.x(), kP1.y(), kP1.z());
  glVertex3f(kP1.x(), kP1.y(), kP2.z());
  glVertex3f(kP1.x(), kP2.y(), kP2.z());
  glVertex3f(kP1.x(), kP2.y(), kP1.z());

  glNormal3f(1, 0, 0);
  glVertex3f(kP2.x(), kP2.y(), kP2.z());
  glVertex3f(kP2.x(), kP1.y(), kP2.z());
  glVertex3f(kP2.x(), kP1.y(), kP1.z());
  glVertex3f(kP2.x(), kP2.y(), kP1.z());
  glEnd();
  if (lighting) {
    glDisable(GL_LIGHTING);
  }
}
