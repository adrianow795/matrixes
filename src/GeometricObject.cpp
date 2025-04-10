
#include "GeometricObject.hpp"

namespace GeoObj
{
    GeometricObject::GeometricObject()
    {
        
    }
    GeometricObject::GeometricObject(const std::vector<std::pair<double, double>>& corners) : corners_(corners)
    {
    }

    GeometricObject::GeometricObject(std::vector<std::pair<double, double>>&& corners) : corners_(corners)
    {
    }

    size_t GeometricObject::getNumberOfConrners()
    {
        return corners_.size();
    }

    std::pair<double, double>& GeometricObject::operator[] (size_t idx)
    {
        return corners_[idx];
    }

    double GeometricObject::computeArea()
    {
        return 10;
    }

    void GeometricObject::draw()
    {
        
    }

    void GeometricObject::addCorner(const std::pair<double, double>& point)
    {
        corners_.push_back(point);
    }

    void GeometricObject::printCorners()
    {
        for(auto corner: corners_)
        {
            std::cout << "(" << corner.first << ", " << corner.second << ")\n";
        }
    }

}