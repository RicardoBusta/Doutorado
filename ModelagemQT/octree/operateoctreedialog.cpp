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

  foreach(Object *o ,scene->objects){
    GetOctreesRec(o);
  }
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


    OctreeEmpty * root = new OctreeEmpty();
    root->p1 = center + QVector3D(-side,side,side)/2;
    root->p2 = center + QVector3D(side,-side,-side)/2;
    Octree * newoct = new Octree("Operated",root,0x00ff00,0xffff00);
    scene->objects.push_back(newoct);
}

void OperateOctreeDialog::GetOctreesRec(Object *obj)
{
  Octree * oct = dynamic_cast<Octree*>(obj);
  if(oct!=nullptr){
    ui->operand_1_comboBox->addItem(oct->getName());
    ui->operand_2_comboBox->addItem(oct->getName());
    objects_ref.push_back(oct);
  }
  foreach(Object *o, oct->children){
    GetOctreesRec(o);
  }
}
