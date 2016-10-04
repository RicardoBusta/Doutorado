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

QString Object::Save()
{
    QString parent_name = parent!=nullptr?parent->getName():"none";
    return QString("%1 %2 %3 %4 %5").arg(ObjectType(),parent_name,getName(),TransformText(),SaveSpecific());
}

QString Object::SaveSpecific()
{
    return "";
}

QString Object::ObjectType()
{
    return "obj";
}

QString Object::TransformText()
{
    return QString("%1 %2 %3 %4 %5 %6 %7 %8 %9")
            .arg(position.x())
            .arg(position.y())
            .arg(position.z())
            .arg(rotation.x())
            .arg(rotation.y())
            .arg(rotation.z())
            .arg(scale.x())
            .arg(scale.y())
            .arg(scale.z());
}

void Object::Draw() const {
}
