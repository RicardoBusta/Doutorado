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

#ifndef MATRIX_H
#define MATRIX_H

#include <QSize>

#include "matrix_interface.h"

class Matrix : public MatrixInterface
{
public:
  Matrix(const QSize &size);

  virtual double data(int i, int j);
  virtual double setData(int i, int j, double value);

  virtual void Randomize();

  virtual void set(double * data);

  virtual MatrixInterface * GaussianElimination(bool horz_pivot, bool vert_pivot);
private:
  double *data_;
};

#endif // MATRIX_H
