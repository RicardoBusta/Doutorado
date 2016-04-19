/*--------------------------------------------------------------------------#
#  Copyright (C) 2015  Ricardo Bustamante de Queiroz (ricardo@busta.com.br) #
#                                                                           #
#  This program is free software: you can redistribute it and/or modify     #
#  it under the terms of the GNU General Public License as published by     #
#  the Free Software Foundation, either version 3 of the License, or        #
#  (at your option) any later version.                                      #
#                                                                           #
#  This program is distributed in the hope that it will be useful,          #
#  but WITHOUT ANY WARRANTY; without even the implied warranty of           #
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            #
#  GNU General Public License for more details.                             #
#                                                                           #
#  You should have received a copy of the GNU General Public License        #
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.    #
#--------------------------------------------------------------------------*/

#include "matrix.h"
#include <QDebug>

const double kZeroPrecision = 0.00001;

Matrix::Matrix(const MatrixSize &size) : MatrixInterface(size) {
  data_ = new double[size_.cols() * size_.rows()];
  std::fill(data_, data_ + (size.cols() * size.rows()), 0);
}

double Matrix::data(int i, int j) {
  return data_[i * size_.cols() + j];
}

void Matrix::setData(int i, int j, double value) {
  data_[i * size_.cols() + j] = value;
}

void Matrix::Randomize() {
  for (int i = 0; i < size_.rows(); i++) {
    for (int j = 0; j < size_.cols(); j++) {
      data_[i * size_.cols() + j] = qrand() % 100;
    }
  }
}

void Matrix::set(double *data) {
  memcpy(data_, data, sizeof(double) * size_.cols() * size_.rows());
}

MatrixInterface *Matrix::Multiply(MatrixInterface *B) {
  MatrixInterface *A = this;

  if (!(A->cols() == B->rows())) {
    error_message_ = "As matrizes escolhidas possuem tamanhos incompatíveis.";
    return nullptr;
  }

  MatrixInterface *R = new Matrix(A->size());

  for (int i = 0; i < A->rows(); i++) {
    for (int j = 0; j < B->cols(); j++) {
      double val = 0;
      for (int k = 0; k < A->cols(); k++) {
        val += A->data(i, k) * B->data(k, j);
      }
      R->setData(i, j, val);
    }
  }

  return R;
}

MatrixInterface *Matrix::Add(MatrixInterface *B) {
  MatrixInterface *A = this;

  if (A->rows() != B->rows() || A->cols() != B->cols()) {
    qDebug() << A->cols() << B->cols();
    error_message_ = "As matrizes escolhidas possuem tamanhos incompatíveis.";
    return nullptr;
  }

  MatrixInterface *R = new Matrix(A->size());

  for (int i = 0; i < A->rows(); i++) {
    for (int j = 0; j < A->cols(); j++) {
      R->setData(i, j, A->data(i, j) + B->data(i, j));
    }
  }
  return R;
}

MatrixInterface *Matrix::GaussianElimination(bool horz_pivot, bool vert_pivot) {
  MatrixInterface *output = new Matrix(size());
  output->set(data_);
  // Coluna atual
  for (int j = 0; j < 2 /*size_.cols()*/; j++) {
    // Linha que vai ser zerada
    for (int i = j + 1; i < size_.rows(); i++) {
      // Elemento que será zerado dividido pelo pivot
      if (output->data(j, j) == 0) {
        if (vert_pivot) {
            for(int k=i+1;k<size_.rows();k++){

            }
        }
        error_message_ = "O pivot deu zero!";
        delete output;
        return nullptr;
      }
      double alpha = output->data(i, j) / output->data(j, j);
      for (int k = j; k < size_.cols(); k++) {
        double val = output->data(i, k);
        val -= alpha * output->data(j, k);
        output->setData(i, k, val < kZeroPrecision ? 0 : val);
      }
    }
  }
  return output;
}
