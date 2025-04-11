#include "GeometricObject.hpp"
#include <gtest/gtest.h>

TEST(GeometricObjectTest, DefaultConstructor) {
    GeoObj::GeometricObject obj;
    EXPECT_EQ(obj.getNumberOfConrners(), 0);
}

TEST(GeometricObjectTest, AddCorner) {
    GeoObj::GeometricObject obj;
    obj.addCorner({1.0, 2.0});
    EXPECT_EQ(obj.getNumberOfConrners(), 1);
    EXPECT_EQ(obj[0], std::make_pair(1.0, 2.0));
}

TEST(GeometricObjectTest, InsertCorner) {
    GeoObj::GeometricObject obj;
    obj.addCorner({1.0, 2.0});
    obj.addCorner({3.0, 4.0});
    obj.insterCorner(1, {2.0, 3.0});
    EXPECT_EQ(obj.getNumberOfConrners(), 3);
    EXPECT_EQ(obj[1], std::make_pair(2.0, 3.0));
}

TEST(GeometricObjectTest, ComputeArea) {
    GeoObj::GeometricObject obj;
    EXPECT_EQ(obj.computeArea(), 10); // Placeholder value
}

TEST(GeometricObjectTest, Draw) {
    GeoObj::GeometricObject obj;
    obj.addCorner({1.0, 1.0});
    obj.addCorner({2.0, 2.0});
    obj.addCorner({3.0, 1.0});
    EXPECT_NO_THROW(obj.draw());
}