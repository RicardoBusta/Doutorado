#include "bezierobject.h"

#include <QtOpenGL>
#include "commondefs.h"

BezierObject::BezierObject(int x, int y)
{
  slices = 30;
  control_points.resize(x);
  for(int i=0;i<x;i++){
    float ii = (2*float(i)/float(x-1))-1;
    control_points[i].resize(y);
    for(int j=0;j<y;j++){
      float jj = (2*float(j)/float(y-1))-1;
      control_points[i][j] = QVector3D(ii,jj,0);
    }
  }

  Calc();
  //  qDebug() << "0,0" << BezierPoint(0,0);
  //  qDebug() << "1,1" << BezierPoint(1,1);
}

void BezierObject::Draw() const
{

  glPointSize(10);
  glBegin(GL_POINTS);
  for(int i=0;i<control_points.size();i++){
    for(int j=0;j<control_points[i].size(); j++){
      if(i==current_cp_x && j==current_cp_y){
        glColor3f(1,0,0);
      }else{
        glColor3f(1,1,1);
      }
      GLVERTEX3D(control_points[i][j]);
    }
  }
  glEnd();

  //  glLineWidth(2);

  //  for(int i=0;i<slices-1;i++){
  //    for(int j=0;j<slices-1;j++){
  //      glBegin(GL_LINE_LOOP);
  //      GLVERTEX3D(points[i][j]);
  //      GLVERTEX3D(points[i+1][j]);
  //      GLVERTEX3D(points[i+1][j+1]);
  //      GLVERTEX3D(points[i][j+1]);
  //      glEnd();
  //    }
  //  }

//  glEnable(GL_LIGHTING);
  glBegin(GL_QUADS);
  for(int i=0;i<slices-1;i++){
    float i1 = float(i)/float(slices-1);
    float i2 = float(i+1)/float(slices-1);
    for(int j=0;j<slices-1;j++){
      float j1 = float(j)/float(slices-1);
      float j2 = float(j+1)/float(slices-1);
      glColor3f(i1,j1,1-(i1*j1));
      GLNORMAL3D(normals[i][j]);
      GLVERTEX3D(points[i][j]);
      glColor3f(i2,j1,1-(i2*j1));
      GLNORMAL3D(normals[i+1][j]);
      GLVERTEX3D(points[i+1][j]);
      glColor3f(i2,j2,1-(i2*j2));
      GLNORMAL3D(normals[i+1][j+1]);
      GLVERTEX3D(points[i+1][j+1]);
      glColor3f(i1,j2,1-(i1*j2));
      GLNORMAL3D(normals[i][j+1]);
      GLVERTEX3D(points[i][j+1]);

      glColor3f(i1,j1,1-(i1*j1));
      GLNORMAL3D(-normals[i][j]);
      GLVERTEX3D(points[i][j]);
      glColor3f(i1,j2,1-(i1*j2));
      GLNORMAL3D(-normals[i+1][j]);
      GLVERTEX3D(points[i][j+1]);
      glColor3f(i2,j2,1-(i2*j2));
      GLNORMAL3D(-normals[i+1][j+1]);
      GLVERTEX3D(points[i+1][j+1]);
      glColor3f(i2,j1,1-(i2*j1));
      GLNORMAL3D(-normals[i][j+1]);
      GLVERTEX3D(points[i+1][j]);
    }
  }
  glEnd();

  glPointSize(1);
  glLineWidth(1);
//  glDisable(GL_LIGHTING);
}

void BezierObject::Calc()
{
  points.resize(slices);
  normals.resize(slices);
  for(int i=0;i<slices;i++){
    float ii = float(i)/float(slices-1);
    points[i].resize(slices);
    normals[i].resize(slices);
    for(int j=0;j<slices;j++){
      float jj = float(j)/float(slices-1);
      points[i][j] = BezierPoint(ii,jj);
      normals[i][j] = BezierNormal(ii,jj);
    }
  }
}

QVector3D BezierObject::BezierPoint(float x, float y) const
{
  qDebug() << x << y;
  QVector3D sum;
  int n = control_points.size();
  int m = control_points[0].size();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      sum += B(n-1,i,x)*B(m-1,j,y)*control_points[i][j];
    }
  }
  qDebug() << sum;
  return sum;
}

QVector3D BezierObject::BezierNormal(float x, float y) const
{
  QVector3D nx;
  QVector3D ny;
  int n = control_points.size();
  int m = control_points[0].size();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      nx += Bx(n-1,i,x)*B(m-1,j,y)*control_points[i][j];
      ny += B(n-1,i,x)*Bx(m-1,j,y)*control_points[i][j];
    }
  }
  QVector3D norm = QVector3D::crossProduct(nx,ny).normalized();
  return norm;
}

float BezierObject::B(int n, int i, float u) const {
  return Bin(n,i)*qPow(u,i)*qPow((1-u),(n-i));
}

float BezierObject::Bx(int n, int i, float u) const
{
  return Bin(n,i)*(i*qPow(u,i-1)-n*qPow(u,n-1));
}

float BezierObject::Bin(int n, int i) const {
  return Fat(n)/(Fat(i)*Fat(n-i));
}

float BezierObject::Fat(int n) const
{
  float fat = 1;
  for(int i=1;i<=n;i++){
    fat *= i;
  }
  return fat;
}
