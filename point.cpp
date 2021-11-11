//  file:  point.cpp
//    HW:  Final Project
//    by:  A.Guerra
//   org:  COP 2001, 202101, 10410
//  desc:  implementation of a point class object
// ------------------------------------------------------------------
#include "point.h"

// constructors
// ------------------------------------------------------------------
/**
 * default constructor - initialize x and y
 */
 Point::Point()
{
     xCoordinate = 0;
     yCoordinate = 0;
}


/**
 * property constructor - initialize to parameter values 
 */
Point::Point(float x, float y)
{
     xCoordinate = x;
     yCoordinate = y;
}


// accessors
// ------------------------------------------------------------------
// getters (to get the private properties)
float Point::getXCoordinate(){ return xCoordinate; }
float Point::getYCoordinate(){ return yCoordinate; }


// setters
// ------------------------------------------------------------------
void Point::setXCoordinate(float value){ xCoordinate = value; }
void Point::setYCoordinate(float value){ yCoordinate = value; }


