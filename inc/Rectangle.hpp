#ifndef SQUARE_HPP_
#define SQUARE_HPP_

#include "GeometricObject.hpp"
#include "ObjectCounter.hpp"

namespace GeoObj
{
    /**
     * @class Rectangle
     * @brief Represents a rectangle.
     * 
     * This class inherits from GeometricObject and provides functionality
     * specific to rectangles, such as computing area and drawing.
     */
    class Rectangle : private GeometricObject, public ObjectCounter<Rectangle>
    {
        public:
        /**
         * @brief Constructor with corner coordinates.
         * @param coordinates A vector of two corner coordinates.
         */
        Rectangle(const std::vector<std::pair<double,double>> & coordinates);

        /**
         * @brief Compute the area of the rectangle.
         * @return The computed area.
         */
        double computeArea() override;

        /**
         * @brief Draw the rectangle using Gnuplot.
         */
        void draw() override;

        private:
        double a_; ///< Length of the rectangle.
        double b_; ///< Width of the rectangle.
    };
}

#endif // SQUARE_HPP_
