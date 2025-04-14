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
     * specific to circles, such as computing area, circuit, and drawing.
     */
    class Circle : public GeometricObject, public ObjectCounter<Circle>
    {
        public:
        /**
         * @brief Constructor with center and radius.
         * 
         * Initializes the circle with the given center and radius.
         * 
         * @param center The center of the circle.
         * @param r The radius of the circle.
         */
        Circle(const std::pair<double,double> center, const double r);

        /**
         * @brief Constructor with corner coordinates.
         * 
         * Initializes the circle with the given corner coordinates.
         * 
         * @param coordinates A vector of corner coordinates.
         */
        Circle(const std::vector<std::pair<double,double>> coordinates);

        /**
         * @brief Compute the area of the circle.
         * 
         * Calculates the area of the circle using the formula \( \pi r^2 \).
         * 
         * @return The computed area of the circle.
         */
        double computeArea() override;

        /**
         * @brief Compute the circuit of the circle.
         * 
         * Calculates the perimeter (circuit) of the circle using the formula \( 2 \pi r \).
         * 
         * @return The computed circuit of the circle.
         */
        double computeCircuit() override;

        /**
         * @brief Draw the circle using Gnuplot.
         * 
         * Visualizes the circle by plotting it with the specified center and radius.
         * 
         * @param gp The Gnuplot instance used for plotting.
         * @param title The title of the circle in the plot.
         * @param color The color of the circle in the plot.
         */
        void draw(Gnuplot& gp, const std::string& title, const std::string& color) override;

        private:
        double r_; ///< Radius of the circle.
    };
}

#endif // CIRCLE_HPP_