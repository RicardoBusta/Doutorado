#include "gauss_tab.h"
#include "ui_gauss_tab.h"

#include "mainwindow.h"

GaussTab::GaussTab(MainWindow *w, QWidget *parent) : QWidget(parent),
                                      ui(new Ui::GaussTab) {
  ui->setupUi(this);

  QObject::connect(ui->gen_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
  QObject::connect(this,SIGNAL(Error(QString)),w,SLOT(ErrorMessage(QString)));
}

GaussTab::~GaussTab() {
  delete ui;
}

void GaussTab::GeneratePressed() {
  emit Error("Não Implementado");
}

void GaussTab::EliminatePressed() {
  emit Error("Não Implementado");
}

void GaussTab::CalculatePressed() {
  emit Error("Não Implementado");
}
