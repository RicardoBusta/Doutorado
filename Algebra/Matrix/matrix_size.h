#ifndef MATRIXSIZE_H
#define MATRIXSIZE_H

class MatrixSize {
 public:
  explicit MatrixSize(int rows=0, int cols=0);

    int rows() const;
    void setRows(int rows);

    int cols() const;
    void setCols(int cols);

private:
    int rows_;
    int cols_;
};

#endif // MATRIXSIZE_H
