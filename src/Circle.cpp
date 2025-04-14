#include "Circle.hpp"

namespace GeoObj
{
    Circle::Circle(const std::pair<double,double> center, const double r) 
        : GeometricObject(std::vector<std::pair<double, double>>{center})
        , r_(r)
    {
    }

    Circle::Circle(const std::vector<std::pair<double,double>> coordinates) 
        : GeometricObject(coordinates)
        , r_(0.0)
        {}

    double Circle::computeArea()
    {
        if(r_ != 0.0)
        {
            return M_PI * r_ * r_;
        }
        else
        {
            return GeometricObject::computeArea();
        }
        
    }

    double Circle::computeCircuit()
    {
        if(r_ != 0.0)
        {
            return 2 * M_PI * r_;
        }
        else
        {
            return GeometricObject::computeCircuit();
        }
    }

    void Circle::draw(Gnuplot& gp, const std::string& title, const std::string& color)
    {
        if(r_ != 0.0)
        {
            gp << "set title '" << title << "'\n";
            // gp << "set xrange ["<< corners_[0].first - 2*r_ - 1.0 << ":" <<corners_[0].first + 2*r_ + 1.0 <<"]\n";
            // gp << "set yrange ["<< corners_[0].second - 2*r_ - 1.0 << ":" <<corners_[0].second + 2*r_ + 1.0 <<"]\n";
            gp << "set object 1 circle at " << 
            corners_[0].first << "," << corners_[0].second <<" radius " 
            << r_ <<" fs empty border lc rgb '"<< color <<"'\n";

            gp << "plot  ["<< corners_[0].first - 2*r_ - 1.0 << ":" <<corners_[0].first + 2*r_ + 1.0 <<
            "] [" << corners_[0].second - 2*r_ - 1.0 << ":" <<corners_[0].second + 2*r_ + 1.0 <<"] 1/0 \n";
        }
        else
        {
            GeometricObject::draw(gp, title, color);
        }
    }

}