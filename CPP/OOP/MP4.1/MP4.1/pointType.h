//
//  pointType.hpp
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//
#ifndef pointType_h
#define pointType_h
#include <stdio.h>
#include <iostream>
using namespace std;

class pointType
{
protected:
    double d_x;
    double d_y;
public:
    pointType();
    pointType(double &, double &);
    
    void setX(double);
    void setY(double);
    void setXY(double, double);
    
    double const & getX() const;
    double const & getY() const;
    
    void print();
    
};

#endif /* pointType_h */
