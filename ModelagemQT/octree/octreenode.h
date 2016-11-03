#ifndef OCTREENODE_H
#define OCTREENODE_H

#include <QRgb>
#include <QVector3D>

#include "ray.h"

const QVector3D kOctreeCoords[] = {
    QVector3D(1, -1, 0),
    QVector3D(1, -1, -1),
    QVector3D(0, -1, -1),
    QVector3D(0, -1, 0),
    QVector3D(1, 0, 0),
    QVector3D(1, 0, -1),
    QVector3D(0, 0, -1),
    QVector3D(0, 0, 0)};

enum OctreeType {
  Full,
  Empty,
  Partial
};

class OctreeNode {
public:
  OctreeNode();
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const = 0;
  virtual void UpdatePRec(const QVector3D &np1, const QVector3D &np2);
  virtual enum OctreeType GetType() = 0;
  static void DrawBox(bool lighting);
  HitInfo CollideBB(const Ray &ray);
  QVector3D p1, p2, pc;
  QVector3D v[8];
  QVector3D n[6];
  int f[6][4];

  virtual QString Save()=0;

  virtual bool IsInside(const QVector3D &p, int depth) const=0;

  virtual OctreeNode * Copy()=0;
  virtual HitInfo RayCast(const Ray &ray, const HitInfo &info)=0;
protected:
  QVector3D dp1, dp2;
};

class OctreeFull : public OctreeNode {
public:
  OctreeFull();
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
  enum OctreeType GetType();
  virtual QString Save();
  virtual bool IsInside(const QVector3D &p, int depth) const;
  virtual OctreeNode * Copy();
  virtual HitInfo RayCast(const Ray &ray, const HitInfo &info);
};

class OctreeEmpty : public OctreeNode {
public:
  OctreeEmpty();
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
  enum OctreeType GetType();
  virtual QString Save();
  virtual bool IsInside(const QVector3D &p, int depth) const;
  virtual OctreeNode * Copy();
  virtual HitInfo RayCast(const Ray &ray, const HitInfo &info);
};

class OctreePartial : public OctreeNode {
public:
  OctreePartial();
  virtual ~OctreePartial();
  virtual void DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const;
  virtual void UpdatePRec(const QVector3D &np1, const QVector3D &np2);
  enum OctreeType GetType();
  virtual QString Save();
  virtual bool IsInside(const QVector3D &p, int depth) const;
  virtual OctreeNode * Copy();
  virtual HitInfo RayCast(const Ray &ray, const HitInfo &info);
public:
  OctreeNode *nodes[8];
};

#endif // OCTREENODE_H
