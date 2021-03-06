#include "octree.h"

#include <QtOpenGL>

#include "octreebox.h"
#include "octreecone.h"
#include "octreecylinder.h"
#include "octreesphere.h"
#include "octreetorus.h"
#include "commondefs.h"
#include "octreepyramid.h"
#include "octreeprism.h"

const QVector3D kP1(-1, 1, 1);
const QVector3D kP2(1, -1, -1);

static int count = 0;

Octree::Octree(QString name, OctreeNode *root, QRgb line_color, QRgb fill_color)
  : Object(name), root(root), spread(1) {
  this->line_color = line_color;
  this->fill_color = fill_color;
}

Octree::~Octree() {
  delete root;
}

void Octree::Draw() const {
  if(hide){
    return;
  }
  bool draw_lines = line;
  if (root != nullptr) {
    root->DrawRec(spread, line_color, fill_color, draw_lines);
  }
}

void Octree::GenSphere(float radius, const QVector3D &center, int max_depth) {
  OctreeSphere sphereGen(radius, center);
  p1 = kP1 * radius;
  p2 = kP2 * radius;
  float size = qAbs(p1.x() - p2.x())/2;
  root = sphereGen.GenRec(max_depth, 0, size, p1, p2);
}

void Octree::GenCylinder(float radius, float height, const QVector3D &center, int max_depth) {
  OctreeCylinder gen(radius, height, center);
  float bb = qMax(radius, height / 2.0f);
  p1 = kP1 * bb;
  p2 = kP2 * bb;
  float size = qAbs(p1.x() - p2.x())/2;
  root = gen.GenRec(max_depth, 0, size, p1, p2);
}

void Octree::GenCone(float radius, float height, const QVector3D &center, int max_depth) {
  OctreeCone gen(radius, height, center);
  float bb = qMax(radius, height / 2.0f);
  p1 = kP1 * bb;
  p2 = kP2 * bb;
  float size = qAbs(p1.x() - p2.x())/2;
  root = gen.GenRec(max_depth, 0, size, p1, p2);
}

void Octree::GenBox(float w, float h, float d, const QVector3D &center, int max_depth) {
  OctreeBox gen(w, h, d, center);
  float bb = qMax(w, qMax(h, d)) / 2;
  p1 = kP1 * bb;
  p2 = kP2 * bb;
  float size = qAbs(p1.x() - p2.x())/2;
  root = gen.GenRec(max_depth, 0, size, p1, p2);
}

void Octree::GenTorus(float r1, float r2, const QVector3D &center, int max_depth) {
  OctreeTorus gen(r1, r2, center);
  float bb = r1+r2;
  p1 = kP1 * bb;
  p2 = kP2 * bb;
  float size = qAbs(p1.x() - p2.x())/2;
  root = gen.GenRec(max_depth, 0, size, p1, p2);
}

void Octree::GenPrism(float r, float h, float s, QVector3D &center, int max_depth)
{
  OctreePrism gen(r,h,s);
  float bb = qMax(r,h/2.0f);
  p1 = kP1 * bb;
  p2 = kP2 * bb;
  float size = qAbs(p1.x() - p2.x())/2;
  root = gen.GenRec(max_depth, 0, size, p1, p2);
}

void Octree::GenPyramid(float r, float h, float s, QVector3D &center, int max_depth)
{
  OctreePyramid gen(r,h,s);
  float bb = qMax(r,h/2.0f);
  p1 = kP1 * bb;
  p2 = kP2 * bb;
  float size = qAbs(p1.x() - p2.x())/2;
  root = gen.GenRec(max_depth, 0, size, p1, p2);
}

void Octree::GenText(const QString &text)
{
  //  int index = 0;
  //  root = GenTextRec(text,index,&index);
  int index = text.size()-1;
  QVector<OctreeNode*> nodes;
  while(index >= 0){
    switch(text[index].toLatin1()){
    case 'w':
      nodes.push_back(new OctreeEmpty());
      break;
    case 'b':
      nodes.push_back(new OctreeFull());
      break;
    default:
      if(nodes.size()<8){
        qDebug() << "ERROR!";
        foreach(OctreeNode *n, nodes){
          delete n;
        }
        return;
      }
      OctreePartial * node = new OctreePartial();
      for(int i=0;i<8;i++){
        node->nodes[i] = nodes.takeLast();
      }
      nodes.push_back(node);
      break;
    }
    index --;
  }
  //p1 = kP1;
  //p2 = kP2;
  root = nodes.first();
  UpdateP();
}

//OctreeNode *Octree::GenTextRec(const QString &text, const int index_start, int *index_end)
//{
//  if(text[index_start]=='b'){
//    *index_end = index_start+1;
//    return new OctreeFull();
//  }else if(text[index_start]=='w'){
//    *index_end = index_start+1;
//    return new OctreeEmpty();
//  }else{
//    OctreePartial * node = new OctreePartial();
//    int index = index_start+1;
//    for(int i=0;i<8;i++){
//      node->nodes[i] = GenTextRec(text,index,&index);
//    }
//    return node;
//  }
//}

void Octree::UpdateP() {
  root->UpdatePRec(p1, p2);
  UpdateSpecific();
}

void Octree::SetP(const QVector3D &p1, const QVector3D &p2)
{
  this->p1 = p1;
  this->p2 = p2;
  UpdateP();
}

void Octree::SetSpread(float spread) {
  this->spread = spread;
}

void Octree::UpdateSpecific()
{
  bb1 = transform*p1;
  bb2 = transform*p2;
}

QString Octree::SaveSpecific()
{
  QString save = QString("%1 %2 %3 %4 %5 %6 %7 %8 %9")
      .arg(p1.x())
      .arg(p1.y())
      .arg(p1.z())
      .arg(p2.x())
      .arg(p2.y())
      .arg(p2.z())
      .arg(QColor(fill_color).name())
      .arg(QColor(line_color).name())
      .arg(root->Save());
  return save;
}

QString Octree::ObjectType()
{
  return "oct";
}

Object *Octree::Duplicate()
{
  Octree * out = new Octree(name+"_copy",root->Copy(),line_color,fill_color);
  out->SetP(p1,p2);
  out->position;
  out->rotation = rotation;
  out->scale = scale;
  return out;
}

bool Octree::IsInside(const QVector3D &p) const
{
  if(p.x() >= p1.x() && p.x() <= p2.x() ){
    if(p.y() <= p1.y() && p.y() >= p2.y() ){
      if(p.z() <= p1.z() && p.z() >= p2.z() ){
        return root->IsInside(p,0);
        //return true;
      }
    }
  }
  return false;
}

HitInfo Octree::RayCast(const Ray &ray, const HitInfo &hitinfo)
{
  if(root!=nullptr){
    root->RayCast(ray.Transformed(inv_transform),hitinfo);
  }else{
    return HitInfo();
  }
}
