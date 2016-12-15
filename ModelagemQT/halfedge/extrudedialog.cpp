#include "extrudedialog.h"
#include "ui_extrudedialog.h"

#include "halfedge/halfedgeobject.h"

ExtrudeDialog::ExtrudeDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ExtrudeDialog)
{
  ui->setupUi(this);
}

ExtrudeDialog::~ExtrudeDialog()
{
  delete ui;
}

void ExtrudeDialog::Apply(HalfEdgeObject *he)
{
  he->ExtrudeFace(ui->face->value(),QVector3D(ui->x->value(),ui->y->value(),ui->z->value()));
}
