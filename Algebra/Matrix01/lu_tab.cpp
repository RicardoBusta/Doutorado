#include "lu_tab.h"
#include "ui_lu_tab.h"

LUTab::LUTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LUTab)
{
    ui->setupUi(this);

    QObject::connect(ui->gen_pushButton,SIGNAL(clicked(bool)),this,SLOT(GeneratePressed()));
}

LUTab::~LUTab()
{
  delete ui;
}

void LUTab::GeneratePressed()
{

}

void LUTab::DecomposePressed()
{

}
