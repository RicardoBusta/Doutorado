#include "csgpyramid.h"

#include "commondefs.h"

CSGPyramid::CSGPyramid(float r, float h, int s)
  : CSGObject(),
    r(r),
    h(h),
    s(s)
{
 Rename("CSG Pyramid");
  float side = qMax(h/2,r);
  bb1 = QVector3D(-side,-side,-side);
  bb2 = QVector3D(side,side,side);
  float angle = 2*M_PI;
  for(int i=0;i<s+1;i++){
    float a = float(i)/float(s);
    a = a*angle;
    points.push_back(QVector3D(cos(a),0,sin(a)));
  }
}

HitInfo CSGPyramid::RayCast(const Ray &r, const HitInfo &hitinfo)
{
  return hitinfo;
}

bool CSGPyramid::ConditionInside(const QVector3D &p) const
{
  if(p.y() <= h/2.0f && p.y() >= -h/2.0f){
    float nr = r*(((p.y()-(h/2.0f))/(h)));;
    for(int i=0;i<s;i++){
      QVector3D p1 = nr*points[i];
      QVector3D p2 = nr*points[(i+1)%s];
      QVector3D pc = QVector3D::crossProduct(p2-p1,p-p1);
      if(pc.y()>0){
        return false;
      }
    }
    return true;
  }
  return false;
}
