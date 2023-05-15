//
//  cylinderType.cpp
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//
#include "cylinderType.h"
#include <iostream>
using namespace std;

cylinderType::cylinderType(){};

cylinderType::cylinderType(double &n, double &m, double &r, double &h)
{
    setCircle(n, m, r);
    d_height = h;
}

void cylinderType::setH(double h)
{
    d_height = h;
}
void cylinderType::setCylinder(double n, double m, double r, double h)
{
    setCircle(n, m, r);
    setH(h);
}

double const & cylinderType::getH() const
{
    return d_height;
}

double cylinderType::calV()
{
    return calA() * d_height;
}
double cylinderType::calS()
{
    return calC() * (getR() + d_height);
}

void cylinderType::pV()
{
    cout << "Volume = " << calV();
}
void cylinderType::pS()
{
    cout << "Surface area = " << calS();
}
