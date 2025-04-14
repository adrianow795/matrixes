
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
        auto area = 0.0;
        for(auto i = 0; i < corners_.size(); i++)
        {
            if(i != corners_.size()-1)
            {
                area += (corners_[i].first + corners_[i+1].first) *(corners_[i+1].second - corners_[i].second);
            }
            else
            {
                area += (corners_[i].first + corners_[0].first) *(corners_[0].second - corners_[i].second);
            }
        }
        return std::abs(area/2.0);
    }

    double GeometricObject::computeCircuit()
    {
        auto circuit = 0.0;
        for(auto i = 0; i < corners_.size(); i++)
        {
            if(i != corners_.size()-1)
            {
                auto x = (corners_[i+1].first - corners_[i].first);
                auto y = (corners_[i+1].second - corners_[i].second);
                circuit += std::sqrt(x*x + y*y);
            }
            else
            {
                auto x = (corners_[0].first - corners_[i].first);
                auto y = (corners_[0].second - corners_[i].second);
                circuit += std::sqrt(x*x + y*y);
            }
        }
        return circuit;
    }

    void GeometricObject::insertCorner(const size_t idx, const std::pair<double, double>& point)
    {
        auto it = corners_.begin();
        std::advance(it, idx);
        corners_.insert(it, point);
    }

    void GeometricObject::draw(Gnuplot& gp, const std::string& title, const std::string& color)
    {
        // Prepare the data for the object
        std::vector<std::pair<double, double>> modified_corners_vec(corners_);
        modified_corners_vec.push_back(corners_[0]); // Close the shape by connecting the last point to the first

        // Create a plot command for this object
        //gp << "set term wxt position 960, 540\n";
        gp << "set xrange [-10:10]\nset yrange [-10:10]\n";

        std::ostringstream plotCommand;
        plotCommand << "'-' with linespoints title '" << title << "' lc rgb '" << color << "'";
        // Send the plot command to Gnuplot
        gp << "plot " << plotCommand.str() << "\n";
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