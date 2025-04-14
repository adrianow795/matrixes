#ifndef GEOMETRIC_OBJECT_HPP_
#define GEOMETRIC_OBJECT_HPP_

#include "gnuplot-iostream.h"
#include <vector>
#include <iostream>
#include "ObjectCounter.hpp"

namespace GeoObj
{
    /**
     * @class GeometricObject
     * @brief Base class for geometric objects.
     * 
     * This class provides common functionality for geometric objects,
     * such as managing corners, computing areas, and drawing shapes.
     */
    class GeometricObject : public ObjectCounter<GeometricObject>
    {
        public:
        /**
         * @brief Default constructor.
         * 
         * Initializes an empty geometric object with no corners.
         */
        GeometricObject();

        /**
         * @brief Constructor with corners.
         * 
         * Initializes the geometric object with the given corners.
         * 
         * @param corners A vector of corner coordinates.
         */
        GeometricObject(const std::vector<std::pair<double, double>>& corners);

        /**
         * @brief Get the number of corners.
         * 
         * @return The number of corners in the geometric object.
         */
        size_t getNumberOfConrners();

        /**
         * @brief Compute the area of the geometric object.
         * 
         * This method should be overridden by derived classes to compute
         * the specific area of the geometric shape.
         * 
         * @return The computed area.
         */
        virtual double computeArea();

        /**
         * @brief Compute the circuit of the geometric object.
         * 
         * This method should be overridden by derived classes to compute
         * the specific circuit of the geometric shape.
         * 
         * @return The computed circuit.
         */
        virtual double computeCircuit();

        /**
         * @brief Draw the geometric object using Gnuplot.
         * 
         * This method visualizes the geometric object by plotting its corners
         * and connecting them with lines.
         * 
         * @param gp The Gnuplot instance used for plotting.
         * @param title The title of the object in the plot.
         * @param color The color of the object in the plot.
         */
        virtual void draw(Gnuplot& gp, const std::string& title, const std::string& color); 

        /**
         * @brief Add a corner to the geometric object.
         * 
         * Appends a new corner to the list of corners.
         * 
         * @param point The coordinates of the corner to add.
         */
        void addCorner(const std::pair<double, double>& point);

        /**
         * @brief Print the coordinates of all corners.
         * 
         * Outputs the coordinates of all corners to the console.
         */
        void printCorners();

        /**
         * @brief Insert a corner at a specific index.
         * 
         * Inserts a new corner at the specified index in the list of corners.
         * 
         * @param idx The index at which to insert the corner.
         * @param point The coordinates of the corner to insert.
         */
        void insertCorner(const size_t idx, const std::pair<double, double>& point);
        
        /**
         * @brief Access a corner by index.
         * 
         * Provides access to a specific corner by its index.
         * 
         * @param idx The index of the corner.
         * @return A reference to the corner.
         */
        std::pair<double, double>& operator[] (size_t idx);

        protected:
        std::vector<std::pair<double, double>> corners_; ///< Vector of corner coordinates.
        size_t number_of_corners_; ///< Number of corners.

    };
}

#endif // GEOMETRIC_OBJECT_HPP_