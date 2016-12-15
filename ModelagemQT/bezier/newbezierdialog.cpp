#include "newbezierdialog.h"
#include "ui_newbezierdialog.h"

#include "scene.h"
#include "bezier/bezierobject.h"

NewBezierDialog::NewBezierDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::NewBezierDialog)
{
  ui->setupUi(this);
}

NewBezierDialog::~NewBezierDialog()
{
  delete ui;
}

void NewBezierDialog::Create(Scene *scene)
{
  BezierObject * object = nullptr;

  object = new BezierObject(ui->x->value(),ui->y->value());

  if(object!=nullptr){
    scene->CreateObjectGeneric(object);
  }
}
