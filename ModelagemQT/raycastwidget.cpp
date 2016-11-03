#include "raycastwidget.h"

#include <QPainter>
#include "scene.h"
#include <QDebug>

RaycastWidget::RaycastWidget(QWidget *parent) : QWidget(parent)
{
  image = QImage(100,100,QImage::Format_ARGB32);
  image.fill(Qt::white);

  camera_transform.translate(0,0,-3);
}

void RaycastWidget::paintEvent(QPaintEvent *event)
{
  const int w = image.width()-1;
  const int h = image.height()-1;
  QVector3D camera_position = camera_transform*QVector3D(0,0,0);
  for(int i=0;i<image.width();i++){
    const float x = ((2.0f*i)/w)-1.0f;
    for(int j=0;j<image.height();j++){
      const float y = ((2.0f*j)/h)-1.0f;
      Ray ray = Ray(camera_position,camera_transform*QVector3D(x,y,-1));
      QRgb color = s->RayCast(ray);
      image.setPixel(i,j,color);
    }
  }

  QPainter p(this);
  p.drawImage(this->rect(),image.scaled(rect().size()));
}
