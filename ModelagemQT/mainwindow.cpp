#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <QFileDialog>

#include "globaloptions.h"
#include "octree/newoctreedialog.h"
#include "octree/operateoctreedialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  Scene *s = ui->glwidget->GetScene();

  //QObject::connect(ui->make_current_parent_checkBox, SIGNAL(toggled(bool)), s, SLOT(UpdateMakeParent(bool)));

  QObject::connect(ui->object_create_button, SIGNAL(clicked(bool)), s, SLOT(CreateObject()));
  QObject::connect(ui->octree_create_button, SIGNAL(clicked(bool)), this, SLOT(CreateOctreePressed()));

  QObject::connect(ui->object_tree,
                   SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)),
                   this,
                   SLOT(SelectObject(QTreeWidgetItem *, QTreeWidgetItem *)));

  QObject::connect(s, SIGNAL(UpdateObjList()), this, SLOT(UpdateObjList()));
  QObject::connect(s, SIGNAL(UpdateDrawing()), this, SLOT(UpdateDrawing()));

  QObject::connect(ui->octree_spread_slider, SIGNAL(valueChanged(int)), s, SLOT(ChangeOctreeSpread(int)));

  QObject::connect(ui->pos_x, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->pos_y, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->pos_z, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->rot_x, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->rot_y, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->rot_z, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->sca_x, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->sca_y, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->sca_z, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));

  QObject::connect(ui->name_lineEdit, SIGNAL(textEdited(QString)), this, SLOT(UpdateCurrentObjectName(QString)));
  QObject::connect(ui->lines_checkBox, SIGNAL(toggled(bool)), this, SLOT(UpdateCurrentObjectCheck(bool)));
  QObject::connect(ui->hide_checkBox, SIGNAL(toggled(bool)), this, SLOT(UpdateCurrentObjectCheck(bool)));

  ui->obj_content->setEnabled(false);

  QObject::connect(ui->object_tree, SIGNAL(ChangeParent(QString, QString)), s, SLOT(Reparent(QString, QString)));

  QObject::connect(ui->delete_object, SIGNAL(clicked(bool)), s, SLOT(DeleteCurrentObject()));

  QObject::connect(ui->operate_octree_button, SIGNAL(clicked(bool)), this, SLOT(OperateOctreePressed()));

  QObject::connect(ui->save_pushButton,SIGNAL(clicked(bool)),this,SLOT(SaveScenePress()));
  QObject::connect(ui->load_pushButton,SIGNAL(clicked(bool)),this,SLOT(LoadScenePress()));
}

MainWindow::~MainWindow() {
  delete ui;
}

void AddRecItem(QTreeWidgetItem *item, Object *o) {
  for (Object *co : o->children) {
    QTreeWidgetItem *i = new QTreeWidgetItem();
    i->setText(0, co->getName());
    item->addChild(i);

    i->setData(0, Qt::UserRole, (qulonglong)co);

    AddRecItem(i, co);
  }
}

void MainWindow::UpdateObjList() {
  ui->object_tree->blockSignals(true);
  ui->object_tree->clear();
  Scene *s = ui->glwidget->GetScene();
  QTreeWidgetItem *currentItem = nullptr;
  for (Object *o : s->objects) {
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, o->getName());

    if (s->current_object != nullptr && o->getName() == s->current_object->getName()) {
      currentItem = item;
    }

    item->setData(0, Qt::UserRole, (qulonglong)o);

    ui->object_tree->addTopLevelItem(item);

    AddRecItem(item, o);
  }
  ui->object_tree->expandAll();
  if (currentItem != nullptr) {
    ui->object_tree->setCurrentItem(currentItem);
  }
  ui->object_tree->blockSignals(false);
  ui->glwidget->update();
}

void MainWindow::UpdateDrawing() {
  ui->glwidget->update();
}

void MainWindow::SelectObject(QTreeWidgetItem *current, QTreeWidgetItem *previous) {
  Object *obj = (Object *)current->data(0, Qt::UserRole).toULongLong();
  ui->glwidget->GetScene()->current_object = obj;

  if (obj != nullptr) {
    ui->obj_content->setEnabled(true);
    ui->pos_x->setValue(obj->getPosition().x());
    ui->pos_y->setValue(obj->getPosition().y());
    ui->pos_z->setValue(obj->getPosition().z());
    ui->rot_x->setValue(obj->getRotation().x());
    ui->rot_y->setValue(obj->getRotation().y());
    ui->rot_z->setValue(obj->getRotation().z());
    ui->sca_x->setValue(obj->getScale().x());
    ui->sca_y->setValue(obj->getScale().y());
    ui->sca_z->setValue(obj->getScale().z());

    ui->hide_checkBox->setChecked(obj->hide);
    ui->lines_checkBox->setChecked(obj->line);

    ui->name_lineEdit->setText(obj->getName());
  } else {
    ui->obj_content->setEnabled(false);
  }
}

void MainWindow::UpdateCurrentObjectTransform(double v) {
  Object *obj = ui->glwidget->GetScene()->current_object;
  if (obj == nullptr) {
    return;
  }
  const QObject *s = QObject::sender();
  if (s == ui->pos_x || s==ui->pos_y || s==ui->pos_z) {
      obj->setPosition(ui->pos_x->value(),ui->pos_y->value(),ui->pos_z->value());
  }else if(s == ui->rot_x || s==ui->rot_y || s==ui->rot_z) {
      obj->setRotation(ui->rot_x->value(),ui->rot_y->value(),ui->rot_z->value());
  }else if(s == ui->sca_x || s==ui->sca_y || s==ui->sca_z) {
      obj->setScale(ui->sca_x->value(),ui->sca_y->value(),ui->sca_z->value());
  }
  ui->glwidget->update();
}

void MainWindow::UpdateCurrentObjectName(QString name) {
  Object *obj = ui->glwidget->GetScene()->current_object;
  if (obj == nullptr) {
    return;
  }
  obj->Rename(name);
  UpdateObjList();
}

void MainWindow::UpdateCurrentObjectCheck(bool value) {
  Object *obj = ui->glwidget->GetScene()->current_object;
  if (obj == nullptr) {
    return;
  }
  const QObject *s = QObject::sender();
  if (s == ui->hide_checkBox) {
    obj->hide = value;
  } else if (s == ui->lines_checkBox) {
    obj->line = value;
  }
  ui->glwidget->update();
}

void MainWindow::CreateOctreePressed() {
  NewOctreeDialog dialog;
  int result = dialog.exec();
  if (result == QDialog::Accepted) {
    dialog.CreateShape(ui->glwidget->GetScene());
  }
}

void MainWindow::OperateOctreePressed() {
  OperateOctreeDialog dialog(ui->glwidget->GetScene());
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    dialog.Operate();
    UpdateObjList();
  }
}

void MainWindow::SaveScenePress()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save Scene",".","Scene (*.scene)");
    if(filename){

    }
}

void MainWindow::LoadScenePress()
{
    QString filename = QFileDialog::getOpenFileName(this,"Load Scene",".","Scene (*.scene)");
    if(filename){

    }
}

