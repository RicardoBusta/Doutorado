#include "raycastwidget.h"

#include <QPainter>
#include "scene.h"

RaycastWidget::RaycastWidget(QWidget *parent) : QWidget(parent)
{
  image = QImage(100,100,QImage::Format_ARGB32);
  image.fill(Qt::white);
}

void RaycastWidget::paintEvent(QPaintEvent *event)
{
  for(int i=0;i<image.width();i++){
    for(int j=0;j<image.height();j++){
      Ray ray = Ray(QVector3D(0,0,0),QVector3D(0,0,1));
      QRgb color = s->RayCast(ray);
      image.setPixel(i,j,color);
    }
  }

  QPainter p(this);
  p.drawImage(this->rect(),image.scaled(rect().size()));
}
