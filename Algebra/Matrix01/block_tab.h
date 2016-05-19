#ifndef BLOCK_TAB_H
#define BLOCK_TAB_H

#include <QWidget>

namespace Ui {
class BlockTab;
}

class MainWindow;

class BlockTab : public QWidget {
  Q_OBJECT

public:
  explicit BlockTab(MainWindow *w, QWidget *parent = 0);
  ~BlockTab();

private:
  Ui::BlockTab *ui;

private slots:
  void GeneratePressed();
  void CalculatePressed();

signals:
  void Error(QString msg);
};

#endif // BLOCK_TAB_H
