#include "Square.hpp"


namespace GeoObj
{
    Square::Square(const std::vector<std::pair<double,double>> & coordinates) :
        GeometricObject(coordinates)
    {
        
    }

    double Square::computeArea()
    {
        auto a = std::abs(corners_[0].first - corners_[1].first);
        return a*a; 
    }
}