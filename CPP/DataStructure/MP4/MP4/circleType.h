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
    pointType d_center;
    double d_radius;
public:
    circleType();
    circleType(double &, double &, double &);
    
    void setR(double);
    void setX(double);
    void setY(double);
    void setXY(double, double);
    void setCircle(double, double, double);
    
    double const & getX() const;
    double const & getY() const;
    double const & getR() const;
    
    double calA();
    double calC();
    
    void pR();
    void pXY();
    void pA();
    void pC();
    


};






#endif /* circleType.h */
