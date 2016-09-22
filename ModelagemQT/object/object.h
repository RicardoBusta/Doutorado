#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include <QVector>
#include <QVector3D>

class Object {
public:
  Object();

  QString name;
  bool hide;
  bool line;
  QVector<Object*> children;

  QVector3D position;
  QVector3D rotation;
  QVector3D scale;

  void Render();
protected:
  virtual void Draw() const;
};

#endif // OBJECT_H
