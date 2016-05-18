#ifndef BLOCK_TAB_H
#define BLOCK_TAB_H

#include <QWidget>

namespace Ui {
class BlockTab;
}

class BlockTab : public QWidget
{
    Q_OBJECT

public:
    explicit BlockTab(QWidget *parent = 0);
    ~BlockTab();

private:
    Ui::BlockTab *ui;

private slots:
    void GeneratePressed();
    void CalculatePressed();
};

#endif // BLOCK_TAB_H
