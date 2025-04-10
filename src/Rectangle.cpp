#include "Rectangle.hpp"


namespace GeoObj
{
    Rectangle::Rectangle(const std::vector<std::pair<double,double>> & coordinates) :
        GeometricObject(coordinates)
    {
        if(coordinates.size() == 2)
        {
            a_ = std::abs(corners_[0].first - corners_[1].first);
            b_ = std::abs(corners_[0].second - corners_[1].second);
        }
        else
        {
            a_ = 0;
            b_ = 0;
        }
    }

    double Rectangle::computeArea()
    {
        return a_*b_; 
    }

    void Rectangle::draw() 
    {
        Gnuplot gp;
        std::vector<std::pair<double,double>> xy_pts;
        for(auto corner: corners_)
        {
            xy_pts.push_back(corner);
        }
        gp << "set object 1 rectangle from " << 
        corners_[0].first << "," << corners_[0].second <<" to " 
        << corners_[1].first << "," << corners_[1].second 
        <<"fs empty border lc rgb 'blue'\n";
       //gp.send1d(xy_pts);
       gp << "plot [-1:4][-1:3] sin(x)\n";
        //gp.send1d(xy_pts);
    }


}