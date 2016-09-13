#include "octree.h"

#include <QtOpenGL>

#define UB_COLOR(color) qRed(color), qGreen(color), qBlue(color)

const QVector3D kP1(-1, 1, 1);
const QVector3D kP2(1, -1, -1);

static int count = 0;

const QVector3D kOctreeCoords[] = {
    QVector3D(1,-1,0),
    QVector3D(1,-1,-1),
    QVector3D(0,-1,-1),
    QVector3D(0,-1,0),
    QVector3D(1,0,0),
    QVector3D(1,0,-1),
    QVector3D(0,0,-1),
    QVector3D(0,0,0)
};

Octree::Octree(OctreeNode *root, QRgb line_color, QRgb fill_color)
    : Object(), root(root), line_color(line_color), fill_color(fill_color) {
    name = QString("Octree %1").arg(count++);
}

Octree::~Octree() {
    delete root;
}

void Octree::Draw() const {
    bool draw_lines = true;
    if (root != nullptr) {
        root->DrawRec(spread, line_color, fill_color, draw_lines);
    }
}

void Octree::GenSphere(float radius, const QVector3D &center, int max_depth) {
    QVector3D p1 = kP1*radius;
    QVector3D p2 = kP2*radius;
    root = GenSphereRec(radius,center,max_depth,0,p1,p2);
}

OctreeNode *Octree::GenSphereRec(float radius, const QVector3D &center, int max_depth, int depth, const QVector3D &p1, const QVector3D &p2) {
    OctreeNode *node;
    if (depth >= max_depth) {
        QVector3D p3 = center - ((p1+p2)/2);
        if(QVector3D::dotProduct(p3,p3) < radius*radius){
            node = new OctreeFull();
        }else{
            node = new OctreeEmpty();
        }
    } else {
        QVector3D p3 = (p1+p2)/2;
        float scale = (1.0f/pow(2,depth));
        OctreePartial * part = new OctreePartial();
        for(int i=0;i<8;i++){
            QVector3D shift = scale*kOctreeCoords[i];
            part->nodes[i] = GenSphereRec(radius, center, max_depth, depth+1, p1+shift, p3+shift);
        }
        node = part;
    }
    return node;
}

void Octree::UpdateP() {
    root->UpdatePRec(kP1, kP2);
}

void Octree::SetSpread(float spread)
{
    this->spread = spread;
}

void OctreeFull::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
    glPushMatrix();
    if (spread > 0) {
        QVector3D center = (p1 + p2) / 2;
        center.normalize();
        center *= spread;
        glTranslatef(center.x(), center.y(), center.z());
    }
    glColor3ub(UB_COLOR(fill));
    DrawBox();

    if (!draw_lines) {
        return;
    }
    GLint polyMode[2];
    GLint cull;
    glGetIntegerv(GL_POLYGON_MODE, polyMode);
    glGetIntegerv(GL_CULL_FACE, &cull);

    glDisable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glColor3ub(UB_COLOR(line));
    DrawBox();

    glPolygonMode(GL_FRONT, polyMode[0]);
    glPolygonMode(GL_BACK, polyMode[1]);
    if (cull) {
        glEnable(GL_CULL_FACE);
    }
    glPopMatrix();
}

void OctreeEmpty::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
    if (!draw_lines) {
        return;
    }
    GLint polyMode[2];
    GLint cull;
    glGetIntegerv(GL_POLYGON_MODE, polyMode);
    glGetIntegerv(GL_CULL_FACE, &cull);

    glDisable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glColor3ub(UB_COLOR(line));
    DrawBox();

    glPolygonMode(GL_FRONT, polyMode[0]);
    glPolygonMode(GL_BACK, polyMode[1]);
    if (cull) {
        glEnable(GL_CULL_FACE);
    }
}

OctreePartial::OctreePartial() {
    for (int i = 0; i < 8; i++) {
        nodes[i] = nullptr;
    }
}

OctreePartial::~OctreePartial() {
}

void OctreePartial::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
    p1 = np1;
    p2 = np2;
    QVector3D p3 = (np1 + np2) / 2;
    float shift = p3.x()-p1.x();

    for(int i=0;i<8;i++){
        QVector3D slide = shift*kOctreeCoords[i];
        nodes[i]->UpdatePRec(p1+slide,p3+slide);
    }
}

void OctreePartial::DrawRec(const float spread, const QRgb &line, const QRgb &fill, bool draw_lines) const {
    //QRgb color[] = {0xff0000, 0xffff00, 0xffffff, 0x00ff00, 0x00ffff, 0x0000ff, 0xff00ff, 0x000000};
    for (int i = 0; i < 8; i++) {
        nodes[i]->DrawRec(spread, line, /*color[i]*/fill, draw_lines);
    }

    if (!draw_lines) {
        return;
    }

    GLint polyMode[2];
    GLint cull;
    glGetIntegerv(GL_POLYGON_MODE, polyMode);
    glGetIntegerv(GL_CULL_FACE, &cull);

    glDisable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glColor3ub(UB_COLOR(line));
    DrawBox();

    glPolygonMode(GL_FRONT, polyMode[0]);
    glPolygonMode(GL_BACK, polyMode[1]);
    if (cull) {
        glEnable(GL_CULL_FACE);
    }
}

void OctreeNode::UpdatePRec(const QVector3D &np1, const QVector3D &np2) {
    p1 = np1;
    p2 = np2;
}

void OctreeNode::DrawBox() const {
    glBegin(GL_QUADS);
    glVertex3f(p1.x(), p1.y(), p1.z());
    glVertex3f(p1.x(), p2.y(), p1.z());
    glVertex3f(p2.x(), p2.y(), p1.z());
    glVertex3f(p2.x(), p1.y(), p1.z());

    glVertex3f(p2.x(), p2.y(), p2.z());
    glVertex3f(p1.x(), p2.y(), p2.z());
    glVertex3f(p1.x(), p1.y(), p2.z());
    glVertex3f(p2.x(), p1.y(), p2.z());

    glVertex3f(p1.x(), p1.y(), p1.z());
    glVertex3f(p2.x(), p1.y(), p1.z());
    glVertex3f(p2.x(), p1.y(), p2.z());
    glVertex3f(p1.x(), p1.y(), p2.z());

    glVertex3f(p2.x(), p2.y(), p2.z());
    glVertex3f(p2.x(), p2.y(), p1.z());
    glVertex3f(p1.x(), p2.y(), p1.z());
    glVertex3f(p1.x(), p2.y(), p2.z());

    glVertex3f(p1.x(), p1.y(), p1.z());
    glVertex3f(p1.x(), p1.y(), p2.z());
    glVertex3f(p1.x(), p2.y(), p2.z());
    glVertex3f(p1.x(), p2.y(), p1.z());

    glVertex3f(p2.x(), p2.y(), p2.z());
    glVertex3f(p2.x(), p1.y(), p2.z());
    glVertex3f(p2.x(), p1.y(), p1.z());
    glVertex3f(p2.x(), p2.y(), p1.z());
    glEnd();
}
