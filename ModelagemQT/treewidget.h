#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>

class TreeWidget : public QTreeWidget
{
  Q_OBJECT
public:
  explicit TreeWidget(QWidget *parent = 0);

protected:
  void dropEvent(QDropEvent *event);

signals:
  void ChangeParent(QString target, QString parent);
};

#endif // TREEWIDGET_H
