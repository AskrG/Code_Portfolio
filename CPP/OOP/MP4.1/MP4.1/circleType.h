//
//  circleType.h
//  MP4
//
//  Created by Fei Gao on 2022/3/20.
//
#ifndef circleType_h
#define circleType_h
#include <stdio.h>
#include <iostream>
#include "pointType.h"
using namespace std;

class circleType
{
protected:
    pointType d_center;
    double d_radius;
public:
    circleType();
    circleType(double &, double &, double &);
    
    void setR(double);
    void setCircle(double, double, double);
    
    double const & getR() const;
    
    double calC();
    double calA();
    
    void pR();
    void pC();
    void pA();

};

#endif /* circleType.h */
