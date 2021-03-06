#include "newcsgdialog.h"
#include "ui_newcsgdialog.h"

#include "scene.h"
#include "csg/csgobject.h"
#include "csg/csgsphere.h"
#include "csg/csgcylinder.h"
#include "csg/csgbox.h"
#include "csg/csgcone.h"
#include "csg/csgcylinder.h"
#include "csg/csgprism.h"
#include "csg/csgtorus.h"
#include "csg/csgpyramid.h"
#include "csg/csgoperation.h"

NewCSGDialog::NewCSGDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::NewCSGDialog)
{
  ui->setupUi(this);

  ui->stackedWidget->setCurrentWidget(ui->invalid_page);

  QObject::connect(ui->box_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->cylinder_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->cone_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->torus_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->sphere_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->prism_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->pyramid_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->operation_radio, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
}

NewCSGDialog::~NewCSGDialog()
{
  delete ui;
}

void NewCSGDialog::CreateShape(Scene *scene)
{
  CSGObject * object = nullptr;
  switch (shape) {
  case Sphere:
    object = new CSGSphere(ui->sphere_radius->value()/2.0f);
    break;
  case Cylinder:
    object = new CSGCylinder(ui->cylinder_radius->value()/2.0f, ui->cylinder_height->value());
    break;
  case Box:
    object = new CSGBox(ui->box_w->value(), ui->box_h->value(), ui->box_d->value());
    break;
  case Torus:
    object = new CSGTorus(ui->torus_r1->value()/2.0f, ui->torus_r2->value()/2.0f);
    break;
  case Cone:
    object = new CSGCone(ui->cone_radius->value()/2.0f, ui->cone_height->value());
    break;
  case Pyramid:
    object = new CSGPyramid(ui->pyramid_diameter->value()/2.0f,ui->pyramid_height->value(),ui->pyramid_sides->value());
    break;
  case Prism:
    object = new CSGPrism(ui->prism_diameter->value()/2.0f,ui->prism_height->value(),ui->prism_sides->value());
    break;
  case Operation:
    object = new CSGOPeration(ui->union_radioButton->isChecked()?0:(ui->intersection_radioButton->isChecked()?1:2));
    break;
  default:
    break;
  }
  if(object!=nullptr){
    object->Init();
    scene->CreateObjectGeneric(object);
  }
}

void NewCSGDialog::SelectPrimitiveShape(bool checked)
{
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
    } else if (rb->text() == "Pyramid") {
      ui->stackedWidget->setCurrentWidget(ui->pyramid_page);
      shape = Pyramid;
    } else if (rb->text() == "Prism") {
      ui->stackedWidget->setCurrentWidget(ui->prism_page);
      shape = Prism;
    } else if (rb->text() == "Operation") {
      ui->stackedWidget->setCurrentWidget(ui->operation_page);
      shape = Operation;
    } else {
      ui->stackedWidget->setCurrentWidget(ui->invalid_page);
      shape = Invalid;
    }
  }
}
