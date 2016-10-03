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
  transform.setToIdentity();
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
  glMultMatrixf(transform.data());
  Draw();
  foreach (Object *o, children) {
    o->Render();
  }
  glPopMatrix();
}

QVector3D Object::getPosition() const {
    return  position;
}

QVector3D Object::getRotation() const {
    return rotation.toEulerAngles();
}

QVector3D Object::getScale() const {
    return scale;
}

void Object::setPosition(float x, float y, float z)
{
    position.setX(x);
    position.setY(y);
    position.setZ(z);
    UpdateTransform();
}

void Object::setRotation(float x, float y, float z)
{
    rotation = QQuaternion::fromEulerAngles(x,y,z);
    UpdateTransform();
}

void Object::setScale(float x, float y, float z)
{
    scale.setX(x);
    scale.setY(y);
    scale.setZ(z);
    UpdateTransform();
}

void Object::UpdateTransform()
{
    transform.setToIdentity();
    transform.translate(position);
    transform.rotate(rotation);
    transform.scale(scale);
    UpdateSpecific();
}

void Object::UpdateSpecific()
{

}

void Object::Draw() const {
}
