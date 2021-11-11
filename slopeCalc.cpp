// file: slopeCalc.cpp
//   HW:  Final Project
//   by:  A.Guerra
//  org:  COP 2001, 202101, 10410
// desc:  main application for slope intercept calculator and graph
// ----------------------------------------------------------------

#include <iostream>         // console library for debugging
#include <iomanip>          // format the console output
#define _USE_MATH_DEFINES   // enable M_PI
#include <math.h>           // sqrt, pow, atan2, M_PI
#include <string>           // convert to string

#include "fgcugl.h"         // FGCU OpenGL library
#include "slopeCalc.h"      // header file


// function declarations (prototype)
Mode getProblem();
Point getPoint();
void get2Point(Line& line);
void getPointSlope(Line& line);
void displayLine(Line line);
void display2Pt(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);

// main program

int main() {

    Mode item;

    // main loop
    do {

        item = getProblem();

        Line line = Line();

        // item specific calls
        if (item == TWO_POINT)
        {
            get2Point(line);
        }
        else if (item == POINT_SLOPE)
        {
            getPointSlope(line);
        }
        // common line code
        if (item != EXIT)
        {

            displayLine(line);

            // item specific calls
            if (item == TWO_POINT)
            {
                display2Pt(line);
            }
            else if (item == POINT_SLOPE)
            {
                displayPointSlope(line);
            }

            // display functions
             displaySlopeIntercept(line);
             drawLine(line);

        }

    } while (item != EXIT);

    return 0;

} // end main()


/**
 * Displays Main Menu and saves user input
 * Parameters:
 *
 * Returns:
 * Mode item
*/
Mode getProblem()
{
    Mode item;

    int userChoice;

    // main menu choices
    std::cout << "\nSelect the form you would like to convert to slope-intercept form: \n"
              << "\t1) Two-point form (you know the two points of the line)\n"
              << "\t2) Point-slope form (you know the line's slope and one point)\n"
              << "\t3) Exit\n"
              << "=> ";
    std::cin >> userChoice;

    item = static_cast<Mode>(userChoice);   // cast userChoice to Mode

    return item;
} // end getProblem


/**
 * Displays the menu prompt for the the specific menu choice
 * Returns:
 * x and y coord as Point
 *
*/
Point getPoint()
{
    float x;
    float y;
    std::cout << "\tEnter X and Y coordinates separated by spaces: ";
    std::cin >> x >> y;

    return(Point(x,y));
} // end getPoint()


/**
 * Takes a line and calls getPoint twice to populate the two properties of the line
 * Parameters:
 * Line line
*/
void get2Point(Line& line)
{
    std::cout << "\t Enter the first point: ";
    line.setPoint1(getPoint());

    std::cout << "\tEnter the second point: ";
    line.setPoint2(getPoint());

    line.calculateSlope();

} // end get2Point()

/**
 * Calls getPoint for one of the line properties and then prompts user for slope
 *
 * Parameters:
 * Line line
*/
void getPointSlope(Line& line)
{
    float slope;

    // std::cout << "\nEnter a point for the line";
    Point point1 = getPoint();

    std::cout << "\nEnter the slope for the line: ";
    std::cin >> slope;

    line = Line(point1, slope);

    float yIntercept = line.calculateYintercept();

    Point point2 = Point(0.0, yIntercept);

    line.setPoint2(point2);
}


/**
 * Displays property value on console
 *
 * Parameters:
 * Line line     // takes line and displays value on console
*/
void displayLine(Line line)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nLine: " << "\n";
    std::cout << "\tPoint - 1: (" << line.getPoint1().getXCoordinate() << ", " << line.getPoint1().getYCoordinate() << ")\n";
    std::cout << "\tPoint - 2: (" << line.getPoint2().getXCoordinate() << ", " << line.getPoint2().getYCoordinate() << ")\n";
    std::cout << "\tSlope = " << line.getSlope();
    std::cout << "\tY-Intercept = " << line.calculateYintercept();
    std::cout << "\n\tLength = " << line.calculateLength();
    std::cout << "\n\tAngle = " << line.calculateAngle();

} // end displayLine


/**
 * Display the two point form of the line on the console
 *
 * Parameters:
 * Line line  -  takes line and two point form of line on console
*/
void display2Pt(Line line)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nTwo-point form: ";
    std::cout << "\n\t      (" << line.getPoint2().getYCoordinate() << " - " << line.getPoint1().getYCoordinate() << ")";
    std::cout << "\n\tm = --------------------------- ";
    std::cout << "\n\t      (" << line.getPoint2().getXCoordinate() << " - " << line.getPoint1().getXCoordinate() << ")";

} // end display2pt


/**
 * Takes a Line and displays the point-slope form of the line on the console
 *
 * Parameters:
 * Line line // takes line and displays the point slope form on console
*/
void displayPointSlope(Line line)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n Point- slope Form: ";
    std:: cout << "\n\ty = " << line.getPoint1().getYCoordinate() << " = "
    << line.calculateSlope() << "(x + " << line.getPoint1().getXCoordinate();

} // end displayPointSlope


/**
 * Takes a Line and displays the slope-intercept form of the line on the console
 *
 * Parameters:
 * Line line  // takes line and displays slope intercept form on console
*/
void displaySlopeIntercept(Line line)
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n Slope Intercept Form: ";
    std:: cout << "\n\ty = " << line.calculateSlope() << "x + "
                << line.calculateYintercept();

} // end displaySlopeIntercept


/**
 * Graphs the line on the OpenGL window
 *
 * Parameters:
 * Line line   // take line and graph on OpenGL
*/
void drawLine(Line line)
{
    fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
    while (!fgcugl::windowClosing())
    {
        // x-axis
        fgcugl::drawLine(0, WINDOW_HEIGHT / 2.0, WINDOW_WIDTH, WINDOW_HEIGHT / 2.0 );

        // y-axis
        fgcugl::drawLine(WINDOW_WIDTH / 2.0, 0, WINDOW_WIDTH / 2.0, WINDOW_HEIGHT);

        // plot line

        // break into different variables so the line is not that long
        fgcugl::drawLine(line.getPoint1().getXCoordinate() + WINDOW_WIDTH /2.0, line.getPoint1().getYCoordinate() + WINDOW_HEIGHT / 2, line.getPoint2().getXCoordinate() + WINDOW_WIDTH / 2.0, line.getPoint2().getYCoordinate() +  WINDOW_HEIGHT / 2);

        fgcugl::windowPaint();

        fgcugl::getEvents();
    }

    fgcugl::cleanup();

} // end drawLine

