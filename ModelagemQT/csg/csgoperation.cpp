#include "csgoperation.h"

#include "commondefs.h"

CSGOPeration::CSGOPeration(int op)
  :CSGObject(),
    op(op)
{
  switch (op) {
  case 0:
    Rename("CSG Union");
    break;
  case 1:
    Rename("CSG Intersection");
    break;
  case 2:
    Rename("CSG Difference");
    break;
  }
  drawRec = false;
}

HitInfo CSGOPeration::RayCast(const Ray &r, const HitInfo &hitinfo)
{
  return hitinfo;
}

bool CSGOPeration::ConditionInside(const QVector3D &p) const
{
  if(children.size()<=1){
    return false;
  }
  CSGObject *o1 = dynamic_cast<CSGObject*>(children[0]);
  CSGObject *o2 = dynamic_cast<CSGObject*>(children[1]);
  QVector3D p1_p = o1->InvTransform()*p;
  QVector3D p2_p = o2->InvTransform()*p;

  switch(op){
  case 0:
    //União
    if(o1->ConditionInside(p1_p) || o2->ConditionInside(p2_p)){
      return true;
    }
    break;
  case 1:
    //Interseção
    if(o1->ConditionInside(p1_p) && o2->ConditionInside(p2_p)){
      return true;
    }
    break;
  case 2:
    //Diferença
    if(o1->ConditionInside(p1_p) && !o2->ConditionInside(p2_p)){
      return true;
    }
    break;
  }
  return false;
}

void CSGOPeration::Recalculate()
{

  qDebug() << "recalculate";


  if(children.size()<=1){
    return;
  }
  dots.clear();
  CSGObject *o1 = dynamic_cast<CSGObject*>(children[0]);
  CSGObject *o2 = dynamic_cast<CSGObject*>(children[1]);
  switch(op){
  case 0:
    //união
    qDebug()<<"0";
    foreach(QVector3D v ,o1->dots){
      dots.push_back(o1->Transform()*v);
    }
    foreach(QVector3D v ,o2->dots){
      dots.push_back(o2->Transform()*v);
    }
    break;
  case 1:
    qDebug()<<"1";
    //interseção
    foreach(QVector3D v ,o1->dots){
      QVector3D tv = o1->Transform()*v;
      if(o2->ConditionInside(o2->InvTransform()*tv)){
        dots.push_back(tv);
      }
    }
    foreach(QVector3D v ,o2->dots){
      QVector3D tv = o2->Transform()*v;
      if(o1->ConditionInside(o1->InvTransform()*tv)){
        dots.push_back(tv);
      }
    }

    break;
  case 2:
    //diferença
    qDebug()<<"2";
    foreach(QVector3D v ,o1->dots){
      QVector3D tv = o1->Transform()*v;
      if(!o2->ConditionInside(tv)){
        dots.push_back(tv);
      }
    }
    break;
  }
  if(parent!=nullptr){
    parent->Recalculate();
  }
}
