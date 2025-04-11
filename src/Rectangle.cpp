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
            a_ = 0;
            b_ = 0;
        }
    }

    double Rectangle::computeArea()
    {
        auto cornersNumber = getNumberOfConrners();
        if(cornersNumber == 2)
        {
            return a_*b_; 
        }
        else if(cornersNumber == 4)
        {
            auto it_ref = corners_.begin();
            it_ref++;
            auto it_a = std::find_if(it_ref, corners_.end(),[&]
                (std::pair<double, double> x)
                {
                    return corners_[0].first == x.first;
                });
            auto it_b = std::find_if(it_ref, corners_.end(),[&]
                (std::pair<double, double> x)
                {
                    return corners_[0].second == x.second;
                });
            
            a_ = std::abs(corners_[0].second - it_a.operator*().second);
            b_ = std::abs(corners_[0].first - it_b.operator*().first);
            return a_*b_; 
        }
        else
        {
            return 0;
        }
    }

    void Rectangle::draw() 
    {
        Gnuplot gp;
        auto cornersNumber = getNumberOfConrners();
        if(cornersNumber == 2)
        {
            gp << "set object 1 rectangle from " << 
                corners_[0].first << "," << corners_[0].second <<" to " 
                << corners_[1].first << "," << corners_[1].second 
                <<"fs empty border lc rgb 'blue'\n";
            gp << "plot [-1:5][-1:5] 1/0 notitle\n";
        }
        else
        {
            GeometricObject::draw();
        }

    }


}