#include "operateoctreedialog.h"
#include "ui_operateoctreedialog.h"

#include "scene.h"
#include "octree.h"
#include "object/object.h"
#include "octree/octreeunion.h"
#include "octree/octreetorus.h"

#include <QColorDialog>

const QString colorButtonStyle = "background-color: %1;\nborder: none;";

OperateOctreeDialog::OperateOctreeDialog(Scene *scene, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OperateOctreeDialog),
  scene(scene)
{
  ui->setupUi(this);

  foreach(Object *o ,scene->objects){
    GetOctreesRec(o);
  }

  faceColor = QColor(150,0,0);
  lineColor = QColor(255,255,255);

  ui->faceColor->setStyleSheet(colorButtonStyle.arg(faceColor.name()));
  ui->lineColor->setStyleSheet(colorButtonStyle.arg(lineColor.name()));

  QObject::connect(ui->faceColor,SIGNAL(clicked(bool)),this,SLOT(SelectFaceColor()));
  QObject::connect(ui->lineColor,SIGNAL(clicked(bool)),this,SLOT(SelectLineColor()));
}

OperateOctreeDialog::~OperateOctreeDialog()
{
    delete ui;
}

void OperateOctreeDialog::Operate() {
    Octree * oct1 = objects_ref[ui->operand_1_comboBox->currentIndex()];
    Octree * oct2 = objects_ref[ui->operand_2_comboBox->currentIndex()];
    if(oct1==oct2){
        return;
    }

    int ope = ui->operation_comboBox->currentIndex()-1;

    if(ope<0){
      return;
    }

    // Both objects are octrees. Get the limits of both of them.
    float max_x = qMax(oct1->bb1.x(),qMax(oct1->bb2.x(),qMax(oct2->bb1.x(),oct2->bb2.x())));
    float max_y = qMax(oct1->bb1.y(),qMax(oct1->bb2.y(),qMax(oct2->bb1.y(),oct2->bb2.y())));
    float max_z = qMax(oct1->bb1.z(),qMax(oct1->bb2.z(),qMax(oct2->bb1.z(),oct2->bb2.z())));
    float min_x = qMin(oct1->bb1.x(),qMin(oct1->bb2.x(),qMin(oct2->bb1.x(),oct2->bb2.x())));
    float min_y = qMin(oct1->bb1.y(),qMin(oct1->bb2.y(),qMin(oct2->bb1.y(),oct2->bb2.y())));
    float min_z = qMin(oct1->bb1.z(),qMin(oct1->bb2.z(),qMin(oct2->bb1.z(),oct2->bb2.z())));

    // Get the biggest side
    float side = qMax(max_x-min_x,qMax(max_y-min_y,max_z-min_z));
    QVector3D center = QVector3D(max_x+min_x,max_y+min_y,max_z+min_z);
    center = center/2.0f;

    QVector3D p1 = center + QVector3D(-side,side,side)/2;
    QVector3D p2 = center + QVector3D(side,-side,-side)/2;
    OctreeUnion oper(oct1,oct2,p1,p2,ope);
    //OctreeTorus oper(1,1,QVector3D(0,0,0));
    //OctreeNode * op = oper.GenRecur(5,0);
    OctreeNode * op = oper.GenRec(ui->depth_spinBox->value(),0,side/2,p1,p2);
    //op->UpdatePRec(p1,p2);

    Octree * newoct = new Octree("Operated",op,faceColor.rgba(),lineColor.rgba());
    newoct->SetP(p1,p2);
    scene->CreateObjectGeneric(newoct);
}

void OperateOctreeDialog::GetOctreesRec(Object *obj)
{
  Octree * oct = dynamic_cast<Octree*>(obj);
  if(oct!=nullptr){
    ui->operand_1_comboBox->addItem(oct->getName());
    ui->operand_2_comboBox->addItem(oct->getName());
    objects_ref.push_back(oct);
  }
  foreach(Object *o, obj->children){
    GetOctreesRec(o);
  }
}

void OperateOctreeDialog::SelectFaceColor()
{
  faceColor = QColorDialog::getRgba(faceColor.rgba());
  ui->faceColor->setStyleSheet(colorButtonStyle.arg(faceColor.name()));
}

void OperateOctreeDialog::SelectLineColor()
{
  lineColor = QColorDialog::getRgba(lineColor.rgba());
  ui->lineColor->setStyleSheet(colorButtonStyle.arg(lineColor.name()));
}
