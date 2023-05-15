//
//  cylinderType.h
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//

#ifndef cylinderType_h
#define cylinderType_h

#include <stdio.h>
#include <iostream>

#include "circleType.h"

using namespace std;


class cylinderType
{
    circleType d_base;
    double d_height;
public:
    cylinderType();
    cylinderType(double &, double &, double &, double &);
    
    void setH(double);
    void setR(double);
    void setXY(double, double);
    void setCircle(double, double, double);
    void setCylinder(double, double, double, double);
    
    double const & getX() const;
    double const & getY() const;
    double const & getR() const;
    double const & getH() const;
    
    double calV();
    double calS();
    
    void pV();
    void pS();
};

#endif /* cylinderType_h */
