#include "Rectangle.hpp"
#include <gtest/gtest.h>

TEST(RectangleTest, ConstructorWithTwoCorners) {
    GeoObj::Rectangle rect({{1.0, 1.0}, {3.0, 4.0}});
    EXPECT_DOUBLE_EQ(rect.computeArea(), 6.0);
}

TEST(RectangleTest, ConstructorWithFourCorners) {
    GeoObj::Rectangle rect({{1.0, 1.0}, {1.0, 4.0}, {4.0, 4.0}, {4.0, 1.0}});
    EXPECT_DOUBLE_EQ(rect.computeArea(), 9.0);
    EXPECT_NO_THROW(rect.draw());
}

TEST(RectangleTest, DrawRectangle) {
    GeoObj::Rectangle rect({{1.0, 1.0}, {3.0, 4.0}});
    EXPECT_NO_THROW(rect.draw());
}