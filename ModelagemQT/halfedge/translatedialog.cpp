#include "translatedialog.h"
#include "ui_translatedialog.h"

#include "halfedge/halfedgeobject.h"

TranslateDialog::TranslateDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::TranslateDialog)
{
  ui->setupUi(this);
}

TranslateDialog::~TranslateDialog()
{
  delete ui;
}

void TranslateDialog::Apply(HalfEdgeObject *he)
{
  QVector3D displacement = QVector3D(ui->x->value(),ui->y->value(),ui->z->value());
  int id = ui->id->value();
  if(ui->face->isChecked()){
    if(id>=0 && id < he->faceCount){
      int e0 = he->faces[id];
      int e = he->edges[e0].next;
      he->vertices[he->edges[e0].Sv] += displacement;
      while(e!=e0){
        he->vertices[he->edges[e].Sv] += displacement;
        e = he->edges[e].next;
      }
    }
  }else if(ui->edge->isChecked()){
    if(id >=0 && id<he->edgeCount) {
      he->vertices[he->edges[id].Sv] += displacement;
      he->vertices[he->edges[id].Ev] += displacement;
    }
  }else if(ui->vertex->isChecked()){
    if(id>=0 && id < he->verticeCount) {
      he->vertices[id] += displacement;
    }
  }
}
