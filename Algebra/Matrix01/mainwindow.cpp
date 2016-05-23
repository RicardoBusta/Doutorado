#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "block_tab.h"
#include "cholesky_tab.h"
#include "gauss_tab.h"
#include "lu_tab.h"
#include "performance_tab.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->tabWidget->addTab(new PerformanceTab(this), QString("Desempenho"));
  ui->tabWidget->addTab(new BlockTab(this), QString("Bloco"));
  ui->tabWidget->addTab(new GaussTab(this), QString("Gauss"));
  ui->tabWidget->addTab(new LUTab(this), QString("LU"));
  ui->tabWidget->addTab(new CholeskyTab(this), QString("Cholesky"));

  showMaximized();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::ErrorMessage(const QString &message) {
  QMessageBox msg;
  msg.setText(message);
  msg.exec();
}
