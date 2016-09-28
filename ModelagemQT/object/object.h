#ifndef OBJECT_H
#define OBJECT_H

#include <QMap>
#include <QString>
#include <QVector3D>
#include <QVector>

class Object {
public:
  Object(QString name = "Object");
  ~Object();

  QString getName() const;
  void Rename(QString new_name);
  bool hide;
  bool line;
  QVector<Object *> children;

  QVector3D position;
  QVector3D rotation;
  QVector3D scale;

  void Render();

  static QMap<QString, Object *> obj_map;

  Object * parent;
protected:
  virtual void Draw() const;
  QString name;
};

#endif // OBJECT_H
