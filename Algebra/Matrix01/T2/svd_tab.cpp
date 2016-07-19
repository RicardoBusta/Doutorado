#include "svd_tab.h"
#include "ui_svd_tab.h"

SVDTab::SVDTab(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::SVDTab) {
  ui->setupUi(this);
}

SVDTab::~SVDTab() {
  delete ui;
}
