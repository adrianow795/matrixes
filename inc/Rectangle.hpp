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
     * specific to rectangles, such as computing area, circuit, and drawing.
     */
    class Rectangle : public GeometricObject, public ObjectCounter<Rectangle>
    {
        public:
        /**
         * @brief Constructor with corner coordinates.
         * 
         * Initializes the rectangle with the given corner coordinates.
         * 
         * @param coordinates A vector of two or four corner coordinates.
         */
        Rectangle(const std::vector<std::pair<double,double>> & coordinates);

        /**
         * @brief Compute the area of the rectangle.
         * 
         * Calculates the area of the rectangle based on its corner coordinates.
         * 
         * @return The computed area of the rectangle.
         */
        double computeArea() override;

        /**
         * @brief Compute the circuit of the rectangle.
         * 
         * Calculates the perimeter (circuit) of the rectangle based on its corner coordinates.
         * 
         * @return The computed circuit of the rectangle.
         */
        double computeCircuit() override;

        /**
         * @brief Draw the rectangle using Gnuplot.
         * 
         * Visualizes the rectangle by plotting its corners and connecting them with lines.
         * 
         * @param gp The Gnuplot instance used for plotting.
         * @param title The title of the rectangle in the plot.
         * @param color The color of the rectangle in the plot.
         */
        void draw(Gnuplot& gp, const std::string& title, const std::string& color) override;

        private:
        double a_; ///< Length of the rectangle.
        double b_; ///< Width of the rectangle.
    };
}

#endif // SQUARE_HPP_