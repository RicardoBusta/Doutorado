#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include <QFileDialog>
#include <QColorDialog>

#include "globaloptions.h"
#include "octree/newoctreedialog.h"
#include "octree/operateoctreedialog.h"
#include "csg/newcsgdialog.h"
#include "halfedge/newhedialog.h"
#include "halfedge/halfedgeobject.h"
#include "halfedge/extrudedialog.h"
#include "halfedge/mefdialog.h"
#include "halfedge/mevdialog.h"
#include "halfedge/translatedialog.h"
#include "bezier/newbezierdialog.h"
#include "bezier/bezierobject.h"

const QString colorButtonStyle = "background-color: %1;\nborder: none;";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
  ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new Scene(this);
  ui->glwidget->SetScene(scene);
  //ui->raycastwidget->s = scene;

  QObject::connect(ui->object_create_button, SIGNAL(clicked(bool)), scene, SLOT(CreateObject()));
  QObject::connect(ui->octree_create_button, SIGNAL(clicked(bool)), this, SLOT(CreateOctreePressed()));

  QObject::connect(ui->object_tree,
                   SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem *)),
                   this,
                   SLOT(SelectObject(QTreeWidgetItem *, QTreeWidgetItem *)));

  QObject::connect(scene, SIGNAL(UpdateObjList()), this, SLOT(UpdateObjList()));
  QObject::connect(scene, SIGNAL(UpdateDrawing()), this, SLOT(UpdateDrawing()));

  QObject::connect(ui->octree_spread_slider, SIGNAL(valueChanged(int)), scene, SLOT(ChangeOctreeSpread(int)));

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

  QObject::connect(ui->object_tree, SIGNAL(ChangeParent(QString, QString)), scene, SLOT(Reparent(QString, QString)));

  QObject::connect(ui->delete_object, SIGNAL(clicked(bool)), scene, SLOT(DeleteCurrentObject()));

  QObject::connect(ui->operate_octree_button, SIGNAL(clicked(bool)), this, SLOT(OperateOctreePressed()));

  QObject::connect(ui->save_pushButton,SIGNAL(clicked(bool)),this,SLOT(SaveScenePress()));
  QObject::connect(ui->load_pushButton,SIGNAL(clicked(bool)),this,SLOT(LoadScenePress()));

  QObject::connect(ui->duplicate_button,SIGNAL(clicked(bool)),this,SLOT(DuplicateObjectPressed()));

  QObject::connect(ui->faceColor,SIGNAL(clicked(bool)),this,SLOT(SetFaceColor()));
  QObject::connect(ui->lineColor,SIGNAL(clicked(bool)),this,SLOT(SetLineColor()));

  faceColor = QColor(0,0,0);
  ui->faceColor->setStyleSheet(colorButtonStyle.arg(faceColor.name()));

  lineColor = QColor(255,255,255);
  ui->lineColor->setStyleSheet(colorButtonStyle.arg(lineColor.name()));

  QObject::connect(ui->clear_pushButton,SIGNAL(clicked(bool)),this,SLOT(ClearScene()));

  QObject::connect(ui->create_csg_pushButton,SIGNAL(clicked(bool)),this,SLOT(CreateCSGPressed()));

  QObject::connect(ui->create_he_button,SIGNAL(clicked(bool)),this,SLOT(CreateHEPressed()));

  QObject::connect(ui->edge_spinBox,SIGNAL(valueChanged(int)),this,SLOT(UpdateCurrentObjectHE()));
  //QObject::connect(ui->face_spinBox,SIGNAL(valueChanged(int)),this,SLOT(UpdateCurrentObjectHE()));

//  QObject::connect(ui->face_pushButton,SIGNAL(clicked(bool)),this,SLOT(GetEdgeFace()));
  QObject::connect(ui->next_pushButton,SIGNAL(clicked(bool)),this,SLOT(GetNextEdge()));
  QObject::connect(ui->mate_pushButton,SIGNAL(clicked(bool)),this,SLOT(GetMateEdge()));

  QObject::connect(ui->mef,SIGNAL(clicked(bool)),this,SLOT(MEF()));
  QObject::connect(ui->mev,SIGNAL(clicked(bool)),this,SLOT(MEV()));
  QObject::connect(ui->translate,SIGNAL(clicked(bool)),this,SLOT(Translate()));
  QObject::connect(ui->extrude,SIGNAL(clicked(bool)),this,SLOT(Extrude()));

  QObject::connect(ui->create_bezier_button,SIGNAL(clicked(bool)),this,SLOT(CreateBezierPressed()));

  QObject::connect(ui->bezi,SIGNAL(valueChanged(int)),this,SLOT(SelectBezierControl()));
  QObject::connect(ui->bezj,SIGNAL(valueChanged(int)),this,SLOT(SelectBezierControl()));
  QObject::connect(ui->bezx,SIGNAL(valueChanged(double)),this,SLOT(SelectBezierPosition()));
  QObject::connect(ui->bezy,SIGNAL(valueChanged(double)),this,SLOT(SelectBezierPosition()));
  QObject::connect(ui->bezz,SIGNAL(valueChanged(double)),this,SLOT(SelectBezierPosition()));

  ui->specific_stackedWidget->setCurrentWidget(ui->default_page);
}

MainWindow::~MainWindow() {
  delete scene;
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
  QTreeWidgetItem *currentItem = nullptr;
  for (Object *o : scene->objects) {
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, o->getName());

    if (scene->current_object != nullptr && o->getName() == scene->current_object->getName()) {
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

  if(scene->current_object==nullptr){
    ui->obj_content->setEnabled(false);
  }
}

void MainWindow::UpdateDrawing() {
  ui->glwidget->update();
  //ui->raycastwidget->repaint();
}

void MainWindow::SelectObject(QTreeWidgetItem *current, QTreeWidgetItem *previous) {
  Object *obj = (Object *)current->data(0, Qt::UserRole).toULongLong();
  scene->current_object = obj;

  QVector<QWidget*> value_widgets = {
    ui->pos_x,ui->pos_y,ui->pos_z,
    ui->rot_x,ui->rot_y,ui->rot_z,
    ui->sca_x,ui->sca_y,ui->sca_z,
    ui->hide_checkBox,ui->lines_checkBox,
    ui->name_lineEdit,ui->faceColor,ui->lineColor
  };

  if (obj != nullptr) {
    ui->obj_content->setEnabled(true);
    foreach (QWidget*w, value_widgets) {
      w->blockSignals(true);
    }
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

    faceColor = obj->getFaceColor();
    ui->faceColor->setStyleSheet(colorButtonStyle.arg(faceColor.name()));

    lineColor = obj->getLineColor();
    ui->lineColor->setStyleSheet(colorButtonStyle.arg(lineColor.name()));

    Octree * octree = dynamic_cast<Octree*>(obj);
    if(octree!=nullptr){
      ui->specific_stackedWidget->setCurrentWidget(ui->octree_page);
      goto ok;
    }
    HalfEdgeObject * halfedge = dynamic_cast<HalfEdgeObject*>(obj);
    if(halfedge!=nullptr){
      ui->specific_stackedWidget->setCurrentWidget(ui->halfedge_page);
      goto ok;
    }
    BezierObject *bezier = dynamic_cast<BezierObject*>(obj);
    if(bezier!=nullptr){
      ui->specific_stackedWidget->setCurrentWidget(ui->bezier_page);
      goto ok;
    }
    ui->specific_stackedWidget->setCurrentWidget(ui->default_page);

    ok:

    foreach (QWidget*w, value_widgets) {
      w->blockSignals(false);
    }
  } else {
    ui->obj_content->setEnabled(false);
  }
}

void MainWindow::UpdateCurrentObjectTransform(double v) {
  Object *obj = scene->current_object;
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
  Object *obj = scene->current_object;
  if (obj == nullptr) {
    return;
  }
  obj->Rename(name);
  UpdateObjList();
}

void MainWindow::UpdateCurrentObjectCheck(bool value) {
  Object *obj = scene->current_object;
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

void MainWindow::UpdateCurrentObjectHE()
{
  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }
  obj->selected_edge = ui->edge_spinBox->value();
  ui->face_spinBox->setValue(obj->edges[obj->selected_edge].face);
  ui->glwidget->update();
}

void MainWindow::GetNextEdge()
{
  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }
  if(obj->selected_edge>=0 && obj->selected_edge < obj->edges.size()){
    ui->edge_spinBox->setValue(obj->edges[obj->selected_edge].next);
    ui->face_spinBox->setValue(obj->edges[obj->selected_edge].face);
  }
}

void MainWindow::GetMateEdge()
{
  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }
  if(obj->selected_edge>=0 && obj->selected_edge < obj->edges.size()){
    ui->edge_spinBox->setValue(obj->edges[obj->selected_edge].mate);
    ui->face_spinBox->setValue(obj->edges[obj->selected_edge].face);
  }
}

//void MainWindow::GetEdgeFace()
//{
//  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
//  if (obj == nullptr) {
//    return;
//  }
//  if(obj->selected_edge>=0 && obj->selected_edge < obj->edges.size()){
//    ui->face_spinBox->setValue(obj->edges[obj->selected_edge].face);
//  }
//}

void MainWindow::CreateOctreePressed() {
  NewOctreeDialog dialog;
  int result = dialog.exec();
  if (result == QDialog::Accepted) {
    dialog.CreateShape(scene);
  }
}

void MainWindow::OperateOctreePressed() {
  OperateOctreeDialog dialog(scene);
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    dialog.Operate();
    UpdateObjList();
  }
}

void MainWindow::CreateBezierPressed()
{
  NewBezierDialog dialog;
  int result = dialog.exec();
  if (result == QDialog::Accepted) {
    dialog.Create(scene);
  }
}

void MainWindow::SelectBezierControl()
{
  BezierObject *obj = dynamic_cast<BezierObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }

  int i = ui->bezi->value();
  int j = ui->bezj->value();

  if(i<0 || i>=obj->control_points.size() ||
     j<0 || j>=obj->control_points[0].size()){
    return;
  }

  obj->current_cp_x = i;
  obj->current_cp_y = j;

  ui->bezx->blockSignals(true);
  ui->bezy->blockSignals(true);
  ui->bezz->blockSignals(true);

  ui->bezx->setValue(obj->control_points[i][j].x());
  ui->bezy->setValue(obj->control_points[i][j].y());
  ui->bezz->setValue(obj->control_points[i][j].z());

  ui->bezx->blockSignals(false);
  ui->bezy->blockSignals(false);
  ui->bezz->blockSignals(false);

  UpdateDrawing();
}

void MainWindow::SelectBezierPosition()
{
  qDebug() << "pos";
  BezierObject *obj = dynamic_cast<BezierObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }

  int i = ui->bezi->value();
  int j = ui->bezj->value();

  if(i<0 || i>=obj->control_points.size() ||
     j<0 || j>=obj->control_points[0].size()){
    return;
  }

  obj->control_points[i][j] = QVector3D(ui->bezx->value(),ui->bezy->value(),ui->bezz->value());
  obj->Calc();
  UpdateDrawing();
}

void MainWindow::CreateHEPressed()
{
  NewHEDialog dialog;
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    dialog.CreateHE(scene);
  }
}

void MainWindow::Extrude()
{
  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }
  ExtrudeDialog dialog;
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    qDebug() << "Extrude";
    dialog.Apply(obj);
  }
}

void MainWindow::MEF()
{
  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }
  MEFDialog dialog;
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    dialog.Apply(obj);
  }
}

void MainWindow::MEV()
{
  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }
  MEVDialog dialog;
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    dialog.Apply(obj);
  }
}

void MainWindow::Translate()
{
  HalfEdgeObject *obj = dynamic_cast<HalfEdgeObject*>(scene->current_object);
  if (obj == nullptr) {
    return;
  }
  TranslateDialog dialog;
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    dialog.Apply(obj);
  }
}

void MainWindow::CreateCSGPressed()
{
  NewCSGDialog dialog;
  int result = dialog.exec();
  if(result == QDialog::Accepted){
    dialog.CreateShape(scene);
  }
}

void MainWindow::DuplicateObjectPressed()
{
  Object * obj = scene->current_object->Duplicate();
  scene->CreateObjectGeneric(obj);
}

void MainWindow::SaveScenePress()
{
  QString filename = QFileDialog::getSaveFileName(this,"Save Scene",".","Text (*.txt)");
  if(filename.isEmpty()){
    return;
  }
  QFile file(filename);
  if(!file.open(QFile::WriteOnly|QFile::Text)){
    return;
  }

  QTextStream out(&file);

  Scene *s = scene;
  foreach(Object * o , s->objects){
    out << o->Save();
  }

}

void MainWindow::LoadScenePress()
{
  QString filename = QFileDialog::getOpenFileName(this,"Load Scene",".","Text (*.txt)");
  if(filename.isEmpty()){
    return;
  }
  QFile file(filename);
  if(!file.open(QFile::ReadOnly|QFile::Text)){
    return;
  }
  QTextStream in(&file);

  while(!in.atEnd()){
    QString line = in.readLine();
    scene->AddObjectFromString(line);
  }
}

void MainWindow::SetFaceColor()
{
  Object *obj = scene->current_object;
  if(obj==nullptr){
    return;
  }
  faceColor = QColorDialog::getRgba(faceColor.rgba());
  ui->faceColor->setStyleSheet(colorButtonStyle.arg(faceColor.name()));
  obj->setFaceColor(faceColor);
  UpdateDrawing();
}

void MainWindow::SetLineColor()
{
  Object *obj = scene->current_object;
  if(obj==nullptr){
    return;
  }
  lineColor = QColorDialog::getRgba(lineColor.rgba());
  ui->lineColor->setStyleSheet(colorButtonStyle.arg(lineColor.name()));
  obj->setLineColor(lineColor);
  UpdateDrawing();
}

void MainWindow::ClearScene()
{
  foreach(Object *s, scene->objects){
    delete s;
  }
  scene->objects.clear();
  UpdateObjList();
}

