#ifndef GEOMETRIC_OBJECT_HPP_
#define GEOMETRIC_OBJECT_HPP_

#include "gnuplot-iostream.h"
#include <vector>
#include <iostream>


namespace GeoObj
{
    class GeometricObject
    {
        public:
        GeometricObject();
        GeometricObject(const std::vector<std::pair<double, double>>& corners);
        GeometricObject(std::vector<std::pair<double, double>>&& corners);

        size_t getNumberOfConrners();
        virtual double computeArea();
        virtual void drawGeoObj(); 
        void addCorner(const std::pair<double, double>& point);
        void printCorners();



        protected:
        std::vector<std::pair<double, double>> corners_;


    };
}



#endif // GEOMETRIC_OBJECT_HPP_