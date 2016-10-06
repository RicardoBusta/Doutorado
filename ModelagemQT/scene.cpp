#include "scene.h"

#include "octree/octree.h"
#include <QDebug>

#include "globaloptions.h"

Scene::Scene(QObject *parent)
    : QObject(parent),
      current_object(nullptr),
      make_parent(false) {
}

void Scene::Render()
{
  foreach(Object* o, objects){
    o->Render();
  }
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
