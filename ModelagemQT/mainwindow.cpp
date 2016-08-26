#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QObject::connect(ui->octree_spread_slider,SIGNAL(valueChanged(int)),ui->glwidget,SLOT(OctreeSpreadChange(int)));
}

MainWindow::~MainWindow() {
  delete ui;
}
