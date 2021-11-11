//  file:  line.cpp
//    HW:  Final Project
//    by:  A.Guerra
//   org:  COP 2001, 202101, 10410
//  desc:  implementation of a line class object
// ------------------------------------------------------------------
#include "line.h"
#include "point.h"
#define _USE_MATH_DEFINES   // enable M_PI
#include <math.h>           // sqrt, pow, atan2, M_PI

// constructors
// ------------------------------------------------------------------
/**
 * default constructor - initialize x and y
 */
Line::Line()
{
    point1 = Point();
    point2 = Point();
    float slope = 0.0;
}


/**
 * property constructor - initialize to parameter values
 */
Line::Line(Point point1, Point point2)
{
    this->point1 = point1;
    this->point2 = point2;
}

/**
 * property constructor - initialize to parameter values
 */
Line::Line(Point point1, float slope)
{
    this->point1 = point1;
    this->slope = slope;
}


// accessors
// ------------------------------------------------------------------
// getters (to get the private properties)
Point Line::getPoint1(){ return point1; }
Point Line::getPoint2(){ return point2; }
float Line::getSlope(){ return slope; }


// setters
// ------------------------------------------------------------------
void Line::setPoint1(Point value){ point1 = value; }
void Line::setPoint2(Point value){ point2 = value; }
void Line::setSlope(float value){ slope = value; }


// member methods
/**
 * calculate the difference in X of the two points
 *
 * Return:
 * differenceX
 */
float Line::diffXpoint()
{
    float differenceX = point2.getXCoordinate() - point1.getXCoordinate();

    return(differenceX);
}


/**
 * calculate the difference in Y of the two points
 *
 * Return:
 * difference
 */
 float Line::diffYpoint()
 {
     float differenceY = point2.getYCoordinate() - point1.getYCoordinate();

     return(differenceY);
 }


/**
 * calculate the slope from diffYpoint() and diffXpoint()
 *
 * Return:
 * slope
 */
float Line::calculateSlope()
{
     slope = diffYpoint() / diffXpoint();

     return(slope);
}


/**
 * calculate the y-intercept from a point and the slope
 *
 * Return:
 * yIntercept
 */
float Line::calculateYintercept()
{
        float yIntercept = point1.getYCoordinate() - (slope * point1.getXCoordinate());

        return yIntercept;
}


/**
 * Takes two points and returns the length between the two as a float
 *
 * Returns:
 * float distance // the distance between two points
*/
float Line::calculateLength()
{
    float distance = std::sqrt(std::pow(diffXpoint(), 2) + std::pow(diffYpoint(), 2));

    return distance;
}


/**
 * Takes two points and returns the line's angle from the top of the y-axis
 *
 * Returns:
 * float angle - cardinal // angle between both of the points
*/
float Line::calculateAngle()
{
    float radians = std::atan2(diffYpoint(), diffXpoint());
    float angle = radians * 180.0 / M_PI;     // relative to the x-axis
    float degrees = 90.0 - angle;             // rotate angle to left 90 degrees
    float cardinal = (degrees > 0.0 ? degrees : degrees + 360.0); // fix negative degrees

    return cardinal;
}