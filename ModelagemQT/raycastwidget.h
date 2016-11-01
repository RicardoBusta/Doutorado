#ifndef RAYCASTWIDGET_H
#define RAYCASTWIDGET_H

#include <QWidget>

#include <QImage>

class Scene;

class RaycastWidget : public QWidget
{
  Q_OBJECT
public:
  explicit RaycastWidget(QWidget *parent = 0);

  void paintEvent(QPaintEvent *event);

  Scene * s;
private:
  QImage image;

signals:

public slots:
};

#endif // RAYCASTWIDGET_H
