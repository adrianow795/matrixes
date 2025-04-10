#ifndef SQUARE_HPP_
#define SQUARE_HPP_

#include "GeometricObject.hpp"


namespace GeoObj
{
    class Rectangle : private GeometricObject
    {
        public:
        Rectangle(const std::vector<std::pair<double,double>> & coordinates);
        double computeArea() override;
        void draw() override;

        private:
        double a_, b_;


    };
}

#endif // SQUARE_HPP_
