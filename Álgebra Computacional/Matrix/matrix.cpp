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

Matrix::Matrix(const QSize &size)
{
    w_ = size.width();
    h_ = size.height();
    data_ = new double[w_*h_];
    std::fill(data_,data_+(w_*h_),0);
}

double Matrix::data(int i, int j)
{
    return data_[i*w_+j];
}

double Matrix::setData(int i, int j, double value)
{
    data_[i*w_+j] = value;
}

void Matrix::Randomize()
{
    for(int i=0;i<h_;i++){
        for(int j=0;j<w_;j++){
            data_[i*w_+j] = qrand()%100;
        }
    }
}

void Matrix::set(double *data)
{
    memcpy(data_,data,sizeof(double)*w_*h_);
}

MatrixInterface *Matrix::Multiply(MatrixInterface *B)
{
    MatrixInterface * A = this;

    if(!(A->w() == B->w() && A->h() == B->h())){
        qWarning() << "Matrizes incompatíveis";
    }

    MatrixInterface * R = new Matrix(A->size());

    for(int i=0;i<A->h();i++){

    }
}

MatrixInterface *Matrix::Add(MatrixInterface *B)
{
    MatrixInterface * A = this;

    if(!(A->w() == B->w() && A->h() == B->h())){
        qWarning() << "Matrizes incompatíveis";
    }

    MatrixInterface * R = new Matrix(A->size());

    for(int i=0;i<A->h();i++){
        for(int j=0;j<A->w();j++){
            R->setData(i,j,A->data(i,j)+B->data(i,j));
        }
    }
    return R;
}

MatrixInterface *Matrix::GaussianElimination(bool horz_pivot, bool vert_pivot)
{
    MatrixInterface * output = new Matrix(size());
    output->set(data_);
    // Coluna atual
    for(int j=0;j<w_;j++){
        // Linha que vai ser zerada
        for(int i=j+1;i<h_;i++){
            // Elemento que será zerado dividido pelo pivot
            double alpha = data(i,j)/data(j,j);
            for(int k=j+1;k<w_;k++){
                double val = data(i,k);
                val -= alpha*data(j,k);
                setData(i,k,val);
            }
        }
    }
    return output;
}
