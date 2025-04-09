#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <optional>
#include <thread>
#include <functional>
#include <mutex> 
#include <condition_variable>
#include <queue>


template <typename Type, size_t rows, size_t cols> 
class Matrix
{
    public:
    /* constructor */
    Matrix() : data_(rows, std::vector<Type>(cols)) { }
    
    /* operator []*/
    std::vector<Type>& operator[](const int a)
    {
        if ((a < 0) || (a >= data_.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return data_[a];
    }

    /* const operator []*/
    const std::vector<Type>& operator[](const int a) const
    {
        if ((a < 0) || (a >= data_.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return data_[a];
    }

    /* multiplyBy */
    template < size_t rows_o, size_t cols_o>
    std::optional<Matrix<Type, rows, cols_o>> multiplyBy(const Matrix<Type, rows_o, cols_o> & b)  const
    {
        /* 1st martix needs to have as many cols as 2nd one rows */
        if(cols != rows_o)
        {
            std::cout << "Matrixes cannot be multiplied" << std::endl;
            return std::nullopt;
        }

        /* cannot use 'this', so use rows (template arg) instead*/
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



    /* operator + */
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

    /* operator ostream <<  - this is fried method because we need to have access to private data_*/
    template <typename T, size_t r, size_t c> 
    friend std::ostream& operator<<(std::ostream &os, const Matrix<T,r,c> & mat);

    /* additional function for showing */
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

    /* multiplyByOnThreads */
    template < size_t rows_o, size_t cols_o>
    std::optional<Matrix<Type, rows, cols_o>> multiplyByOnThreads(const Matrix<Type, rows_o, cols_o> & b)  const
    {
        /* 1st martix needs to have as many cols as 2nd one rows */
        if(cols != rows_o)
        {
            std::cout << "Matrixes cannot be multiplied" << std::endl;
            return std::nullopt;
        }

        /* cannot use 'this', so use rows (template arg) instead*/
        Matrix<Type, rows, cols_o> result;
        for(auto i = 0; i < rows; i++)
        {
            for(auto j = 0; j < cols_o; j++)
            {
                addJob([this, i, j, &result[i][j]] {
                    this->calculateIdx(this->data_[i], b.data_[j], result[i][j]);
                })
            }
        }



    }
    private:
    bool should_terminate_ = false;
    std::vector<std::vector<Type>> data_;
    std::mutex queue_mutex_;
    std::condition_variable mutex_condition_;
    std::vector<std::thread> theads_;
    std::queue<std::function<void()>> jobs_;


    void th(void)
    {
        while(true)
        {
            std::function<void()> job;
            {
                std::unique_lock<std::mutex> lock(queue_mutex_);
                mutex_condition_.wait(lock, [this] 
                    {
                    return (!jobs_.empty() || should_terminate_); 
                    });
                job = jobs_.front();
                jobs_.pop();
            }
            job();
        }
    }

    void addJob(std::function<void()> job)
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        jobs_.push(job);
        mutex_condition_.notify_one();
    }

    void calculateIdx(std::vector<Type> &vec_row, std::vector<Type> &vec_col, Type &result)
    {
        Type result = 0;
        for(auto i = 0; i < vec_row.size(); i++)
        {
            result += vec_row[i] * vec_col[i];
        }
        return result;
    }

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