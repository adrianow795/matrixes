#include <iostream>
#include "Matrix.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <numeric>
#include "GeometricObject.hpp"
#include "gnuplot-iostream.h"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "ObjectCounter.hpp"
#include <memory>
#include <vector>
#include <cmath>
#include <utility>

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
std::vector<std::pair<double, double>> generateCirclePoints(
    const std::pair<double, double>& center, 
    double radius, 
    int num_points) ;
void MultiplicationTest();
void GnuPlotExample();
void GnuPlotExample2();

void CircleTest();
void RectTest();
int main()
{
    ObjectCounter<GeoObj::Circle> circle_ctr;
    ObjectCounter<GeoObj::Rectangle> rectangle_ctr;
    ObjectCounter<GeoObj::GeometricObject> geoObj_ctr;
    //MultiplicationTest();
    //GnuPlotExample();
    //GnuPlotExample2();
    RectTest();
    CircleTest();
    std::cout << "------------------------\n";
    std::cout << "ObjectCounter test\n";
    std::cout << "------------------------\n";
    std::cout << circle_ctr.c_tor_ctr << " Circles were created and " << circle_ctr.d_tor_ctr << " deleted\n";
    std::cout << rectangle_ctr.c_tor_ctr << " Rectangles were created and " << rectangle_ctr.d_tor_ctr << " deleted\n";
    std::cout << geoObj_ctr.c_tor_ctr << " GeoObjs were created and " << geoObj_ctr.d_tor_ctr << " deleted\n";
    

    return 0;
}


void RectTest()
{
    Gnuplot gp;

    
    GeoObj::Rectangle r1 ({{1.0, 2.0}, {3.0,3.0}});
    std::cout << "Rect1 area: " << r1.computeArea() << " and circuit: " << r1.computeCircuit() << "\nGive color: \n";
    std::string abc;
    std::cin >> abc;
    r1.draw(gp, "Rect1", abc);

    GeoObj::Rectangle r2 ({{1.0, 2.0}, {3.0,2.0}, {3.0,3.0}, {1.0,3.0}});
    std::cout << "\nRect2 area: " << r2.computeArea() << " and circuit: " << r2.computeCircuit() << "\n";
    //r2.draw(gp, "Rect2", "red");

    std::cin >> abc;
}

void CircleTest()
{
    Gnuplot gp;

    //gp << "plot NaN\n";
    auto vec = generateCirclePoints({0,0}, 4.0, 20);
    GeoObj::Circle x(vec);
    x.draw(gp, "Circle 1", "red");
    
    std::cout << "Circle area:::x1(20): " << x.computeArea() << std::endl;
    auto vec2 = generateCirclePoints({1.0,1.0}, 4.0, 40);
    GeoObj::Circle x2(vec2);

    int n;
    //std::cin >> n;

    
    x2.draw(gp, "Circle 2", "blue");
    std::cout << "Circle area:::x2(40): " << x2.computeArea() << std::endl;
    //std::cin >> n;

    auto vec3 = generateCirclePoints({2.0,-1.0}, 4.0, 100);
    GeoObj::Circle x3(vec3);
    x3.draw(gp, "Circle 3", "green");
    std::cout << "Circle area:::x3(100): " << x3.computeArea() << std::endl;

    GeoObj::Circle x4(std::make_pair(2.0, -2.0), 3.0);
    x4.draw(gp, "Circle 3", "red");
    std::cout << "Circle area:::x4(circle): " << x4.computeArea() << std::endl;
    
}

void MultiplicationTest()
{
    constexpr size_t dim = 50;
    Matrix<int,dim,dim> d1;
    Matrix<int,dim,dim> d2;

    for(auto i = 0u; i < 2; i++)
    {
        for(auto j =0u; j < 3; j++)
        {
            d1[i][j] = (std::rand() % 100) ;
        }
    }

    for(auto i = 0u; i < 3; i++)
    {
        for(auto j =0u; j < 2; j++)
        {
            d2[i][j] = (std::rand() % 100) ;
        }
    }
    constexpr auto number_of_runs = 40;
    std::vector<int64_t> durations;
    for(auto i = 0; i < number_of_runs; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = d1.multiplyBy(d2);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        durations.push_back(duration);
    }
    auto min_duration = *std::min_element(durations.begin(), durations.end()); //return an intterator to smalest element
    auto max_duration = *std::max_element(durations.begin(), durations.end());
    auto average_duration = std::accumulate(durations.begin(), durations.end(), 0.0) / durations.size();

    std::cout << "[multiplyBy]            Min: " << min_duration << " Max: " << max_duration<< " Average: " << average_duration <<  " microseconds" << std::endl;

    for(auto i = 0; i < number_of_runs; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = d1.multiplyByWithThreads(d2);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        durations[i] = duration;
        //std::cout << "Time taken by multiplyByWithThreads: " << duration.count() << " microseconds" << std::endl;
    }
    min_duration = *std::min_element(durations.begin(), durations.end()); //return an intterator to smalest element
    max_duration = *std::max_element(durations.begin(), durations.end());
    average_duration = std::accumulate(durations.begin(), durations.end(), 0.0) / durations.size();
    std::cout << "[multiplyByWithThreads] Min: " << min_duration << " Max: " << max_duration<< " Average: " << average_duration <<  " microseconds" << std::endl;
}

void GnuPlotExample()
{
    Gnuplot gp;
    std::vector<std::pair<double, double>> points = {
        {1, 1}, // A
        {1, 4}, // B
        {4, 4}, // D
        {4, 1}, //
        {4, 1}  
    };
    gp << "plot [-1:5][-1:5] '-' with linespoints title 'Path A->B->D->C'\n";
    gp.send1d(points);
}

void GnuPlotExample2()
{
    Gnuplot gp;
    std::vector<std::pair<double,double>> xy_pts;


    xy_pts.push_back(std::make_pair(1,1));
    xy_pts.push_back(std::make_pair(3,4));


    gp << "set object 1 rectangle from " << 
    xy_pts[0].first << "," << xy_pts[0].second <<" to " 
    << xy_pts[1].first << "," << xy_pts[1].second 
    <<"fs empty border lc rgb 'blue'\n";
   //gp.send1d(xy_pts);
   gp << "plot [-1:4][-1:3] sin(x)\n";
}


/**
 * @brief Generates a vector of points representing a circle.
 * 
 * This function generates a vector of points (x, y) that lie on the circumference
 * of a circle with a given center, radius, and number of points.
 * 
 * @param center The center of the circle as a pair (x, y).
 * @param radius The radius of the circle.
 * @param num_points The number of points to generate on the circle.
 * @return A vector of pairs representing the points on the circle.
 */
std::vector<std::pair<double, double>> generateCirclePoints(
    const std::pair<double, double>& center, 
    double radius, 
    int num_points) 
{
    std::vector<std::pair<double, double>> points;
    points.reserve(num_points);

    const double angle_step = 2 * M_PI / num_points; // Step size for angles

    for (int i = 0; i < num_points; ++i) {
        double angle = i * angle_step;
        double x = center.first + radius * std::cos(angle);
        double y = center.second + radius * std::sin(angle);
        points.emplace_back(x, y);
    }

    return points;
}