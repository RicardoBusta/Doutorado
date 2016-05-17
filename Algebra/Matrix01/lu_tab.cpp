#include "lu_tab.h"
#include "ui_lu_tab.h"

LUTab::LUTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LUTab)
{
    ui->setupUi(this);
}

LUTab::~LUTab()
{
    delete ui;
}
