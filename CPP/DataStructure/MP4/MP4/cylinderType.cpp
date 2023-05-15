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
    d_base.setCircle(n, m, r);
    d_height = h;
}

void cylinderType::setH(double h)
{
    d_height = h;
}

void cylinderType::setR(double r)
{
    d_base.setR(r);
}

void cylinderType::setXY(double n, double m)
{
    d_base.setXY(n, m);
}

void cylinderType::setCircle(double n, double m, double r)
{
    d_base.setCircle(n, m, r);
}

void cylinderType::setCylinder(double n, double m, double r, double h)
{
    setCircle(n, m, r);
    setH(h);
}


double const & cylinderType::getX() const
{
    return d_base.getX();
}

double const & cylinderType::getY() const
{
    return d_base.getY();
}

double const & cylinderType::getR() const
{
    return d_base.getR();
}

double const & cylinderType::getH() const
{
    return d_height;
}

double cylinderType::calV()
{
    return d_base.calA() * d_height;
}
double cylinderType::calS()
{
    return d_base.calC() * (d_base.getR() + d_height);
}


void cylinderType::pV()
{
    cout << "Volume = " << calV();
}

void cylinderType::pS()
{
    cout << "Surface area = " << calS();
}
