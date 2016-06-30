#include "vector_norm_tab.h"
#include "ui_vector_norm_tab.h"

VectorNormTab::VectorNormTab(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::VectorNormTab)
{
  ui->setupUi(this);
}

VectorNormTab::~VectorNormTab()
{
  delete ui;
}
