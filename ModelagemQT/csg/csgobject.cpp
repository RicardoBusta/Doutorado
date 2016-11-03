#include "csgobject.h"

#include <QtOpenGL>
#include "commondefs.h"

CSGObject::CSGObject()
  :Object("CSG")
{
}

void CSGObject::Init()
{
  for(float i=0;i<=1;i+=0.02f) {
    float x = i*bb1.x()+(1-i)*bb2.x();
    for(float j=0;j<=1;j+=0.02f){
      float y = j*bb1.y()+(1-j)*bb2.y();
      for(float k=0;k<=1;k+=0.02f){
        float z = k*bb1.z()+(1-k)*bb2.z();
        if(ConditionInside(QVector3D(x,y,z))){
          dots.push_back(QVector3D(x,y,z));
        }
      }
    }
  }
}

void CSGObject::Draw() const
{
  if(hide){
    return;
  }
  glColor3ub(UB_COLOR(fill_color));
  glBegin(GL_POINTS);
  foreach(QVector3D v, dots){
    glVertex3f(FVECTOR3D(v));
  }
  glEnd();
}
