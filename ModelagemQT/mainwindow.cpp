#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

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
  qDebug()<< "Whoa";
}

MainWindow::~MainWindow() {
  delete ui;
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
  Object * obj = (Object*)current->data(0,Qt::UserRole).toULongLong();
  ui->glwidget->GetScene()->current_object = obj;
  qDebug() << ui->glwidget->GetScene()->current_object;
}
