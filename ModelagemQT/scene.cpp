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

//void Scene::CreateOctree() {
//  int max_d = 5;
//  Octree * octree = new Octree(nullptr,0xffffff,0xAA0000);
//  switch(GlobalOptions::Instance()->shape){
//  case GlobalOptions::Sphere:
//      octree->GenSphere(3.0f,QVector3D(0,0,0),max_d);
//    break;
//  case GlobalOptions::Cylinder:
//      octree->GenCylinder(0.1f,1.0f,QVector3D(0,0,0),max_d);
//    break;
//  case GlobalOptions::Box:
//      octree->GenBox(1.0f,4.0f,2.0f,QVector3D(0,0,0),max_d);
//    break;
//  case GlobalOptions::Torus:
//      octree->GenTorus(1.0f,2.0f,QVector3D(0,0,0),max_d);
//    break;
//  case GlobalOptions::Cone:
//      octree->GenCone(1.0f,2.0f,QVector3D(0,0,0),max_d);
//    break;
//  }
//  octree->UpdateP();
//  CreateObjectGeneric(octree);
//}

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
        emit UpdateDrawing();
    }
}
