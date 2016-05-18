#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "performance_tab.h"
#include "gauss_tab.h"
#include "block_tab.h"
#include "lu_tab.h"
#include "cholesky_tab.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  showMaximized();

  ui->tabWidget->addTab(new PerformanceTab(), QString("Desempenho"));
  ui->tabWidget->addTab(new BlockTab(), QString("Bloco"));
  ui->tabWidget->addTab(new GaussTab(), QString("Gauss"));
  ui->tabWidget->addTab(new LUTab(), QString("LU"));
  ui->tabWidget->addTab(new CholeskyTab(), QString("Cholesky"));
}

MainWindow::~MainWindow() {
  delete ui;
}
