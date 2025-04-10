#ifndef GEOMETRIC_OBJECT_HPP_
#define GEOMETRIC_OBJECT_HPP_

#include "gnuplot-iostream.h"
#include <vector>
#include <iostream>

namespace GeoObj
{
    /**
     * @class GeometricObject
     * @brief Base class for geometric objects.
     * 
     * This class provides common functionality for geometric objects,
     * such as managing corners and computing areas.
     */
    class GeometricObject
    {
        public:
        /**
         * @brief Default constructor.
         */
        GeometricObject();

        /**
         * @brief Constructor with corners.
         * @param corners A vector of corner coordinates.
         */
        GeometricObject(const std::vector<std::pair<double, double>>& corners);

        /**
         * @brief Constructor with rvalue reference to corners.
         * @param corners A vector of corner coordinates (rvalue reference).
         */
        GeometricObject(std::vector<std::pair<double, double>>&& corners);

        /**
         * @brief Get the number of corners.
         * @return The number of corners.
         */
        size_t getNumberOfConrners();

        /**
         * @brief Compute the area of the geometric object.
         * @return The computed area.
         */
        virtual double computeArea();

        /**
         * @brief Draw the geometric object using Gnuplot.
         */
        virtual void draw(); 

        /**
         * @brief Add a corner to the geometric object.
         * @param point The coordinates of the corner to add.
         */
        void addCorner(const std::pair<double, double>& point);

        /**
         * @brief Print the coordinates of all corners.
         */
        void printCorners();

        /**
         * @brief Access a corner by index.
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