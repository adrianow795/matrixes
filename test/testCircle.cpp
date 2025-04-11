#include "Circle.hpp"
#include <gtest/gtest.h>

TEST(CircleTest, Constructor) {
    GeoObj::Circle circle({2.0, 2.0}, 3.0);
    EXPECT_DOUBLE_EQ(circle.computeArea(), 3.14 * 3.0 * 3.0);
}

TEST(CircleTest, DrawCircle) {
    GeoObj::Circle circle({2.0, 2.0}, 3.0);
    EXPECT_NO_THROW(circle.draw());
}