#include "treewidget.h"

#include <QDebug>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

TreeWidget::TreeWidget(QWidget *parent) : QTreeWidget(parent) {
}

void TreeWidget::dropEvent(QDropEvent *event) {
  // Solution for drag & drop from:
  // https://forum.qt.io/topic/27951/solved-qtreewidget-drag-and-drop-signals/5
  // Thanks, Glaucos
  // MimeData: application/x-qabstractitemmodeldatalist"

  QTreeWidget::dropEvent(event);

  const QMimeData *qMimeData = event->mimeData();

  QByteArray encoded = qMimeData->data("application/x-qabstractitemmodeldatalist");
  QDataStream stream(&encoded, QIODevice::ReadOnly);

  while (!stream.atEnd()) {
    int row, col;
    QMap<int, QVariant> roleDataMap;

    stream >> row >> col >> roleDataMap;

    QString dropped = roleDataMap[0].toString();

    QString into = this->itemAt(event->pos())->text(0);

    emit ChangeParent(dropped,into);
  }
}
