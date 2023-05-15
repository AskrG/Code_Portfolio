//
//  error.h
//  MP6
//
//  Created by Fei Gao on 2022/3/27.
//

#ifndef error_h
#define error_h
#include <iostream>
#include <stdio.h>
using namespace std;

class Excptn: public exception {
    const char * msg;
    Excptn();
public:
    Excptn(const char * s) throw() : msg(s) {}
    const char * errormsg() const throw() {return msg;}
};

#endif /* error_h */
