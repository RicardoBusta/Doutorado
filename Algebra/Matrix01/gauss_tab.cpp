#include "gauss_tab.h"
#include "ui_gauss_tab.h"

GaussTab::GaussTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GaussTab)
{
    ui->setupUi(this);

    QObject::connect(ui->gen_pushButton,SIGNAL(clicked(bool)),this,SLOT(GeneratePressed()));
}

GaussTab::~GaussTab()
{
  delete ui;
}

void GaussTab::GeneratePressed()
{

}

void GaussTab::EliminatePressed()
{

}

void GaussTab::CalculatePressed()
{

}
