#include "octreeshape.h"

#include <QDebug>

OctreeShape::OctreeShape() {
}

OctreeNode *OctreeShape::GenRec(int max_depth, int depth, float size, const QVector3D &p1, const QVector3D &p2) {
  OctreeNode *node;
  if (depth >= max_depth) {
    QVector3D p3 = ((p1 + p2) / 2);
    //    qDebug() << depth << p1 << p2 << p3;
    if (ConditionInside(p3)) {
      node = new OctreeFull();
      node->p1 = p1;
      node->p2 = p2;
    } else {
      node = new OctreeEmpty();
      node->p1 = p1;
      node->p2 = p2;
    }
  } else {
    QVector3D p3 = (p1 + p2) / 2;
    //    qDebug() << depth << p1 << p2 << p3;
    float scale = (size / pow(2, depth));
    OctreePartial *part = new OctreePartial();
    part->p1 = p1;
    part->p2 = p2;
    bool empty = false;
    bool full = false;
    bool partial = false;
    for (int i = 0; i < 8; i++) {
      QVector3D shift = scale * kOctreeCoords[i];
      part->nodes[i] = GenRec(max_depth, depth + 1, size, p1 + shift, p3 + shift);
      if (partial == false) {
        if (part->nodes[i]->GetType() == OctreeType::Full) {
          full = true;
        } else if (part->nodes[i]->GetType() == OctreeType::Empty) {
          empty = true;
        } else if (part->nodes[i]->GetType() == OctreeType::Partial) {
          partial = true;
        }
      }
    }
    node = part;
    if (partial == false) {
      if (empty == true && full == false) {
        node = new OctreeEmpty();
        delete part;
      } else if (empty == false && full == true) {
        node = new OctreeFull();
        delete part;
      }
    }
  }
  return node;
}
