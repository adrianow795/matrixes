#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "GeometricObject.hpp"
#include "ObjectCounter.hpp"

namespace GeoObj
{
    /**
     * @class Circle
     * @brief Represents a circle.
     * 
     * This class inherits from GeometricObject and provides functionality
     * specific to circles, such as computing area and drawing.
     */
    class Circle : private GeometricObject, public ObjectCounter<Circle>
    {
        public:
        /**
         * @brief Constructor with center and radius.
         * @param center The center of the circle.
         * @param r The radius of the circle.
         */
        Circle(const std::pair<double,double> center, const double r);

        /**
         * @brief Compute the area of the circle.
         * @return The computed area.
         */
        double computeArea() override;

        /**
         * @brief Draw the circle using Gnuplot.
         */
        void draw() override;

        private:
        double r_; ///< Radius of the circle.
    };
}

#endif // CIRCLE_HPP_
