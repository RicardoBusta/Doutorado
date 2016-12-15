#ifndef EXTRUDEDIALOG_H
#define EXTRUDEDIALOG_H

#include <QDialog>

namespace Ui {
class ExtrudeDialog;
}

class HalfEdgeObject;

class ExtrudeDialog : public QDialog
{
  Q_OBJECT

public:
  explicit ExtrudeDialog(QWidget *parent = 0);
  ~ExtrudeDialog();

  void Apply(HalfEdgeObject *he);
private:
  Ui::ExtrudeDialog *ui;
};

#endif // EXTRUDEDIALOG_H
