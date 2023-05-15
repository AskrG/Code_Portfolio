//
//  Staff.hpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#ifndef Staff_h
#define Staff_h
#include <stdio.h>
#include <string>
#include "Employee.h"
using namespace std;

class Staff : public virtual Employee{
    string d_title;
public:
    Staff();
    Staff(const Staff &);
    Staff &operator = (const Staff &);
    ~Staff();
    
    void pStaff();
    void iStaff();
};

#endif /* Staff_h */
