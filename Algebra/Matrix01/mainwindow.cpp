#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "T1/block_tab.h"
#include "T1/cholesky_tab.h"
#include "T1/gauss_tab.h"
#include "T1/lu_tab.h"
#include "T1/performance_tab.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // T1 Tabs
  ui->tabWidget->addTab(new PerformanceTab(this), QString("T1 Desempenho"));
  ui->tabWidget->addTab(new BlockTab(this), QString("T1 Bloco"));
  ui->tabWidget->addTab(new GaussTab(this), QString("T1 Gauss"));
  ui->tabWidget->addTab(new LUTab(this), QString("T1 LU"));
  ui->tabWidget->addTab(new CholeskyTab(this), QString("T1 Cholesky"));

  // T2 Tabs
  //ui->tabWidget->addTab()

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
