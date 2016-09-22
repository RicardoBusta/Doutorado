#include "octreetorus.h"

OctreeTorus::OctreeTorus(float r1, float r2, const QVector3D &center)
  :r1(r1),r2(r2),center(center)
{

}

bool OctreeTorus::ConditionInside(const QVector3D &p)
{
return true;
}

