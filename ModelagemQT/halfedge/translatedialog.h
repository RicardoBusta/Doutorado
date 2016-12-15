#ifndef TRANSLATEDIALOG_H
#define TRANSLATEDIALOG_H

#include <QDialog>

namespace Ui {
class TranslateDialog;
}

class HalfEdgeObject;

class TranslateDialog : public QDialog
{
  Q_OBJECT

public:
  explicit TranslateDialog(QWidget *parent = 0);
  ~TranslateDialog();

  void Apply(HalfEdgeObject *he);
private:
  Ui::TranslateDialog *ui;
};

#endif // TRANSLATEDIALOG_H
