#include "scene.h"

#include "octree/octree.h"
#include <QDebug>

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

void Scene::CreateOctree() {
  /*OctreePartial *root = new OctreePartial();
  root->nodes[0] = new OctreeFull();
  root->nodes[1] = new OctreeFull();
  root->nodes[2] = new OctreeFull();
  root->nodes[3] = new OctreeFull();
  root->nodes[4] = new OctreeFull();
  root->nodes[5] = new OctreeFull();
  root->nodes[6] = new OctreeFull();
  root->nodes[7] = new OctreeFull();*/
  Octree * octree = new Octree(nullptr,0xffffff,0xAA0000);
  octree->GenSphere(1.0f,QVector3D(1,0,0),5);
  octree->UpdateP();
  CreateObjectGeneric(octree);
}

void Scene::CreateObjectGeneric(Object *obj)
{
  if (make_parent && current_object != nullptr) {
    current_object->children.push_back(obj);
  } else {
    objects.push_back(obj);
  }
  emit UpdateObjList();
}

void Scene::ChangeOctreeSpread(int spread)
{   Octree* octree = dynamic_cast<Octree*>(current_object);
    if(octree!=nullptr){
        float s = float(spread) / 100.0f;
        octree->SetSpread(s);
        emit UpdateObjList();
    }
}
