#include "matrix_widget.h"
#include "ui_matrix_widget.h"

MatrixWidget::MatrixWidget(const QString &name, const QSize &matrix_size, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatrixWidget)
{
    ui->setupUi(this);

    ui->name_label->setText(name);
    ui->size_label->setText(QString("%1x%2").arg(matrix_size.width()).arg(matrix_size.height()));
    //ui->block_size_label->setText(QString("%1x%2").arg(block_size.width()).arg(block_size.height()));
    ui->other_label->setText("full");

    QObject::connect(ui->view_pushButton,SIGNAL(clicked(bool)),this,SLOT(ShowMatrixClicked()));
}

MatrixWidget::~MatrixWidget()
{
    delete ui;
}

void MatrixWidget::ShowMatrixClicked()
{
    emit ShowMatrixRequested(ui->name_label->text());
}
