//
//  main.cpp
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//

#include <iostream>
#include "pointType.h"
#include "cylinderType.h"
#include "circleType.h"
using namespace std;

void inputData(double &, double &, double &, double &);
void printData(double, double, double, double);

int main() {
    
    cout << "Point functions" << endl;
    pointType Point;
    
    //setting the coordinates of the point
    Point.setXY(5, 6);
    Point.setX(10);                     //modifying individually
    Point.setY(7);                      //modifying individually
    
    //printing the coordinates of the point
    Point.print();
    cout << endl;
    
    //returning the x-coordinate
    cout << "x = " << Point.getX() << ", ";
    //returning the y-coordinate
    cout << "y = " << Point.getY() << endl;
    
    cout << "Circle functions" << endl;
    circleType Circle;
    
    //setting the circle
    Circle.setCircle(100000, 43322, 10);
    //printing the radius
    Circle.pR();
    cout << endl;
    
    //calculating and printing the circumference
    Circle.calC();
    Circle.pC();
    cout << endl;
    //calculating and printing the area
    Circle.calA();
    Circle.pA();
    cout << endl;
    
    cout << "Cylinder functions" << endl;
    cylinderType Cylinder;
    //setter one
    Cylinder.setCylinder(1, 2, 3, 4);
    //reset the radius of the base
    Cylinder.setR(11);
    //reset the height
    Cylinder.setH(4);
    
    //calculating and printing the surface area
    Cylinder.calS();
    Cylinder.pS();
    cout << endl;
    //calculating and printing the volume
    Cylinder.calV();
    Cylinder.pV();
    cout << endl;
    
    //others
    Cylinder.setCircle(2, 3, 4);

    Cylinder.setCylinder(4, 5, 6, 7);

    
    cout << "User Input:" << endl;
    double n, m, r, h;
    bool quit = false;
    string q;
    while (quit == false)
    {
        inputData(n, m, r, h);
        printData(n, m, r, h);
        cout << "Input q to quit. Press any key to continue." << endl;
        cin >> q;
        if (q == "q")
            quit = true;
    }

    
    return 0;
}

void inputData(double & n, double & m, double & r, double & h)
{
    cout << "Enter the x-coordinate, y-coordinate, radius, and height (enter 0 if it is a circle.)" << endl;
    cin >> n >> m >> r >> h;
}

void printData(double n, double m, double r, double h)
{
    if (h == 0)
    {
        circleType outputCircle(n, m, r);
        cout << "The circumference of the circle is: " << outputCircle.calC() << "." << endl;
        cout << "The area of the circle is: " << outputCircle.calA() << "." << endl;
    }
    else
    {
        cylinderType outputCylinder(n, m, r, h);
        cout << "The surface area of the cylindar is: " << outputCylinder.calS() << "." << endl;
        cout << "The volume of the cylindar is: " << outputCylinder.calV() << "." << endl;
    }
}
