#include "ObjectCounter.hpp"
#include "GeometricObject.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

template<>
int ObjectCounter<GeoObj::GeometricObject>::c_tor_ctr = 0;
template<>
int ObjectCounter<GeoObj::GeometricObject>::d_tor_ctr = 0;


template<>
int ObjectCounter<GeoObj::Circle>::c_tor_ctr = 0;
template<>
int ObjectCounter<GeoObj::Circle>::d_tor_ctr = 0;

template<>
int ObjectCounter<GeoObj::Rectangle>::c_tor_ctr = 0;
template<>
int ObjectCounter<GeoObj::Rectangle>::d_tor_ctr = 0;

