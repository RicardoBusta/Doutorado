#include "newoctreedialog.h"
#include "ui_newoctreedialog.h"

#include "globaloptions.h"
#include "octree.h"
#include "scene.h"
#include <QDebug>

#include <QColorDialog>

NewOctreeDialog::NewOctreeDialog(QWidget *parent) : QDialog(parent),
                                                    ui(new Ui::NewOctreeDialog),
                                                    shape(Invalid) {
  ui->setupUi(this);

  ui->stackedWidget->setCurrentWidget(ui->invalid_page);

  QObject::connect(ui->box_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->cylinder_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->cone_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->torus_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->sphere_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));

  QObject::connect(ui->lineColor,SIGNAL(clicked(bool)),this,SLOT(SelectLineColor()));
  QObject::connect(ui->faceColor,SIGNAL(clicked(bool)),this,SLOT(SelectFaceColor()));
}

NewOctreeDialog::~NewOctreeDialog() {
  delete ui;
}

void NewOctreeDialog::CreateShape(Scene *scene) {
  if (shape == Invalid) {
    return;
  }

  Octree *octree = new Octree(nullptr, line, face);

  int max_d = ui->tree_depth->value();

  switch (shape) {
  case Sphere:
    octree->GenSphere(ui->sphere_radius->value(), QVector3D(0, 0, 0), max_d);
    break;
  case Cylinder:
    octree->GenCylinder(ui->cylinder_radius->value(), ui->cylinder_height->value(), QVector3D(0, 0, 0), max_d);
    break;
  case Box:
    octree->GenBox(ui->box_w->value(), ui->box_h->value(), ui->box_d->value(), QVector3D(0, 0, 0), max_d);
    break;
  case Torus:
    octree->GenTorus(ui->torus_r1->value(), ui->torus_r2->value(), QVector3D(0, 0, 0), max_d);
    break;
  case Cone:
    octree->GenCone(ui->cone_radius->value(), ui->cone_height->value(), QVector3D(0, 0, 0), max_d);
    break;
  default:
    break;
  }
  octree->UpdateP();
  if (octree != nullptr) {
    scene->CreateObjectGeneric(octree);
  }
}

void NewOctreeDialog::SelectPrimitiveShape(bool checked) {
  if (!checked) {
    return;
  }
  QRadioButton *rb = qobject_cast<QRadioButton *>(QObject::sender());
  if (rb != nullptr) {
    if (rb->text() == "Sphere") {
      ui->stackedWidget->setCurrentWidget(ui->sphere_page);
      shape = Sphere;
    } else if (rb->text() == "Cylinder") {
      ui->stackedWidget->setCurrentWidget(ui->cylinder_page);
      shape = Cylinder;
    } else if (rb->text() == "Box") {
      ui->stackedWidget->setCurrentWidget(ui->box_page);
      shape = Box;
    } else if (rb->text() == "Cone") {
      ui->stackedWidget->setCurrentWidget(ui->cone_page);
      shape = Cone;
    } else if (rb->text() == "Torus") {
      ui->stackedWidget->setCurrentWidget(ui->torus_page);
      shape = Torus;
    } else {
      ui->stackedWidget->setCurrentWidget(ui->invalid_page);
      shape = Invalid;
    }
  }
  qDebug() << shape;
}

void NewOctreeDialog::SelectFaceColor()
{
face = QColorDialog::getRgba();
}

void NewOctreeDialog::SelectLineColor()
{
line = QColorDialog::getRgba();
}
