#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <optional>
#include <thread>

/**
 * @class Matrix
 * @brief Represents a 2D matrix with basic operations.
 * 
 * This class provides functionality for matrix operations such as addition,
 * multiplication, and multithreaded multiplication.
 * 
 * @tparam Type The data type of the matrix elements.
 * @tparam rows The number of rows in the matrix.
 * @tparam cols The number of columns in the matrix.
 */
template <typename Type, size_t rows, size_t cols> 
class Matrix
{
    public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the matrix with default values.
     */
    Matrix() : data_(rows, std::vector<Type>(cols)) {}
    
    /**
     * @brief Access a row of the matrix (non-const).
     * 
     * @param a The index of the row.
     * @return A reference to the row.
     * @throws std::out_of_range If the index is out of range.
     */
    std::vector<Type>& operator[](const int a)
    {
        if ((a < 0) || (a >= data_.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return data_[a];
    }

    /**
     * @brief Access a row of the matrix (const).
     * 
     * @param a The index of the row.
     * @return A const reference to the row.
     * @throws std::out_of_range If the index is out of range.
     */
    const std::vector<Type>& operator[](const int a) const
    {
        if ((a < 0) || (a >= data_.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return data_[a];
    }

    /**
     * @brief Multiply the matrix with another matrix.
     * 
     * @tparam rows_o The number of rows in the second matrix.
     * @tparam cols_o The number of columns in the second matrix.
     * @param b The second matrix to multiply with.
     * @return An optional matrix containing the result, or `std::nullopt` if the matrices cannot be multiplied.
     */
    template < size_t rows_o, size_t cols_o>
    std::optional<Matrix<Type, rows, cols_o>> multiplyBy(const Matrix<Type, rows_o, cols_o> & b)  const
    { 
        if(cols != rows_o)
        {
            std::cout << "Matrixes cannot be multiplied" << std::endl;
            return std::nullopt;
        }

        Matrix<Type, rows, cols_o> result;

        for(auto i = 0; i < rows; i++)
        {
            for(auto j = 0; j < cols_o; j++)
            {
                result[i][j] = 0;
                for(auto z = 0; z < cols; z++)
                {
                    result[i][j] += data_[i][z] * b[z][j];
                }
            }
        }
        return std::optional<Matrix<Type, rows, cols_o>>(result);
    }

    /**
     * @brief Multiply the matrix with another matrix using multiple threads.
     * 
     * @tparam rows_o The number of rows in the second matrix.
     * @tparam cols_o The number of columns in the second matrix.
     * @param b The second matrix to multiply with.
     * @return An optional matrix containing the result, or `std::nullopt` if the matrices cannot be multiplied.
     */
    template < size_t rows_o, size_t cols_o>
    std::optional<Matrix<Type, rows, cols_o>> multiplyByWithThreads(const Matrix<Type, rows_o, cols_o> & b)  const
    {
        if(cols != rows_o)
        {
            std::cout << "Matrixes cannot be multiplied" << std::endl;
            return std::nullopt;
        }
        Matrix<Type, rows, cols_o> result;
        constexpr auto thread_num = std::min<size_t>(10, rows);
        size_t chunk_size = rows / thread_num;
        std::vector<std::thread> workers;

        for(auto i = 0; i < thread_num; i++)
        {
            workers.push_back(std::thread([&, i]{
                for(auto x = i*chunk_size; x < i*chunk_size + chunk_size && x < rows; x++)
                {
                    for(auto j = 0; j < cols_o; j++)
                    {
                        Type temp = 0;
                        for(auto z = 0; z < cols; z++)
                        {
                            temp += data_[x][z] * b[z][j];
                        }
                        result[x][j] = temp;
                    }
                }
            }));
        }

        for(auto &th : workers)
        {
            th.join();
        }

        return std::optional<Matrix<Type, rows, cols_o>>(result);

    }

    /**
     * @brief Add two matrices.
     * 
     * @param b The matrix to add.
     * @return A new matrix containing the result of the addition.
     * @throws std::invalid_argument If the matrices have different sizes.
     */
    Matrix operator+(const Matrix& b) const 
    {
        if((data_.size() != b.data_.size()) ||
           (data_[0].size() != b.data_[0].size()))
        {
            throw std::invalid_argument("Incorrect matrixes size");
        }

        Matrix<Type, rows, cols> result;
        for(auto i = 0u; i < data_.size(); i++)
        {
            for(auto j = 0u; j < data_[0].size(); j++)
            {
                result.data_[i][j] = this->data_[i][j] + b.data_[i][j];
            }
        }
        return result;
    }

    /**
     * @brief Print the matrix to an output stream.
     * 
     * @tparam T The data type of the matrix elements.
     * @tparam r The number of rows in the matrix.
     * @tparam c The number of columns in the matrix.
     * @param os The output stream.
     * @param mat The matrix to print.
     * @return The output stream.
     */
    template <typename T, size_t r, size_t c> 
    friend std::ostream& operator<<(std::ostream &os, const Matrix<T,r,c> & mat);

    /**
     * @brief Display the matrix with a name.
     * 
     * @param name The name of the matrix.
     */
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
    std::vector<std::vector<Type>> data_; ///< The 2D vector storing the matrix elements.

};


template <typename T, size_t r, size_t c> 
std::ostream& operator<<(std::ostream& os, const Matrix<T, r, c>& mat) {
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