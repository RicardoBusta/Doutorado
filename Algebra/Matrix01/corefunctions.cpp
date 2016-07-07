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
  widget->resizeColumnsToContents();
}

void GetMatrixFromWidget(QTableWidget *widget, SimpleMatrix &m, bool *ok) {
  (*ok) = true;
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      m.setData(i, j, widget->item(i, j)->text().toDouble(ok));
      if (!(*ok)) {
        return;
      }
    }
  }
}

void SetMatrixToWidget(QTableWidget *widget, const BlockMatrix &m) {
  widget->clear();
  widget->setRowCount(m.rows);
  widget->setColumnCount(m.cols);
  for (int i = 0; i < m.rr; i++) {
    int ci = i * m.mm;
    for (int j = 0; j < m.cc; j++) {
      int cj = j * m.nn;
      SimpleMatrix *mm = m.getData(i, j);
      for (int ii = 0; ii < mm->rows; ii++) {
        for (int jj = 0; jj < mm->cols; jj++) {
          QTableWidgetItem *item = new QTableWidgetItem();
          widget->setItem(ci + ii, cj + jj, item);
          if ((i + j) % 2 == 0) {
            item->setBackgroundColor(QColor(0xddddff));
          } else {
            item->setBackgroundColor(Qt::white);
          }
          item->setText(QString::number(mm->getData(ii, jj)));
        }
      }
    }
  }
  widget->resizeColumnsToContents();
}
}
