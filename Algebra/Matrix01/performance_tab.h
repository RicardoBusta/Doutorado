#ifndef PERFORMANCE_TAB_H
#define PERFORMANCE_TAB_H

#include <QWidget>

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
};

#endif // PERFORMANCE_TAB_H
