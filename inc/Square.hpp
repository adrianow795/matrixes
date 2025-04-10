#ifndef SQUARE_HPP_
#define SQUARE_HPP_

#include "GeometricObject.hpp"


namespace GeoObj
{
    class Square : private GeometricObject
    {
        public:
        Square(const std::vector<std::pair<double,double>> & coordinates);
        double computeArea() override;


    };
}

#endif // SQUARE_HPP_
