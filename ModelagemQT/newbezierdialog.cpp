#include "newbezierdialog.h"
#include "ui_newbezierdialog.h"

NewBezierDialog::NewBezierDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::NewBezierDialog)
{
  ui->setupUi(this);
}

NewBezierDialog::~NewBezierDialog()
{
  delete ui;
}
