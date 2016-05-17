#ifndef GAUSS_TAB_H
#define GAUSS_TAB_H

#include <QWidget>

namespace Ui {
class GaussTab;
}

class GaussTab : public QWidget
{
    Q_OBJECT

public:
    explicit GaussTab(QWidget *parent = 0);
    ~GaussTab();

private:
    Ui::GaussTab *ui;
};

#endif // GAUSS_TAB_H
