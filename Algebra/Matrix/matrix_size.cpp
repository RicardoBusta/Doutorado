#include "matrix_size.h"

MatrixSize::MatrixSize(int rows, int cols) : rows_(rows),
    cols_(cols) {}

int MatrixSize::rows() const
{
    return rows_;
}

void MatrixSize::setRows(int rows)
{
    rows_ = rows;
}

int MatrixSize::cols() const
{
    return cols_;
}

void MatrixSize::setCols(int cols)
{
    cols_ = cols;
}
