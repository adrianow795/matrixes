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
        virtual void draw(); 
        void addCorner(const std::pair<double, double>& point);
        void printCorners();

        std::pair<double, double>& operator[] (size_t idx);



        protected:
        std::vector<std::pair<double, double>> corners_;
        size_t number_of_corners_;


    };
}



#endif // GEOMETRIC_OBJECT_HPP_