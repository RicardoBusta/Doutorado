#include "gauss_tab.h"
#include "ui_gauss_tab.h"

GaussTab::GaussTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GaussTab)
{
    ui->setupUi(this);
}

GaussTab::~GaussTab()
{
    delete ui;
}
