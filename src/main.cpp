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

    m1.show("m1");
    m2.show("m2");
    m3 = m1 + m2;
    m3.show("m3");

    return 0;
}