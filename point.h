//  file:  point.h
//    HW:  Final
//    by:  A.Guerra
//   org:  COP 2001, 202101, 10410
//  desc:  declaration of a point class object
// ------------------------------------------------------------------
#ifndef POINT_H
#define POINT_H

#include "fgcugl.h"

class Point{
public:
    // constructors
    Point();
    Point(float x, float y);

    // accessors
    // getters (to get the private properties)
    float getXCoordinate();
    float getYCoordinate();

    // setters
    void setXCoordinate(float value);
    void setYCoordinate(float value);


private:
    float xCoordinate;
    float yCoordinate;
};


#endif POINT_H // POINT_H
