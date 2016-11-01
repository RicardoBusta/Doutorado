#include "scene.h"

#include "octree/octree.h"
#include <QDebug>
#include <QColor>

#include "globaloptions.h"

#include <QRegularExpression>

QRegularExpression obj;
QRegularExpression octexp;

Scene::Scene(QObject *parent)
  : QObject(parent),
    current_object(nullptr),
    make_parent(false) {
  QString obj_reg = "\\s(\\w+)\\s(\\w+)\\s";
  QString float_reg = "(-?\\d+(?:\\.\\d+)?)";
  QString color_reg = "(#[\\dA-Fa-f]{6})";
  for(int i=0;i<9;i++){
    obj_reg += float_reg+"\\s";
  }

  QString oct_reg = "oct"+obj_reg;
  for(int i=0;i<6;i++)
  {
    oct_reg += float_reg+"\\s";
  }

  oct_reg+=color_reg+"\\s";
  oct_reg+=color_reg+"\\s";
  oct_reg+="([\\(wb]+)";

  obj_reg = "obj"+obj_reg;

//  qDebug() << obj_reg;
//  qDebug() << oct_reg;

  obj = QRegularExpression(obj_reg);
  octexp = QRegularExpression(oct_reg);

  qDebug() << "Valid strings?" << obj.isValid() << octexp.isValid();
}

void Scene::Render()
{
  foreach(Object* o, objects){
    o->Render();
  }
}

QRgb Scene::RayCast(const Ray &ray)
{
  HitInfo currenthit = HitInfo();
  foreach (Object *o, objects) {
    HitInfo hitinfo = o->RayCast(ray);
    if(hitinfo.hit && (hitinfo.t < currenthit.t)){
      currenthit = hitinfo;
    }
  }
  return currenthit.color;
}

void Scene::UpdateMakeParent(bool val)
{
  make_parent = val;
}

void Scene::CreateObject() {
  Object *obj = new Object();
  CreateObjectGeneric(obj);
}

void Scene::CreateObjectGeneric(Object *obj)
{
  if (make_parent && current_object != nullptr) {
    current_object->children.push_back(obj);
    obj->parent = current_object;
  } else {
    objects.push_back(obj);
  }
  emit UpdateObjList();
}

void Scene::DeleteCurrentObject()
{
  objects.removeOne(current_object);
  delete current_object;
  current_object = nullptr;
  emit UpdateObjList();
}

void Scene::AddObjectFromString(const QString &objcode)
{
  //qDebug() << obj.isValid();
  if(objcode.startsWith("obj")){
    QRegularExpressionMatch m = obj.match(objcode);
    qDebug() << m.capturedTexts();

    int cap_count = m.capturedTexts().size();

    if(cap_count!=12){
      qDebug () << "Cap fail" << cap_count;
      return;
    }

    QString parent = m.captured(1);
    QString name = m.captured(2);

    Object * o = new Object(name);
    o->setPosition(m.captured(3).toFloat(),m.captured(4).toFloat(),m.captured(5).toFloat());
    o->setRotation(m.captured(6).toFloat(),m.captured(7).toFloat(),m.captured(8).toFloat());
    o->setScale(m.captured(9).toFloat(),m.captured(10).toFloat(),m.captured(11).toFloat());
    CreateObjectGeneric(o);
    if(parent!="none"){
      Reparent(name,parent);
    }
  }else if(objcode.startsWith("oct")){
    QRegularExpressionMatch m = octexp.match(objcode);

//    int i=0;
//    foreach(QString s, m.capturedTexts()){
//      qDebug() << s << i++;
//    }

    int cap_count = m.capturedTexts().size();

    //qDebug() << cap_count;

    if(cap_count!=21){
      qDebug () << "Cap fail";
      return;
    }

    QString parent = m.captured(1);
    QString name = m.captured(2);

    Octree * o = new Octree(name,nullptr,0xff0000,0xffffff);
    o->setPosition(m.captured(3).toFloat(),m.captured(4).toFloat(),m.captured(5).toFloat());
    o->setRotation(m.captured(6).toFloat(),m.captured(7).toFloat(),m.captured(8).toFloat());
    o->setScale(m.captured(9).toFloat(),m.captured(10).toFloat(),m.captured(11).toFloat());
    o->setFaceColor(QColor(m.captured(18)));
    o->setLineColor(QColor(m.captured(19)));
    o->GenText(m.captured(20));
    o->SetP(
          QVector3D(m.captured(12).toFloat(),m.captured(13).toFloat(),m.captured(14).toFloat()),
          QVector3D(m.captured(15).toFloat(),m.captured(16).toFloat(),m.captured(17).toFloat()));
    o->UpdateP();
    CreateObjectGeneric(o);
    if(parent!="none"){
      Reparent(name,parent);
    }
  }
}

void Scene::ChangeOctreeSpread(int spread)
{   Octree* octree = dynamic_cast<Octree*>(current_object);
    if(octree!=nullptr){
      float s = float(spread) / 1000.0f;
      octree->SetSpread(1-s);
      emit UpdateDrawing();
    }
}

void Scene::Reparent(QString child, QString new_parent)
{
  Object *moving = Object::obj_map[child];
  Object *parent = Object::obj_map[new_parent];

  qDebug() << moving->getName() << parent->getName();

  if(moving->parent!=nullptr){
    moving->parent->children.removeOne(moving);
  }else{
    objects.removeOne(moving);
  }
  if(moving != parent){
    moving->parent = parent;
    parent->children.push_back(moving);
  }else{
    moving->parent = nullptr;
    objects.push_back(moving);
  }
  emit UpdateDrawing();
}
