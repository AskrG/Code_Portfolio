//
//  circleType.cpp
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//

#include "circleType.h"
#include <iostream>

using namespace std;

circleType::circleType(){};

circleType::circleType(double &n, double &m, double &r)
{
    d_center.setXY(n, m);
    d_radius = r;
    
}

void circleType::setR(double r)
{
    d_radius = r;
}

void circleType::setX(double n)
{
    d_center.setX(n);
}

void circleType::setY(double m)
{
    d_center.setY(m);
}

void circleType::setXY(double n, double m)
{
    d_center.setXY(n, m);
}

void circleType::setCircle(double n, double m , double r)
{
    d_center.setXY(n, m);
    setR(r);
}



double const & circleType::getX() const
{
    return d_center.getX();
}

double const & circleType::getY() const
{
    return d_center.getY();
}

double const & circleType::getR() const
{
    return d_radius;
}


double circleType::calA()
{
    return 3.14 * d_radius * d_radius;
}

double circleType::calC()
{
    return 6.28 * d_radius;
}


void circleType::pR()
{
    cout << "Radius = " << d_radius;
}

void circleType::pXY()
{
    d_center.print();
}


void circleType::pA()
{
    cout << "Area = " << calA();
}

void circleType::pC()
{
    cout << "Circumference = " << calC();
}

