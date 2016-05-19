#ifndef GAUSS_TAB_H
#define GAUSS_TAB_H

#include <QWidget>

namespace Ui {
class GaussTab;
}

class MainWindow;

class GaussTab : public QWidget
{
    Q_OBJECT

public:
    explicit GaussTab(MainWindow *w, QWidget *parent = 0);
    ~GaussTab();

private:
    Ui::GaussTab *ui;

private slots:
    void GeneratePressed();
    void EliminatePressed();
    void CalculatePressed();

signals:
  void Error(QString msg);
};

#endif // GAUSS_TAB_H
