#include "cholesky_tab.h"
#include "ui_cholesky_tab.h"

CholeskyTab::CholeskyTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CholeskyTab)
{
    ui->setupUi(this);
}

CholeskyTab::~CholeskyTab()
{
    delete ui;
}
