#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class Scene;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

  QColor faceColor;
  QColor lineColor;
  //void GetCurrentObjectTransform();

  Scene *scene;
private slots:
  void UpdateObjList();
  void UpdateDrawing();
  void SelectObject(QTreeWidgetItem*, QTreeWidgetItem*previous);

  void UpdateCurrentObjectTransform(double v);
  void UpdateCurrentObjectName(QString name);
  void UpdateCurrentObjectCheck(bool value);

  void CreateOctreePressed();
  void OperateOctreePressed();

  void DuplicateObjectPressed();

  void SaveScenePress();
  void LoadScenePress();

  void SetFaceColor();
  void SetLineColor();

  void ClearScene();
};

#endif // MAINWINDOW_H
