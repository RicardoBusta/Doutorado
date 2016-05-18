#ifndef PERFORMANCE_TAB_H
#define PERFORMANCE_TAB_H

#include <QWidget>

#include "simplematrix.h"

namespace Ui {
class PerformanceTab;
}

class PerformanceTab : public QWidget
{
    Q_OBJECT

public:
    explicit PerformanceTab(QWidget *parent = 0);
    ~PerformanceTab();

private:
    Ui::PerformanceTab *ui;

    SimpleMatrix *A=nullptr, *B=nullptr, *C=nullptr;

private slots:
    void GeneratePressed();
    void CalculatePressed();
};

#endif // PERFORMANCE_TAB_H
