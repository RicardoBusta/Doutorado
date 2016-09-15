#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <globaloptions.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  Scene *s = ui->glwidget->GetScene();

  QObject::connect(ui->make_current_parent_checkBox, SIGNAL(toggled(bool)), s, SLOT(UpdateMakeParent(bool)));

  QObject::connect(ui->object_create_button, SIGNAL(clicked(bool)), s, SLOT(CreateObject()));
  QObject::connect(ui->octree_create_button, SIGNAL(clicked(bool)), s, SLOT(CreateOctree()));

  QObject::connect(ui->object_tree,
                   SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)),
                   this,
                   SLOT(SelectObject(QTreeWidgetItem *, QTreeWidgetItem *)));

  QObject::connect(s, SIGNAL(UpdateObjList()), this, SLOT(UpdateObjList()));

  QObject::connect(ui->octree_spread_slider, SIGNAL(valueChanged(int)), s, SLOT(ChangeOctreeSpread(int)));

  QObject::connect(ui->sphere_radioButton, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));
  QObject::connect(ui->cylinder_radioButton, SIGNAL(toggled(bool)), this, SLOT(SelectPrimitiveShape(bool)));

  QObject::connect(ui->pos_x, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->pos_y, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->pos_z, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->rot_x, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->rot_y, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->rot_z, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->sca_x, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->sca_y, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
  QObject::connect(ui->sca_z, SIGNAL(valueChanged(double)), this, SLOT(UpdateCurrentObjectTransform(double)));
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::GetCurrentObjectTransform() {
  Object *obj = ui->glwidget->GetScene()->current_object;
  if (obj == nullptr) {
    return;
  }
  ui->pos_x->setValue(obj->position.x());
  ui->pos_y->setValue(obj->position.y());
  ui->pos_z->setValue(obj->position.z());
}

void AddRecItem(QTreeWidgetItem *item, Object *o) {
  for (Object *co : o->children) {
    QTreeWidgetItem *i = new QTreeWidgetItem();
    i->setText(0, co->name);
    item->addChild(i);

    i->setData(0, Qt::UserRole, (qulonglong)co);

    AddRecItem(i, co);
  }
}

void MainWindow::UpdateObjList() {
  ui->object_tree->blockSignals(true);
  ui->object_tree->clear();
  Scene *s = ui->glwidget->GetScene();
  for (Object *o : s->objects) {
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, o->name);

    item->setData(0, Qt::UserRole, (qulonglong)o);

    ui->object_tree->addTopLevelItem(item);

    AddRecItem(item, o);
  }
  ui->object_tree->expandAll();
  ui->object_tree->blockSignals(false);
  ui->glwidget->update();
}

void MainWindow::SelectObject(QTreeWidgetItem *current, QTreeWidgetItem *previous) {
  Object *obj = (Object *)current->data(0, Qt::UserRole).toULongLong();
  ui->glwidget->GetScene()->current_object = obj;
  qDebug() << ui->glwidget->GetScene()->current_object;
}

void MainWindow::SelectPrimitiveShape(bool checked) {
  if (!checked) {
    return;
  }
  QRadioButton *rb = qobject_cast<QRadioButton *>(QObject::sender());
  if (rb != nullptr) {
    if (rb->text() == "Sphere") {
      GlobalOptions::Instance()->shape = GlobalOptions::Shape::Sphere;
    } else if (rb->text() == "Cylinder") {
      GlobalOptions::Instance()->shape = GlobalOptions::Shape::Cylinder;
    }
  }
  qDebug() << GlobalOptions::Instance()->shape;
}

void MainWindow::UpdateCurrentObjectTransform(double v) {
  Object *obj = ui->glwidget->GetScene()->current_object;
  if (obj == nullptr) {
    return;
  }
  const QObject *s = QObject::sender();
  if (s == ui->pos_x) {
    obj->position.setX(v);
  } else if (s == ui->pos_y) {
    obj->position.setY(v);
  } else if (s == ui->pos_z) {
    obj->position.setZ(v);
  } else if (s == ui->rot_x) {
    obj->rotation.setX(v);
  } else if (s == ui->rot_y) {
    obj->rotation.setY(v);
  } else if (s == ui->rot_z) {
    obj->rotation.setZ(v);
  } else if (s == ui->sca_x) {
    obj->scale.setX(v);
  } else if (s == ui->sca_y) {
    obj->scale.setY(v);
  } else if (s == ui->sca_z) {
    obj->scale.setZ(v);
  }
  ui->glwidget->update();
}
