#include "object.h"

#include <QDebug>
#include <QtOpenGL>

#include "commondefs.h"

QMap<QString, Object *> Object::obj_map = QMap<QString, Object *>();

static int count = 0;

Object::Object(QString name)
    : scale(QVector3D(1, 1, 1)),
      hide(false),
      line(false),
      parent(nullptr) {
  this->name = name + " " + QString::number(count++);
  while (obj_map.contains(name)) {
    this->name = name + " " + QString::number(count++);
  }
  obj_map.insert(this->name, this);
}

Object::~Object() {
}

QString Object::getName() const {
  return name;
}

void Object::Rename(QString new_name) {
  obj_map.remove(name);
  name = new_name;
  while (obj_map.contains(name)) {
    name = new_name + " " + QString::number(count++);
  }
  obj_map.insert(name, this);
}

void Object::Render() {
  glPushMatrix();
  glTranslatef(FVECTOR3D(position));
  glRotatef(rotation.x(), 1, 0, 0);
  glRotatef(rotation.y(), 0, 1, 0);
  glRotatef(rotation.z(), 0, 0, 1);
  glScalef(FVECTOR3D(scale));
  Draw();
  foreach (Object *o, children) {
    o->Render();
  }
  glPopMatrix();
}

void Object::Draw() const {
}
