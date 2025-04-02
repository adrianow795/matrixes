#include <iostream>
#include "Matrix.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    int x = 3;
    Matrix<double> m1(x,x);
    Matrix<double> m2(x,x);
    Matrix<double> m3(x,x);
    std::srand(std::time({})); // use current time as seed for random generator

    for(auto i = 0u; i < x; i++)
    {
        for(auto j =0u; j < x; j++)
        {
            m1.matrix[i][j] = (std::rand() % 20) * 0.7;
            m2.matrix[i][j] = (std::rand() % 100) * 0.5;
        }
    }

    std::cout << "Matrix m1: " << std::endl;
    for(auto i = 0u; i < x; i++)
    {
        for(auto j =0u; j < x; j++)
        {
            std::cout << m1.matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix m2: " << std::endl;
    for(auto i = 0u; i < x; i++)
    {
        for(auto j =0u; j < x; j++)
        {
            std::cout << m2.matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }

    m3 = m1 + m2;
    std::cout << "Matrix m3 = m1 + m2: " << std::endl;
    for(auto i = 0u; i < x; i++)
    {
        for(auto j =0u; j < x; j++)
        {
            std::cout << m3.matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }


    return 0;
}