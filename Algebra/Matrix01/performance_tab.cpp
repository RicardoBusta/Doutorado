#include "performance_tab.h"
#include "ui_performance_tab.h"

PerformanceTab::PerformanceTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PerformanceTab)
{
    ui->setupUi(this);
}

PerformanceTab::~PerformanceTab()
{
    delete ui;
}
