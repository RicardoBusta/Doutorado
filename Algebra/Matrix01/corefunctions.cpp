#include "corefunctions.h"

#include <QTableWidget>

namespace Core {
void SetMatrixToWidget(QTableWidget *widget, const SimpleMatrix &m) {
  widget->clear();
  widget->setRowCount(m.rows);
  widget->setColumnCount(m.cols);
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      QTableWidgetItem *item = new QTableWidgetItem();
      widget->setItem(i, j, item);
      item->setText(QString::number(m.getData(i, j)));
    }
  }
}
}
