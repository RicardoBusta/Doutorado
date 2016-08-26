#include "octree.h"

#include <QtOpenGL>

#define UB_COLOR(color) qRed(color),qGreen(color),qBlue(color)

const QVector3D kP1(-1,1,1);
const QVector3D kP2(1,-1,-1);

Octree::Octree(OctreeNode *root, QRgb line_color, QRgb fill_color)
    : root(root), line_color(line_color),fill_color(fill_color){
}

Octree::~Octree() {
  delete root;
}

void Octree::Draw(const float spread, bool draw_lines) const {
  if (root != nullptr) {
    root->DrawRec(kP1,kP2,spread,line_color,fill_color,draw_lines);
  }
}

void Octree::GenSphere(float radius, const QVector3D &center, int max_depth)
{
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

void OctreeFull::DrawRec(const QVector3D &p1, const QVector3D &p2, const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
    glPushMatrix();
    if(spread>0){
        QVector3D center = (p1+p2)/2;
        center.normalize();
        center *= spread;
        glTranslatef(center.x(),center.y(),center.z());
    }
    glColor3ub(UB_COLOR(fill));
    DrawBox(p1,p2);
    glPopMatrix();
}

void OctreeEmpty::DrawRec(const QVector3D &p1, const QVector3D &p2, const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  if(!draw_lines){
   return;
  }
  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox(p1,p2);

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

void OctreePartial::DrawRec(const QVector3D &p1, const QVector3D &p2, const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const{
  QVector3D p3 = (p1 + p2) / 2;
  nodes[0]->DrawRec(p1, p3,spread,line,fill,draw_lines);
  nodes[1]->DrawRec(p3, p2,spread,line,fill,draw_lines);

  if(!draw_lines){
   return;
  }

  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox(p1,p2);

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
}

void OctreeNode::DrawBox(const QVector3D &p1, const QVector3D &p2) const
{
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
