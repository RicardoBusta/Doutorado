#include "octree.h"

#include <QtOpenGL>

#include "octreesphere.h"
#include "octreecylinder.h"

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
  bool draw_lines = false;
  if (root != nullptr) {
    root->DrawRec(spread, line_color, fill_color, draw_lines);
  }
}

void Octree::GenSphere(float radius, const QVector3D &center, int max_depth) {
  OctreeSphere sphereGen(radius,center);
  QVector3D p1 = kP1 * radius;
  QVector3D p2 = kP2 * radius;
  root = sphereGen.GenRec(max_depth,0,p1,p2);
}

void Octree::GenCylinder(float radius, float height, const QVector3D &center, int max_depth)
{
  OctreeCylinder gen(radius,height,center);
  float bb = qMax(radius,height/2.0f);
  QVector3D p1 = kP1 * bb;
  QVector3D p2 = kP2 * bb;
  root = gen.GenRec(max_depth,0,p1,p2);
}

void Octree::UpdateP() {
  root->UpdatePRec(kP1, kP2);
}

void Octree::SetSpread(float spread) {
  this->spread = spread;
}
