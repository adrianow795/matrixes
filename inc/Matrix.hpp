#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

template <class Type> 
class Matrix
{
    public:
    Matrix(int size_x, int size_y) : dim_x_(size_x), dim_y_(size_y) 
    { matrix.resize(dim_x_, std::vector<Type>(dim_y_));}

    std::vector<std::vector<Type>> matrix;
    
    Matrix operator+(const Matrix& b) const 
    {
        Matrix<Type> result(this->dim_x_, this->dim_y_);
        for(auto i = 0u; i < this->dim_x_; i++)
        {
            for(auto j = 0u; j < this->dim_y_; j++)
            {
                result.matrix[i][j] = this->matrix[i][j] + b.matrix[i][j];
            }
        }
        return result;
    }
    

    private:
    
    int dim_x_;
    int dim_y_;

};

#endif