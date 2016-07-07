#include "matrix_norm_tab.h"
#include "ui_matrix_norm_tab.h"

MatrixNormTab::MatrixNormTab(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::MatrixNormTab) {
  ui->setupUi(this);
}

MatrixNormTab::~MatrixNormTab() {
  delete ui;
}
