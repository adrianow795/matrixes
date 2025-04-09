#include <iostream>
#include "Matrix.hpp"
#include <cstdlib>
#include <ctime>


constexpr int fibo(int el)
{
    long long int result = 0;
    if(el == 1)
    {
        result = 1;
    }
    else if(el > 1)
    {
        int a = 0, b = 1;
        result = a +b;
        for(int i = 2; i < el; i++)
        {
            a = b;
            b = result;
            result = a + b;
        }
    }
    return result;
}

constexpr int fiboRec(int el)
{
    if(el == 0)
    {
        return 0;
    }
    if(el == 1)
    {
        return 1;
    }
    else
    {
        return fiboRec(el-1) + fiboRec(el-2);
    }
}


int main()
{
    constexpr auto x = 3;
    Matrix<double,x,x> m1;
    Matrix<double,x,x> m2;
    Matrix<double,x,x> m3;
    std::srand(std::time({})); // use current time as seed for random generator

    for(auto i = 0u; i < x; i++)
    {
        for(auto j =0u; j < x; j++)
        {
            m1[i][j] = (std::rand() % 20) * 0.7;
            m2[i][j] = (std::rand() % 100) * 0.5;
        }
    }
    std::cout << m1;
    
    m1.show("m1");
    m2.show("m2");
    m3 = m1 + m2; //RVO return value opt
    m3.show("m1 + m2");

    Matrix<int,2,3> d1;
    Matrix<int,3,2> d2;

    for(auto i = 0u; i < 2; i++)
    {
        for(auto j =0u; j < 3; j++)
        {
            d1[i][j] = (std::rand() % 10) ;
        }
    }

    for(auto i = 0u; i < 3; i++)
    {
        for(auto j =0u; j < 2; j++)
        {
            d2[i][j] = (std::rand() % 10) ;
        }
    }
    // d2[3,2] , d1[2,3]
    auto result = d1.multiplyBy(d2);
    if(result.has_value())
    {
        auto d3 = result.value();
        std::cout << "-----: d1\n" << d1 << std::endl;
        std::cout << "-----: d2\n" << d2 << std::endl;
        std::cout << "-----: d2 * d1\n" << d3 << std::endl;
    }
    else
    {
        std::cout << "Matrixes cannot be multiplied" << std::endl;
    }



    #define ELEMENT_NO 20
    time_t start_time, end_time;
    double duration;
    time(&start_time);
    constexpr long long int el = fibo(ELEMENT_NO);
    time(&end_time);
    duration = difftime(end_time, start_time);
    std::cout<< "\nfibo[" << ELEMENT_NO << "] = " << el;

    time(&start_time);
    constexpr long long int el2 = fiboRec(ELEMENT_NO);
    time(&end_time);
    duration = difftime(end_time, start_time);
    std::cout<< "\nfibo[" << ELEMENT_NO << "] = " << el2;

    // int y = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout<< "\nfibo[" << y << "] = " << fibo(i) << " - " << fiboRec(i);
    // }
   

    return 0;
}