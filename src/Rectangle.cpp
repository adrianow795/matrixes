#include "Rectangle.hpp"
#include <algorithm>

namespace GeoObj
{
    Rectangle::Rectangle(const std::vector<std::pair<double,double>> & coordinates) :
        GeometricObject(coordinates)
    {
        auto cornersNumber = getNumberOfConrners();
        if(cornersNumber == 2)
        {
            a_ = std::abs(corners_[0].first - corners_[1].first);
            b_ = std::abs(corners_[0].second - corners_[1].second);
        }
        else
        {
            a_ = 0.0;
            b_ = 0.0;
        }
    }

    double Rectangle::computeArea()
    {

        if(getNumberOfConrners() == 2)
        {
            return a_*b_; 
        }
        else
        {
            return GeometricObject::computeArea();
        }
    }

    double Rectangle::computeCircuit()
    {
        if(getNumberOfConrners() == 2)
        {
            return 2* a_ + 2*b_;
        }
        else
        {
            return GeometricObject::computeCircuit();
        }

    }

    void Rectangle::draw(Gnuplot& gp, const std::string& title, const std::string& color)
    {
        if(getNumberOfConrners() == 2)
        {
            gp << "set title '" << title << "'\n";
            gp << "set object 1 rectangle from " << 
                corners_[0].first << "," << corners_[0].second <<" to " 
                << corners_[1].first << "," << corners_[1].second 
                <<"fs empty border lc rgb '"<< color << "'\n";
            gp << "plot [-1:5][-1:5] 1/0 \n";
            
        }
        else
        {
            GeometricObject::draw(gp, title, color);
        }

    }


}