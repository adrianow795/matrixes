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

    Matrix(int size_x, int size_y) : data_(size_x, std::vector<Type>(size_y)) {}
    
    std::vector<Type>& operator[] (const int a)
    {
        if((a < 0) || (a >= data_.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return data_[a];
    }

    Matrix<Type> operator+(const Matrix& b) const 
    {
        if((data_.size() != b.data_.size()) ||
           (data_[0].size() != b.data_[0].size()))
        {
            throw std::invalid_argument("Incorrect matrixes size");
        }

        Matrix<Type> result(data_.size(), data_[0].size());
        for(auto i = 0u; i < data_.size(); i++)
        {
            for(auto j = 0u; j < data_[0].size(); j++)
            {
                result.data_[i][j] = this->data_[i][j] + b.data_[i][j];
            }
        }
        return result;
    }
    template <typename T>
    friend std::ostream& operator<<(std::ostream &os, const Matrix<T> & mat);

    void show(std::string &&name) const
    {
        std::cout << std::setw(10) << "============" << std::setw(10) <<
            std::internal <<   name << std::setw(10) << "   ============" << std::endl;
        for(const auto& row: data_)
        {
            for(const auto& el: row)
            {
                std::cout << std::setw(10) << el << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    private:
    std::vector<std::vector<Type>> data_;

};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
    for (const auto& row : mat.data_) {
        for (const auto& el : row) {
            os << std::internal << std::setw(10) << el << " | ";
        }
        os << '\n';
    }
    os << '\n';
    return os;
}

#endif