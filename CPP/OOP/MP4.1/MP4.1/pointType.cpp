//
//  pointType.cpp
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//
#include "pointType.h"
#include <iostream>
using namespace std;

pointType::pointType(){};

pointType::pointType(double &n, double &m)
{
    d_x = n;
    d_y = m;
}

void pointType::setX(double n)
{
    d_x = n;
}
void pointType::setY(double m)
{
    d_y = m;
}
void pointType::setXY(double n, double m)
{
    d_x = n;
    d_y = m;
}

double const & pointType::getX() const
{
    return d_x;
}
double const & pointType::getY() const
{
    return d_y;
}

void pointType::print()
{
    cout << "x = " << d_x << ", y = " << d_y;
}


