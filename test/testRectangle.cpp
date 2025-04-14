#include "Rectangle.hpp"
#include <gtest/gtest.h>
#include "gnuplot-iostream.h"

TEST(RectangleTest, ConstructorWithTwoCorners) {
    GeoObj::Rectangle rect({{1.0, 1.0}, {3.0, 4.0}});
    EXPECT_DOUBLE_EQ(rect.computeArea(), 6.0);
    EXPECT_DOUBLE_EQ(rect.computeCircuit(), 10.0);
}

TEST(RectangleTest, ConstructorWithFourCorners) {
    GeoObj::Rectangle rect({{1.0, 1.0}, {1.0, 4.0}, {4.0, 4.0}, {4.0, 1.0}});
    EXPECT_DOUBLE_EQ(rect.computeArea(), 9.0);
    EXPECT_DOUBLE_EQ(rect.computeCircuit(), 12.0);
}

TEST(RectangleTest, DrawRectangle) {
    GeoObj::Rectangle rect({{1.0, 1.0}, {3.0, 4.0}});
    Gnuplot gp;
    EXPECT_NO_THROW(rect.draw(gp, "Rectangle", "blue"));
}