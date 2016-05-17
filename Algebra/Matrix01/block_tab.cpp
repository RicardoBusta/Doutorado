#include "block_tab.h"
#include "ui_block_tab.h"

BlockTab::BlockTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockTab)
{
    ui->setupUi(this);
}

BlockTab::~BlockTab()
{
    delete ui;
}
