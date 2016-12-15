#include "mefdialog.h"
#include "ui_mefdialog.h"

#include "halfedge/halfedgeobject.h"

MEFDialog::MEFDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MEFDialog)
{
  ui->setupUi(this);
}

MEFDialog::~MEFDialog()
{
  delete ui;
}

void MEFDialog::Apply(HalfEdgeObject *he)
{
  he->MEF(ui->id1->value(),ui->id2->value());
}
