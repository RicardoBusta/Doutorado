#include "object.h"

#include <QDebug>
#include <QtOpenGL>

#include "commondefs.h"

static int count = 0;

Object::Object()
    : scale(QVector3D(1, 1, 1)), hide(false), line(false) {
  name = QString("Object %1").arg(count++);
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
