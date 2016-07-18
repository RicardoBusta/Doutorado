#include "least_square_tab.h"
#include "ui_least_square_tab.h"

LeastSquareTab::LeastSquareTab(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::LeastSquareTab)
{
  ui->setupUi(this);
}

LeastSquareTab::~LeastSquareTab()
{
  delete ui;
}
