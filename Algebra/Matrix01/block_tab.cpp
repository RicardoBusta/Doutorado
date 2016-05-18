#include "block_tab.h"
#include "ui_block_tab.h"

#include <structures/blockmatrix.h>
#include "corefunctions.h"

BlockTab::BlockTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlockTab)
{
    ui->setupUi(this);

    QObject::connect(ui->gen_pushButton,SIGNAL(clicked(bool)),this,SLOT(GeneratePressed()));
}

BlockTab::~BlockTab()
{
  delete ui;
}

void BlockTab::GeneratePressed()
{
  int m = ui->m_spinBox->value();
  int n = ui->n_spinBox->value();
  int p = ui->p_spinBox->value();

  int r = ui->mb_spinBox->value();
  int s = ui->nb_spinBox->value();
  int t = ui->pb_spinBox->value();


  BlockMatrix *A = new BlockMatrix(m,n,r,s);
  BlockMatrix *B = new BlockMatrix(n,p,s,t);
  BlockMatrix *C = new BlockMatrix(m,p,r,t);

  Core::SetMatrixToWidget(ui->A_tableWidget,*A);
  Core::SetMatrixToWidget(ui->B_tableWidget,*B);
  Core::SetMatrixToWidget(ui->C_tableWidget,*C);
}

void BlockTab::CalculatePressed()
{

}
