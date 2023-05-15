//
//  main.cpp
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//

/*
 The center of the circle is a point in the x-y plane. Design a class, circleType, that can store the radius and center of the circle. Because the center is a point in the x-y plane and you designed the class to capture the properties of a point, in addition to the radius member, create a member of type class pointType. You should be able to perform the usual operations on the circle, such as setting the radius, printing the radius, calculating and printing the area and circumference, and carrying out the usual operations on the center.
  

 Also create a Class/Inheritance Diagram which shows your design. An example of how your diagram is attached as a JPEG

 */

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
    
    //setting the radius
    Circle.setR(10);
    //printing the radius
    Circle.pR();
    cout << endl;
    
    //carrying out the usual operations on the center
    Circle.setXY(5, 2);
    Circle.setX(9);
    cout << "x = " << Circle.getX() << endl;
    Circle.pXY();
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

    //set the center of the base
    Cylinder.setXY(5, 8);
    //set the radius of the base
    Cylinder.setR(11);
    //set the height
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
    cout << "New y = " << Cylinder.getY() << endl;
    Cylinder.setCylinder(4, 5, 6, 7);
    cout << "New y = " << Cylinder.getX() << endl;
    
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
        cout << "The surface area of the circle is: " << outputCylinder.calS() << "." << endl;
        cout << "The volume of the circle is: " << outputCylinder.calV() << "." << endl;
    }
}
