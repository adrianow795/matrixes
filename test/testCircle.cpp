#include "Circle.hpp"
#include <gtest/gtest.h>
#include "gnuplot-iostream.h"

TEST(CircleTest, Constructor) {
    GeoObj::Circle circle({2.0, 2.0}, 3.0);
    EXPECT_DOUBLE_EQ(circle.computeArea(), M_PI * 3.0 * 3.0);
    EXPECT_DOUBLE_EQ(circle.computeCircuit(), 2 * M_PI * 3.0);
}

TEST(CircleTest, Constructor2) {
    std::pair<double, double> center(2.0, 2.0);
    int num_points = 100;
    double radius = 3.0;
    // Generate points on the circle
    std::vector<std::pair<double, double>> points;
    points.reserve(num_points);

    const double angle_step = 2 * M_PI / num_points; // Step size for angles

    for (int i = 0; i < num_points; ++i) {
        double angle = i * angle_step;
        double x = center.first + radius * std::cos(angle);
        double y = center.second + radius * std::sin(angle);
        points.emplace_back(x, y);
    }
    GeoObj::Circle circle(points);
    double area = circle.computeArea();
    double circuit = circle.computeCircuit();
    const auto expected_area = M_PI * radius * radius;
    const auto expected_circuit = 2 * M_PI *radius;
    EXPECT_TRUE( (area > expected_area*0.9) && (area < expected_area*1.1) );
    EXPECT_TRUE( (circuit > expected_circuit*0.9) && (circuit < expected_circuit*1.1) );

}


TEST(CircleTest, DrawCircle) {
    GeoObj::Circle circle({2.0, 2.0}, 3.0);
    Gnuplot gp;
    EXPECT_NO_THROW(circle.draw(gp, "Circle", "red"));
}

TEST(CircleTest, DrawCircle2) {
    std::pair<double, double> center(2.0, 2.0);
    int num_points = 100;
    double radius = 3.0;
    // Generate points on the circle
    std::vector<std::pair<double, double>> points;
    points.reserve(num_points);

    const double angle_step = 2 * M_PI / num_points; // Step size for angles

    for (int i = 0; i < num_points; ++i) {
        double angle = i * angle_step;
        double x = center.first + radius * std::cos(angle);
        double y = center.second + radius * std::sin(angle);
        points.emplace_back(x, y);
    }
    GeoObj::Circle circle(points);
    Gnuplot gp;
    EXPECT_NO_THROW(circle.draw(gp, "Circle", "red"));
}