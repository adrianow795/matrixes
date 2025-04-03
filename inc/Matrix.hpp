#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>


template <class Type> 
class Matrix
{
    public:
    std::vector<std::vector<Type>> matrix;

    Matrix(int size_x, int size_y) : dim_x_(size_x), dim_y_(size_y) 
    { 
        matrix.resize(dim_x_, std::vector<Type>(dim_y_));
    }
    
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

    void show(std::string &&name) const
    {
        std::cout << std::setw(10) << "============" << std::setw(10) <<
            std::internal <<   name << std::setw(10) << "   ============" << std::endl;
        for(auto i = 0u; i < dim_x_; i++)
        {
            for(auto j =0u; j < dim_y_; j++)
            {
                std::cout << std::setw(10) << matrix[i][j] << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    

    private:
    
    int dim_x_;
    int dim_y_;

};

#endif