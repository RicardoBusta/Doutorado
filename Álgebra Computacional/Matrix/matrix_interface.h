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

#ifndef MATRIX_INTERFACE_H
#define MATRIX_INTERFACE_H

#include <QSize>

class MatrixInterface
{
public:
  MatrixInterface(){}

  QSize size() const;
  int w() const;
  int h() const;

  virtual double data(int i, int j)=0;
  virtual double setData(int i, int j, double value)=0;

  virtual void set(double * data) = 0;

  virtual void Randomize()=0;

  virtual MatrixInterface * Add(MatrixInterface* B)=0;
  virtual MatrixInterface * Multiply(MatrixInterface* B)=0;
  virtual MatrixInterface * GaussianElimination(bool horz_pivot, bool vert_pivot) = 0;

protected:
  int w_;
  int h_;
};

#endif // MATRIX_INTERFACE_H
