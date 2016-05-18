#include "cholesky_tab.h"
#include "ui_cholesky_tab.h"

CholeskyTab::CholeskyTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CholeskyTab)
{
    ui->setupUi(this);

    QObject::connect(ui->gen)
}

CholeskyTab::~CholeskyTab()
{
  delete ui;
}

void CholeskyTab::GenerateClicked()
{

}
