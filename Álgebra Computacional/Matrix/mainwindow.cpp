/*--------------------------------------------------------------------------#
#  Copyright (C) 2015  Ricardo Bustamante de Queiroz (ricardo@busta.com.br) #
#                                                                           #
#  This program is free software: you can redistribute it and/or modify     #
#  it under the terms of the GNU General Public License as published by     #
#  the Free Software Foundation, either version 3 of the License, or        #
#  (at your option) any later version.                                      #
#                                                                           #
#  This program is distributed in the hope that it will be useful,          #
#  but WITHOUT ANY WARRANTY; without even the implied warranty of           #
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
#  GNU General Public License for more details.                             #
#                                                                           #
#  You should have received a copy of the GNU General Public License        #
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.    #
#--------------------------------------------------------------------------*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "matrix_widget.h"
#include "matrix.h"
#include "show_matrix_dialog.h"

#include <QDebug>

static int matrix_index = 0;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->generate_pushButton,SIGNAL(clicked(bool)),this,SLOT(GenerateMatrix()));
  connect(ui->exec_gauss_pushButton, SIGNAL(clicked(bool)),this,SLOT(GaussExecute()));

  // Ops
  connect(ui->ops_refresh_pushButton,SIGNAL(clicked(bool)),this,SLOT(OpsRefreshClicked()));
  // Gauss
  connect(ui->gauss_refresh_pushButton,SIGNAL(clicked(bool)),this,SLOT(GaussRefreshClicked()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

QString MatrixNameFromInt(int i){
    qDebug() << "Test";
    QString out;
    int v = i;
    do{
        QChar c = (char)(v%26 + (int)'A');
        qDebug() << c;
        out.push_front(c);
        v = v/26;
        qDebug() << v;
    }while(float(v)/26.0f > 0);
        return out;
}

void MainWindow::GenerateMatrix()
{
    QString name = MatrixNameFromInt(matrix_index++);
    QSize matrix_size = QSize(ui->row_spinBox->value(),ui->col_spinBox->value());
    Matrix *m = new Matrix(matrix_size);
    m->Randomize();
    matrix_map_.insert(name,m);

    AddMatrix(name,matrix_size);
}

MatrixWidget* MainWindow::AddMatrix(const QString &name, const QSize &matrix_size)
{
    QListWidgetItem * item = new QListWidgetItem;
    MatrixWidget * widget = new MatrixWidget(
                name,
                matrix_size);
    QObject::connect(widget,SIGNAL(ShowMatrixRequested(QString)),this,SLOT(ShowMatrix(QString)));
    ui->matrix_listWidget->addItem(item);
    ui->matrix_listWidget->setItemWidget(item,widget);
    item->setSizeHint(widget->size());
}

void MainWindow::ShowMatrix(QString matrix_name) {
    if(!matrix_map_.contains(matrix_name)){
        qWarning() << "Não tem essa matriz";
        return;
    }
    ShowMatrixDialog  matrix_dialog(matrix_map_[matrix_name]);
    matrix_dialog.exec();
}

void MainWindow::OpsRefreshClicked()
{
    qDebug() << "refreshing";
    ui->ops_1_comboBox->clear();
    ui->ops_2_comboBox->clear();
    ui->ops_1_comboBox->addItems(matrix_map_.keys());
    ui->ops_2_comboBox->addItems(matrix_map_.keys());
}

void MainWindow::OpsExecute()
{
    QString op1_name = ui->ops_1_comboBox->currentText();
    QString op2_name = ui->ops_2_comboBox->currentText();

    if(!(matrix_map_.contains(op1_name) && matrix_map_.contains(op2_name))){
        qWarning() << "Escolha uma matriz existente";
    }

    if(ui->op_comboBox->currentIndex() == 0){

    }else{
        matrix_map_[op1_name]->Add(matrix_map_[op2_name]);
    }
}

void MainWindow::GaussRefreshClicked()
{

}

void MainWindow::GaussExecute() {
    qDebug() << "Executing gauss";
    if(!matrix_map_.contains("A")){
        qWarning() << "Selecione matriz existente";
        return;
    }
    MatrixInterface * result = matrix_map_["A"]->GaussianElimination(false,false);
    qDebug() << "got result";
    QString result_name = "Gauss(A)";
    matrix_map_.insert(result_name,result);

    AddMatrix(result_name,result->size());
}
