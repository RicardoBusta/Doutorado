#include "cholesky_tab.h"
#include "ui_cholesky_tab.h"

CholeskyTab::CholeskyTab(QWidget *parent) : QWidget(parent),
                                            ui(new Ui::CholeskyTab) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateClicked()));
  QObject::connect(ui->deco_pushButton, SIGNAL(clicked(bool)), this, SLOT(DecomposeClicked()));
}

CholeskyTab::~CholeskyTab() {
  delete ui;
}

void CholeskyTab::GenerateClicked() {
}

void CholeskyTab::DecomposeClicked() {
}
