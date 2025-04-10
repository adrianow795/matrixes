#include "Circle.hpp"

namespace GeoObj
{
    Circle::Circle(const std::pair<double,double> center, const double r) 
        : GeometricObject(std::vector<std::pair<double, double>>{center})
        , r_(r)
    {
    }

    double Circle::computeArea()
    {
        return 3.14 * r_ * r_;
    }

    void Circle::draw() 
    {
        Gnuplot gp;
        std::vector<std::pair<double,double>> xy_pts;
        for(auto corner: corners_)
        {
            xy_pts.push_back(corner);
        }
        gp << "set object 1 circle at " << 
        corners_[0].first << "," << corners_[0].second <<" radius " 
        << r_ <<" fs empty border lc rgb 'red'\n";
        gp << "plot [-1:5][-1:5] 1/0 notitle\n";

    }

}