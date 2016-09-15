#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

  void GetCurrentObjectTransform();
private slots:
  void UpdateObjList();
  void SelectObject(QTreeWidgetItem*, QTreeWidgetItem*previous);
  void SelectPrimitiveShape(bool checked);

  void UpdateCurrentObjectTransform(double v);
};

#endif // MAINWINDOW_H
