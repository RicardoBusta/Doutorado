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

  //void GetCurrentObjectTransform();
private slots:
  void UpdateObjList();
  void UpdateDrawing();
  void SelectObject(QTreeWidgetItem*, QTreeWidgetItem*previous);

  void UpdateCurrentObjectTransform(double v);
  void UpdateCurrentObjectName(QString name);
  void UpdateCurrentObjectCheck(bool value);

  void CreateOctreePressed();
  void OperateOctreePressed();

  void SaveScenePress();
  void LoadScenePress();
};

#endif // MAINWINDOW_H