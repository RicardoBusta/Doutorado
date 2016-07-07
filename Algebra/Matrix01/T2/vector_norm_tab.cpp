#include "vector_norm_tab.h"
#include "ui_vector_norm_tab.h"

VectorNormTab::VectorNormTab(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::VectorNormTab) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GenerateVector()));
  QObject::connect(ui->calc_pushButton, SIGNAL(clicked(bool)), this, SLOT(Calculate()));
}

VectorNormTab::~VectorNormTab() {
  delete ui;
}

void VectorNormTab::GenerateVector() {
  int vector_size = ui->vsize_spinBox->value();

}

void VectorNormTab::Calculate() {
}
