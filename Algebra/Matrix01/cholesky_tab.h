#ifndef CHOLESKY_TAB_H
#define CHOLESKY_TAB_H

#include <QWidget>

namespace Ui {
class CholeskyTab;
}

class CholeskyTab : public QWidget
{
    Q_OBJECT

public:
    explicit CholeskyTab(QWidget *parent = 0);
    ~CholeskyTab();

private:
    Ui::CholeskyTab *ui;
};

#endif // CHOLESKY_TAB_H