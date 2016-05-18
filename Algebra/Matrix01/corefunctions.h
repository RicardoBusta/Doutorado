#ifndef COREFUNCTIONS_H
#define COREFUNCTIONS_H

class QTableWidget;

#include "simplematrix.h"

namespace Core {
void RandomizeMatrix(SimpleMatrix &M);

void SetMatrixToWidget(QTableWidget *widget, const SimpleMatrix &m);

void MultiplyByRow(SimpleMatrix &A, SimpleMatrix &B, SimpleMatrix &C);

void MultiplyByCol(SimpleMatrix &A, SimpleMatrix &B, SimpleMatrix &C);
}

#endif  // COREFUNCTIONS_H
