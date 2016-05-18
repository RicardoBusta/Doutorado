#ifndef COREFUNCTIONS_H
#define COREFUNCTIONS_H

class QTableWidget;

namespace Core {
void CreateRandomMatrix(int m, int n, double ***A, bool rand);

void SetMatrixToWidget(QTableWidget *widget, int m, int n, double **M);

void MultiplyByRow(int m, int n, int p, double **A, double **B, double ***C);

void MultiplyByCol(int m, int n, int p, double **A, double **B, double ***C);
}

#endif  // COREFUNCTIONS_H
