#ifndef LU_TAB_H
#define LU_TAB_H

#include <QWidget>

namespace Ui {
class LUTab;
}

class LUTab : public QWidget
{
    Q_OBJECT

public:
    explicit LUTab(QWidget *parent = 0);
    ~LUTab();

private:
    Ui::LUTab *ui;

private slots:
    void GeneratePressed();
    void DecomposePressed();
};

#endif // LU_TAB_H
