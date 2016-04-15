#ifndef SHOW_MATRIX_DIALOG_H
#define SHOW_MATRIX_DIALOG_H

#include <QDialog>

class MatrixInterface;

namespace Ui {
class ShowMatrixDialog;
}

class ShowMatrixDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowMatrixDialog(MatrixInterface * matrix, QWidget *parent = 0);
    ~ShowMatrixDialog();

private:
    Ui::ShowMatrixDialog *ui;
};

#endif // SHOW_MATRIX_DIALOG_H
