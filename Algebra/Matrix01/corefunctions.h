#ifndef COREFUNCTIONS_H
#define COREFUNCTIONS_H

class QTableWidget;

#include "structures/blockmatrix.h"
#include "structures/simplematrix.h"

namespace Core {
void SetMatrixToWidget(QTableWidget *widget, const SimpleMatrix &m);
void GetMatrixFromWidget(QTableWidget *widget, SimpleMatrix &m, bool *ok);
void SetMatrixToWidget(QTableWidget *widget, const BlockMatrix &m);
}

#endif // COREFUNCTIONS_H
