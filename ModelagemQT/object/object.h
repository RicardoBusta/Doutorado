#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include <QVector>

class Object {
public:
  Object();

  QString name;
  QVector<Object*> children;

  void Render();
protected:
  virtual void Draw() const;
};

#endif // OBJECT_H
