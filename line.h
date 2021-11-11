//  file:  line.h
//    HW:  Final
//    by:  A.Guerra
//   org:  COP 2001, 202101, 10410
//  desc:  declaration of a line class object
// ------------------------------------------------------------------

#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line {
public:
    // constructors
    Line();
    Line(Point point1, Point point2);
    Line(Point point1, float slope);

    // accessors
    // getters
    Point getPoint1();
    Point getPoint2();
    float getSlope();

    //setters
    void setPoint1(Point value);
    void setPoint2(Point value);
    void setSlope(float value);

    // member methods
    float diffXpoint();
    float diffYpoint();
    float calculateSlope();
    float calculateYintercept();
    float calculateLength();
    float calculateAngle();

private:
    Point point1;
    Point point2;
    float slope;

};

#endif LINE_H
