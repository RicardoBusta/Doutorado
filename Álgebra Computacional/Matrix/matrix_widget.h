#ifndef MATRIX_WIDGET_H
#define MATRIX_WIDGET_H

#include <QWidget>

namespace Ui {
class MatrixWidget;
}

class MatrixWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MatrixWidget(const QString &name, const QSize &block_size, const QSize &matrix_size, QWidget *parent = 0);
    explicit MatrixWidget(QWidget *parent = 0);
    ~MatrixWidget();

private:
    Ui::MatrixWidget *ui;
};

#endif // MATRIX_WIDGET_H
