#include "octreepyramid.h"

OctreePyramid::OctreePyramid(float r, float h, float s)
  :OctreeShape(),
    r(r),
    h(h),
    s(s)
{

}

bool OctreePyramid::ConditionInside(const QVector3D &p)
{
  return true;
}
