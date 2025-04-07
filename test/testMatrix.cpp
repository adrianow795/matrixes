#include "Matrix.hpp"
#include <gtest/gtest.h>
#include <ctime>
#include <cstdlib>

TEST(MatrixTest, MatrixConstructor) {
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
    m3 = m1 + m2;
    for(auto i = 0u; i < x; i++)
    {
        for(auto j =0u; j < x; j++)
        {
            EXPECT_EQ(m1[i][j] + m2[i][j], m3[i][j]);
        }
    }
    
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
