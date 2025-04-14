
#include "GeometricObject.hpp"

namespace GeoObj
{
    GeometricObject::GeometricObject()
    {
        
    }
    GeometricObject::GeometricObject(const std::vector<std::pair<double, double>>& corners) : corners_(corners)
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

    void GeometricObject::insterCorner(const size_t idx, const std::pair<double, double>& point)
    {
        auto it = corners_.begin();
        std::advance(it, idx);
        corners_.insert(it, point);
    }

    void GeometricObject::draw()
    {
        Gnuplot gp;
        std::vector<std::pair<double, double>> modified_corners_vec(corners_);
        modified_corners_vec.push_back(corners_[0]);
        gp << "plot [-1:5][-1:5] '-' with linespoints title 'Path over provided points'\n";
        gp.send1d(modified_corners_vec);
    }

    void GeometricObject::addCorner(const std::pair<double, double>& point)
    {
        corners_.push_back(point);
    }

    void GeometricObject::printCorners()
    {   
        auto idx = 0;
        for(auto corner: corners_)
        {
            std::cout << "[" << idx++ << "]:" << "(" << corner.first << ", " << corner.second << ")\n";
        }
    }

}