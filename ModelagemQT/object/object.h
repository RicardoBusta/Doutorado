#ifndef OBJECT_H
#define OBJECT_H

#include <QMap>
#include <QString>
#include <QVector3D>
#include <QVector>
#include <QQuaternion>
#include <QMatrix4x4>
#include <QRgb>

#include "ray.h"

class Object {
public:
  Object(QString name = "Object");
  ~Object();

  QString getName() const;
  void Rename(QString new_name);
  bool hide;
  bool line;
  QVector<Object *> children;

  bool drawRec;
  virtual void Render();

  QVector3D getPosition() const;
  QVector3D getRotation() const;
  QVector3D getScale() const;

  void setPosition(float x, float y, float z);
  void setRotation(float x, float y, float z);
  void setScale(float x, float y, float z);

  void UpdateTransform();
  virtual void UpdateSpecific();

  static QMap<QString, Object *> obj_map;

  Object * parent;

  QString Save();
  virtual QString SaveSpecific();
  virtual QString ObjectType();
  QString TransformText();

  QMatrix4x4 Transform() const;
  QMatrix4x4 InvTransform() const;

  virtual bool IsInside(const QVector3D) const;

  virtual Object * Duplicate();

  QColor getFaceColor() const;
  QColor getLineColor() const;

  void setFaceColor(const QColor &color);
  void setLineColor(const QColor &color);

  virtual HitInfo RayCast(const Ray &r, const HitInfo &hitinfo);

  virtual void Recalculate();
protected:
  virtual void Draw() const;
  QString name;

  QVector3D position;
  QQuaternion rotation;
  QVector3D scale;

  QMatrix4x4 transform;
  QMatrix4x4 inv_transform;

  QRgb line_color;
  QRgb fill_color;
};

#endif // OBJECT_H
