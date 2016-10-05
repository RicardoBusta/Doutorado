#include "octreeprism.h"

#define M_PI 3.14159265358979323846

#include <QDebug>

OctreePrism::OctreePrism(float r, float h, int s)
  :OctreeShape(),
    r(r),
    h(h),
    s(s)
{
  float angle = 2*M_PI;
  for(int i=0;i<s+1;i++){
    float a = float(i)/float(s);
    a = a*angle;
    points.push_back(QVector3D(r*cos(a),0,r*sin(a)));
  }
}

bool OctreePrism::ConditionInside(const QVector3D &p)
{
  if(p.y() <= h/2.0f && p.y() >= -h/2.0f){
    for(int i=0;i<s;i++){
      QVector3D p1 = points[i];
      QVector3D p2 = points[(i+1)%s];
      QVector3D pc = QVector3D::crossProduct(p2-p1,p-p1);
      if(pc.y()>0){
        return false;
      }
    }
    return true;
  }
  return false;
}
