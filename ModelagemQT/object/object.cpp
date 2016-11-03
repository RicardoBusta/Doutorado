#include "object.h"

#include <QDebug>
#include <QtOpenGL>

#include "commondefs.h"

QMap<QString, Object *> Object::obj_map = QMap<QString, Object *>();

Object::Object(QString name)
  : scale(QVector3D(1, 1, 1)),
    hide(false),
    line(false),
    parent(nullptr),
    drawRec(true)
{
  this->name = name;
  int count=0;
  while (obj_map.contains(this->name)) {
    this->name = name + "_" + QString::number(count++);
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
  new_name.replace(' ','_');
  name = new_name;
  int count =0;
  while (obj_map.contains(name)) {
    name = new_name + " " + QString::number(count++);
  }
  obj_map.insert(name, this);
}

void Object::Render() {
  glPushMatrix();
  glMultMatrixf(transform.data());
  Draw();
  if(drawRec){
    foreach (Object *o, children) {
      o->Render();
    }
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

  inv_transform = transform.inverted();

  if(parent!=nullptr){
  parent->Recalculate();
  }

  UpdateSpecific();
}

void Object::UpdateSpecific()
{

}

QString Object::Save()
{
  QString parent_name = parent!=nullptr?parent->getName():"none";
  QString result = QString("%1 %2 %3 %4 %5").arg(ObjectType(),parent_name,getName(),TransformText(),SaveSpecific())+"\n";
  foreach(Object *child, children){
    result += child->Save();
  }
  return result;
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
  QVector3D rot = rotation.toEulerAngles();
  return QString("%1 %2 %3 %4 %5 %6 %7 %8 %9")
      .arg(position.x())
      .arg(position.y())
      .arg(position.z())
      .arg(rot.x())
      .arg(rot.y())
      .arg(rot.z())
      .arg(scale.x())
      .arg(scale.y())
      .arg(scale.z());
}

QMatrix4x4 Object::Transform() const
{
  return transform;
}

QMatrix4x4 Object::InvTransform() const
{
  return inv_transform;
}

bool Object::IsInside(const QVector3D) const
{
  return false;
}

Object *Object::Duplicate()
{
  return new Object(name+" copy");
}

QColor Object::getFaceColor() const
{
  return fill_color;
}

QColor Object::getLineColor() const
{
  return line_color;
}

void Object::setFaceColor(const QColor &color)
{
  fill_color = color.rgba();
}

void Object::setLineColor(const QColor &color)
{
  line_color = color.rgba();
}

HitInfo Object::RayCast(const Ray &r, const HitInfo &hitinfo)
{
  return hitinfo;
}

void Object::Recalculate()
{
}

void Object::Draw() const {
}
