#include "mevdialog.h"
#include "ui_mevdialog.h"

#include "halfedge/halfedgeobject.h"

MEVDialog::MEVDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MEVDialog)
{
  ui->setupUi(this);
}

MEVDialog::~MEVDialog()
{
  delete ui;
}

void MEVDialog::Apply(HalfEdgeObject *he)
{
  QVector3D v = QVector3D(ui->x->value(),ui->y->value(),ui->z->value());
  he->MEV(ui->id->value(),v);
}
