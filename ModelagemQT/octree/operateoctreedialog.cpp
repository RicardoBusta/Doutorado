#include "operateoctreedialog.h"
#include "ui_operateoctreedialog.h"

#include "scene.h"
#include "octree.h"
#include "object/object.h"

OperateOctreeDialog::OperateOctreeDialog(Scene *scene, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OperateOctreeDialog),
  scene(scene)
{
  ui->setupUi(this);

//  foreach(Object *o ,scene->objects){
//    GetOctreesRec(o);
//  }
}

OperateOctreeDialog::~OperateOctreeDialog()
{
  delete ui;
}

void OperateOctreeDialog::GetOctreesRec(Object *obj)
{
  Octree * oct = dynamic_cast<Octree*>(obj);
  if(oct!=nullptr){
    ui->operand_1_comboBox->addItem(oct->getName());
    ui->operand_2_comboBox->addItem(oct->getName());
  }
//  foreach(Object *o, oct->children){
//    GetOctreesRec(o);
//  }
}
