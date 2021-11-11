// file: slopeCalc.cpp
//   HW:  Final Project
//   by:  A.Guerra
//  org:  COP 2001, 202101, 10410
// desc:  main header file for slope intercept calculator and graph
// ------------------------------------------------------------------
#ifndef SLOPECALC_H
#define SLOPECALC_H

#include "point.h"  // point objects
#include "line.h"   // line objects

// Global defines

// main game window properties
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const std::string WINDOW_TITLE = "The BEST Linear Graph EVER";

//
enum Mode {
    TWO_POINT = 1,
    POINT_SLOPE,
    EXIT
};


#endif //SLOPECALC_H
