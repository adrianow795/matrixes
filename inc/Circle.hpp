#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "GeometricObject.hpp"

namespace GeoObj
{
    class Circle : private GeometricObject
    {
        public:
        Circle(const std::pair<double,double> center, const double r);
        double computeArea() override;
        void draw() override;

        private:
        double r_;

    };
}


#endif // CIRCLE_HPP_
