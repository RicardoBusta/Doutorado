#include "octreenode.h"

#include <QtOpenGL>

#include "commondefs.h"

const QVector3D kP1(-1, 1, 1);
const QVector3D kP2(1, -1, -1);

OctreeFull::OctreeFull()
  :OctreeNode()
{

}

void OctreeFull::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  glPushMatrix();
  //  if (spread > 0) {
  QVector3D center = (p1 + p2) / 2;
  float scale = qAbs(p1.x()-p2.x())/2*spread;
  glTranslatef(center.x(),center.y(),center.z());
  glScalef(scale,scale,scale);
  //}
  glColor3ub(UB_COLOR(fill));
  DrawBox(true);

  if (!draw_lines) {
    glPopMatrix();
    return;
  }
  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox(false);

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
  glPopMatrix();
}

OctreeType OctreeFull::GetType() {
  return OctreeType::Full;
}

QString OctreeFull::Save()
{
  return "b";
}

bool OctreeFull::IsInside(const QVector3D &p, int depth) const
{
  return true;
}

OctreeNode *OctreeFull::Copy()
{
  return new OctreeFull();
}

HitInfo OctreeFull::RayCast(const Ray &ray, const HitInfo &info)
{
  return info;
}

OctreeEmpty::OctreeEmpty()
  :OctreeNode()
{

}

void OctreeEmpty::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  if (!draw_lines) {
    return;
  }
  glPushMatrix();

  QVector3D center = (p1 + p2) / 2;
  float scale = qAbs(p1.x()-p2.x())/2*spread;
  glTranslatef(center.x(),center.y(),center.z());
  glScalef(scale,scale,scale);

  GLint polyMode[2];
  GLint cull;
  glGetIntegerv(GL_POLYGON_MODE, polyMode);
  glGetIntegerv(GL_CULL_FACE, &cull);

  glDisable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glColor3ub(UB_COLOR(line));
  DrawBox(false);

  glPolygonMode(GL_FRONT, polyMode[0]);
  glPolygonMode(GL_BACK, polyMode[1]);
  if (cull) {
    glEnable(GL_CULL_FACE);
  }
  glPopMatrix();
}

OctreeType OctreeEmpty::GetType() {
  return OctreeType::Empty;
}

QString OctreeEmpty::Save()
{
  return "w";
}

bool OctreeEmpty::IsInside(const QVector3D &p, int depth) const
{
  return false;
}

OctreeNode *OctreeEmpty::Copy()
{
  return new OctreeEmpty();
}

HitInfo OctreeEmpty::RayCast(const Ray &ray, const HitInfo &info)
{
  return info;
}

OctreePartial::OctreePartial()
  :OctreeNode()
{
  for (int i = 0; i < 8; i++) {
    nodes[i] = nullptr;
  }
}

OctreePartial::~OctreePartial() {
  for (int i = 0; i < 8; i++) {
    if (nodes[i] != nullptr) {
      delete nodes[i];
    }
  }
}

void OctreePartial::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
  p1 = np1;
  p2 = np2;
  pc = (np1 + np2) / 2;
  float shift = pc.x() - p1.x();

  for (int i = 0; i < 8; i++) {
    QVector3D slide = shift * kOctreeCoords[i];
    nodes[i]->UpdatePRec(p1 + slide, pc + slide);
  }

  v[0] = p1;
  v[1] = QVector3D(p1.x(),p2.y(),p1.z());
  v[2] = QVector3D(p2.x(),p2.y(),p1.z());
  v[3] = QVector3D(p2.x(),p1.y(),p1.z());
  v[4] = p2;
  v[5] = QVector3D(p1.x(),p1.y(),p1.z());
  v[6] = QVector3D(p1.x(),p1.y(),p2.z());
  v[7] = QVector3D(p2.x(),p1.y(),p2.z());
}

OctreeType OctreePartial::GetType() {
  return OctreeType::Partial;
}

QString OctreePartial::Save()
{
  QString out = "(";
  for(int i=0;i<8;i++){
    out += nodes[i]->Save();
  }
  return out;
}

/*
  2---1
 /|  /|
3-+-0 |
| 6-+-5   y
|/  |/    |_x
7---4   z/
*/
bool OctreePartial::IsInside(const QVector3D &p,int depth) const
{
  //ebug() << depth << pc << p1 << p2;
  if(p.x() > pc.x()){
    //0,1,4,5
    if(p.y()<pc.y()){
      //0,1
      if(p.z()>pc.z()){
        return nodes[0]->IsInside(p,depth+1);
      }else{
        return nodes[1]->IsInside(p,depth+1);
      }
    }else{
      //4,5
      if(p.z()>pc.z()){
        return nodes[4]->IsInside(p,depth+1);
      }else{
        return nodes[5]->IsInside(p,depth+1);
      }
    }
  }else{
    //2,3,6,7
    if(p.y()<pc.y()){
      //2,3
      if(p.z()>pc.z()){
        return nodes[3]->IsInside(p,depth+1);
      }else{
        return nodes[2]->IsInside(p,depth+1);
      }
    }else{
      //6,7
      if(p.z()>pc.z()){
        return nodes[7]->IsInside(p,depth+1);
      }else{
        return nodes[6]->IsInside(p,depth+1);
      }
    }
  }
  return false;
}

OctreeNode *OctreePartial::Copy()
{
  OctreePartial *out = new OctreePartial();

  for(int i=0;i<8;i++){
    out->nodes[i] = nodes[i]->Copy();
  }

  return out;
}

HitInfo OctreePartial::RayCast(const Ray &ray, const HitInfo &info)
{
  HitInfo new_info = CollideBB(ray);
  //if(new_info.t < info.t){
    return new_info;
//  }
//  return info;
}

void OctreePartial::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
  for (int i = 0; i < 8; i++) {
    nodes[i]->DrawRec(spread, line, /*color[i]*/ fill, draw_lines);
  }
}

OctreeNode::OctreeNode()
{
  f[0][0] = f[2][0] = f[4][0] = 0;
  f[0][1] = f[3][2] = f[4][3] = 1;
  f[0][2] = f[3][1] = f[5][3] = 2;
  f[0][3] = f[2][1] = f[5][2] = 3;
  f[1][0] = f[3][0] = f[5][0] = 4;
  f[1][1] = f[3][3] = f[4][2] = 5;
  f[1][2] = f[2][3] = f[4][1] = 6;
  f[1][3] = f[2][2] = f[5][1] = 7;

  n[0] = QVector3D(0,0,1);
  n[1] = QVector3D(0,0,-1);
  n[2] = QVector3D(0,1,0);
  n[3] = QVector3D(0,-1,0);
  n[4] = QVector3D(-1,0,0);
  n[5] = QVector3D(1,0,0);
}

void OctreeNode::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
  p1 = np1;
  p2 = np2;
  pc = (p1+p2)/2.0f;
}

void OctreeNode::DrawBox(bool lighting) {
  if (lighting) {
    glEnable(GL_LIGHTING);
  }
  glBegin(GL_QUADS);
  glNormal3f(0, 0, 1);
  //0
  glVertex3f(kP1.x(), kP1.y(), kP1.z());
  glVertex3f(kP1.x(), kP2.y(), kP1.z());
  glVertex3f(kP2.x(), kP2.y(), kP1.z());
  glVertex3f(kP2.x(), kP1.y(), kP1.z());

  //1
  glNormal3f(0, 0, -1);
  glVertex3f(kP2.x(), kP2.y(), kP2.z());
  glVertex3f(kP1.x(), kP2.y(), kP2.z());
  glVertex3f(kP1.x(), kP1.y(), kP2.z());
  glVertex3f(kP2.x(), kP1.y(), kP2.z());

  //2
  glNormal3f(0, 1, 0);
  glVertex3f(kP1.x(), kP1.y(), kP1.z());
  glVertex3f(kP2.x(), kP1.y(), kP1.z());
  glVertex3f(kP2.x(), kP1.y(), kP2.z());
  glVertex3f(kP1.x(), kP1.y(), kP2.z());

  //3
  glNormal3f(0, -1, 0);
  glVertex3f(kP2.x(), kP2.y(), kP2.z());
  glVertex3f(kP2.x(), kP2.y(), kP1.z());
  glVertex3f(kP1.x(), kP2.y(), kP1.z());
  glVertex3f(kP1.x(), kP2.y(), kP2.z());

  //4
  glNormal3f(-1, 0, 0);
  glVertex3f(kP1.x(), kP1.y(), kP1.z());
  glVertex3f(kP1.x(), kP1.y(), kP2.z());
  glVertex3f(kP1.x(), kP2.y(), kP2.z());
  glVertex3f(kP1.x(), kP2.y(), kP1.z());

  //5
  glNormal3f(1, 0, 0);
  glVertex3f(kP2.x(), kP2.y(), kP2.z());
  glVertex3f(kP2.x(), kP1.y(), kP2.z());
  glVertex3f(kP2.x(), kP1.y(), kP1.z());
  glVertex3f(kP2.x(), kP2.y(), kP1.z());
  glEnd();
  if (lighting) {
    glDisable(GL_LIGHTING);
  }
}

HitInfo OctreeNode::CollideBB(const Ray &ray)
{
  HitInfo hit;
  for(int i=0;i<6;i++){
    QVector3D face_normal = n[i];
    QVector3D face_v0 = v[f[i][0]];
    QVector3D face_v1 = v[f[i][1]];
    QVector3D face_v2 = v[f[i][2]];
    QVector3D face_v3 = v[f[i][3]];
    double vD = QVector3D::dotProduct(face_normal, ray.d);
    if(vD!=0){
      double vO = -QVector3D::dotProduct(face_normal,ray.o)+QVector3D::dotProduct(face_normal,face_v0);
      float new_t = vO/vD;
      if(new_t < hit.t /*&& new_t > 1*/){
        hit.hit=true;
        hit.t = new_t;
        qDebug() << new_t;
        hit.color = 0xffffffff;
        return hit;
        //qDebug()<< "face_v0" << face_v0 << v[f[i][0]] << f[i][0];
        QVector3D new_p = ray.o + ray.d*new_t;
        QVector3D d0 = QVector3D::crossProduct(face_v1-face_v0,new_p-face_v0);
        QVector3D d1 = QVector3D::crossProduct(face_v2-face_v1,new_p-face_v1);
        QVector3D d2 = QVector3D::crossProduct(face_v3-face_v2,new_p-face_v2);
        QVector3D d3 = QVector3D::crossProduct(face_v0-face_v3,new_p-face_v3);

        float l0 = QVector3D::dotProduct(d0,face_normal);
        float l1 = QVector3D::dotProduct(d1,face_normal);
        float l2 = QVector3D::dotProduct(d2,face_normal);
        float l3 = QVector3D::dotProduct(d3,face_normal);

        //qDebug() << new_p << face_v0 << face_v1 << d0 << face_normal << l0;
        if(l0>=0 && l1>=0 && l2>=0 && l3>=0){
          hit.hit=true;
          hit.t = new_t;
          hit.color = 0xffffffff;
        }
      }
    }
  }
  /*
   *  // TODO fazer o cast com um scene object. Caso o objeto seja composto, chamar recursivamente para cada sub objeto caso seja true para a "bounding area".
  const TriangleFace *hit_face = NULL;

  //  qDebug() << "cast";
  if(o->bounding_worthy_){
    //    qDebug() << "bounding worthy";
    bool hit = false;
    QVector<TriangleFace>::const_iterator bounding_faces_it;
    for(bounding_faces_it=o->bounding_volume_.begin();bounding_faces_it!=o->bounding_volume_.end();bounding_faces_it++){
      const TriangleFace &f = (*bounding_faces_it);
      double vD = f.n()*d_;
      if(vD != 0){
        float vO = -(f.n()*o_)+(f.n()*f.v0());
        float new_t = vO/vD;
        if(new_t<t_ && new_t>near_length_){
          Ric::Vector new_p = (o_+(d_*new_t));
          Ric::Vector d1 = (f.v1()-f.v0())^(new_p-f.v0());
          Ric::Vector d2 = (f.v2()-f.v1())^(new_p-f.v1());
          Ric::Vector d3 = (f.v0()-f.v2())^(new_p-f.v2());

          float l1 = d1*f.n();
          float l2 = d2*f.n();
          float l3 = d3*f.n();
          if((l1 >= 0) && (l2 >= 0) && (l3 >= 0)){
            hit = true;

            // DEBUG, draw boundingbox
            //            hit_face = &f;
            //            hit_ = true;
            //            t_ = new_t;
            //            p_ = new_p;
            //            n_ = f.n();
            //            return hit_face;

            break;
          }
        }
      }
    }

    if( false == hit ){
      return NULL;
    }
  }
  //  qDebug() << "break";

  for(int i=0;i<o->child_objects_.size();i++){
    const TriangleFace *hit = NULL;
    hit = cast(&(o->child_objects_[i]));
    if(hit != NULL){
      hit_face = hit;
    }*/
  return hit;
}
