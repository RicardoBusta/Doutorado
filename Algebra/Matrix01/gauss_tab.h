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

private slots:
    void GeneratePressed();
    void EliminatePressed();
    void CalculatePressed();
};

#endif // GAUSS_TAB_H
