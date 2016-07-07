#include "qr_tab.h"
#include "ui_qr_tab.h"

QRTab::QRTab(QWidget *parent) : QWidget(parent),
                                ui(new Ui::QRTab) {
  ui->setupUi(this);
}

QRTab::~QRTab() {
  delete ui;
}
