#include "object.h"

#include <QDebug>

static int count = 0;

Object::Object() {
  name = QString("Object %1").arg(count++);
}

void Object::Render()
{
  Draw();
}

void Object::Draw() const
{
}
