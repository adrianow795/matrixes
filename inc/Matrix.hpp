#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>


template <typename Type> 
class Matrix
{
    public:
    std::vector<std::vector<Type>> data_;

    Matrix(int size_x, int size_y) : dim_x_(size_x), dim_y_(size_y) 
    { 
        data_.resize(dim_x_, std::vector<Type>(dim_y_));
    }
    
    Matrix operator+(const Matrix& b) const 
    {
        Matrix<Type> result(this->dim_x_, this->dim_y_);
        for(auto i = 0u; i < this->dim_x_; i++)
        {
            for(auto j = 0u; j < this->dim_y_; j++)
            {
                result.data_[i][j] = this->data_[i][j] + b.data_[i][j];
            }
        }
        return result;
    }

    template <typename T>
    friend std::ostream& operator<<(std::ostream &os, const Matrix<Type> & mat);

    void show(std::string &&name) const
    {
        std::cout << std::setw(10) << "============" << std::setw(10) <<
            std::internal <<   name << std::setw(10) << "   ============" << std::endl;
        for(auto i = 0u; i < dim_x_; i++)
        {
            for(auto j =0u; j < dim_y_; j++)
            {
                std::cout << std::setw(10) << data_[i][j] << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    private:
    
    int dim_x_;
    int dim_y_;

};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
    for (const auto& row : mat.data_) {
        for (const auto& el : row) {
            os << std::setw(10) << el << " | ";
        }
        os << '\n';
    }
    return os;
}

#endif