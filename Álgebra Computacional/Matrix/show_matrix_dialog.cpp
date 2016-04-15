#include "show_matrix_dialog.h"
#include "ui_show_matrix_dialog.h"

#include "matrix_interface.h"

ShowMatrixDialog::ShowMatrixDialog(MatrixInterface *matrix, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowMatrixDialog)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(matrix->w());
    ui->tableWidget->setRowCount(matrix->h());

    for(int i=0;i<matrix->h();i++){
        for(int j=0;j<matrix->w();j++){
            QTableWidgetItem * item = new QTableWidgetItem(QString::number(matrix->data(i,j)));
            ui->tableWidget->setItem(i,j,item);
        }
    }
}

ShowMatrixDialog::~ShowMatrixDialog()
{
    delete ui;
}
