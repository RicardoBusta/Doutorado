#include "scene.h"

#include "octree/octree.h"

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
  OctreePartial *root = new OctreePartial();
  root->nodes[0] = new OctreeFull();
  root->nodes[1] = new OctreeFull();
  root->nodes[2] = new OctreeFull();
  root->nodes[3] = new OctreeFull();
  root->nodes[4] = new OctreeFull();
  root->nodes[5] = new OctreeFull();
  root->nodes[6] = new OctreeFull();
  root->nodes[7] = new OctreeFull();
  Octree * octree = new Octree(root,0xffffff,0xff0000);
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
