#include "performance_tab.h"
#include "ui_performance_tab.h"

#include <QDebug>
#include <QElapsedTimer>

#include "corefunctions.h"
#include "mainwindow.h"

PerformanceTab::PerformanceTab(MainWindow *w, QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::PerformanceTab),
                                                  A(nullptr), B(nullptr), C(nullptr) {
  ui->setupUi(this);

  QObject::connect(ui->generate_pushButton, SIGNAL(clicked(bool)), this, SLOT(GeneratePressed()));
  QObject::connect(ui->calculate_pushButton, SIGNAL(clicked(bool)), this, SLOT(CalculatePressed()));
  QObject::connect(this,SIGNAL(Error(QString)),w,SLOT(ErrorMessage(QString)));

  ui->calculate_pushButton->setEnabled(false);
}

PerformanceTab::~PerformanceTab() {
  delete ui;
}

void PerformanceTab::GeneratePressed() {
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();
  int p = ui->p_spinBox->value();

  SimpleMatrix::CreateMatrix(m, n, &A);
  SimpleMatrix::CreateMatrix(n, p, &B);
  SimpleMatrix::CreateMatrix(m, p, &C);

  A->Randomize();
  B->Randomize();

  Core::SetMatrixToWidget(ui->A_tableWidget, *A);
  Core::SetMatrixToWidget(ui->B_tableWidget, *B);
  ui->C_tableWidget->clear();
  ui->C_tableWidget->setRowCount(0);
  ui->C_tableWidget->setColumnCount(0);

  ui->calculate_pushButton->setEnabled(true);
}

void PerformanceTab::CalculatePressed() {
  if (A == nullptr || B == nullptr || C == nullptr) {
    emit Error("Matrizes nulas");
    return;
  }


  if(ui->read_checkBox->isChecked()){
    bool ok;
    Core::GetMatrixFromWidget(ui->A_tableWidget,*A,&ok);
    if(!ok){
      emit Error("Matriz A inválida");
      return;
    }
    Core::GetMatrixFromWidget(ui->B_tableWidget,*B,&ok);
    if(!ok){
      emit Error("Matriz B inválida");
      return;
    }
  }

  QElapsedTimer timer;
  timer.start();
  SimpleMatrix::MultiplyByRow(*A, *B, *C);
  qint64 t11 = timer.elapsed();
  timer.start();
  SimpleMatrix::MultiplyByCol(*A, *B, *C);
  qint64 t21 = timer.elapsed();

  if (ui->three_times_checkBox->isChecked()) {
    timer.start();
    SimpleMatrix::MultiplyByCol(*A, *B, *C);
    qint64 t22 = timer.elapsed();
    timer.start();
    SimpleMatrix::MultiplyByRow(*A, *B, *C);
    qint64 t12 = timer.elapsed();
    timer.start();
    SimpleMatrix::MultiplyByRow(*A, *B, *C);
    qint64 t13 = timer.elapsed();
    timer.start();
    SimpleMatrix::MultiplyByCol(*A, *B, *C);
    qint64 t23 = timer.elapsed();

    ui->row2_label->setText(QString::number(t12) + "ms");
    ui->col2_label->setText(QString::number(t22) + "ms");

    ui->row3_label->setText(QString::number(t13) + "ms");
    ui->col3_label->setText(QString::number(t23) + "ms");
  } else {
    ui->row2_label->setText("?ms");
    ui->col2_label->setText("?ms");

    ui->row3_label->setText("?ms");
    ui->col3_label->setText("?ms");
  }

  ui->row_label->setText(QString::number(t11) + "ms");
  ui->col_label->setText(QString::number(t21) + "ms");
  Core::SetMatrixToWidget(ui->C_tableWidget, *C);
}
