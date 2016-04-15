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

#include <QDebug>

static int matrix_index = 0;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->generate_pushButton,SIGNAL(clicked(bool)),this,SLOT(GenerateMatrix()));
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
    QListWidgetItem * item = new QListWidgetItem;
    MatrixWidget * widget = new MatrixWidget(
                name,
                QSize(ui->row_spinBox->value(),ui->col_spinBox->value()),
                QSize(ui->block_row_spinBox->value(),ui->block_col_spinBox->value()));
    ui->matrix_listWidget->addItem(item);
    ui->matrix_listWidget->setItemWidget(item,widget);
    item->setSizeHint(widget->size());

    Matrix *m = new Matrix();

    matrix_map_.insert(name,);
}
