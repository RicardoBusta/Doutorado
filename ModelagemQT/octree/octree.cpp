#include "octree.h"

#include <QtOpenGL>

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
  QVector3D p1 = kP1 * radius;
  QVector3D p2 = kP2 * radius;
  root = GenSphereRec(radius, center, max_depth, 0, p1, p2);
}

void Octree::UpdateP() {
  root->UpdatePRec(kP1, kP2);
}

void Octree::SetSpread(float spread) {
  this->spread = spread;
}

OctreeNode *Octree::GenSphereRec(float radius, const QVector3D &center, int max_depth, int depth, const QVector3D &p1, const QVector3D &p2) {
  OctreeNode *node;
  if (depth >= max_depth) {
    QVector3D p3 = center - ((p1 + p2) / 2);
    if (QVector3D::dotProduct(p3, p3) < radius * radius) {
      node = new OctreeFull();
    } else {
      node = new OctreeEmpty();
    }
  } else {
    QVector3D p3 = (p1 + p2) / 2;
    float scale = (1.0f / pow(2, depth));
    OctreePartial *part = new OctreePartial();
    bool empty = false;
    bool full = false;
    for (int i = 0; i < 8; i++) {
      QVector3D shift = scale * kOctreeCoords[i];
      part->nodes[i] = GenSphereRec(radius, center, max_depth, depth + 1, p1 + shift, p3 + shift);
      if(part->nodes[i]->GetType()==OctreeType::Full){
        full = true;
      }else if(part->nodes[i]->GetType()==OctreeType::Empty){
        empty= true;
      }
    }
    node = part;
    if (empty == true && full == false) {
      node = new OctreeEmpty();
    } else if (empty == false && full == true) {
      node = new OctreeFull();
    }
  }
  return node;
}
