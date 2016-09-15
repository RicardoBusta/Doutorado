#include "octreeshape.h"

OctreeShape::OctreeShape()
{

}

OctreeNode *OctreeShape::GenRec(int max_depth, int depth, const QVector3D &p1, const QVector3D &p2) {
  OctreeNode *node;
  if (depth >= max_depth) {
    QVector3D p3 = ((p1 + p2) / 2);
    if (ConditionInside(p3)) {
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
    bool partial = false;
    for (int i = 0; i < 8; i++) {
      QVector3D shift = scale * kOctreeCoords[i];
      part->nodes[i] = GenRec(max_depth, depth + 1, p1 + shift, p3 + shift);
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
      } else if (empty == false && full == true) {
        node = new OctreeFull();
      }
    }
  }
  return node;
}
