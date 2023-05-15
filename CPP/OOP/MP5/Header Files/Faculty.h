//
//  Faculty.hpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#ifndef Faculty_h
#define Faculty_h
#include <stdio.h>
#include <vector>
#include "MyDate.h"
#include "Employee.h"

using namespace std;

class Faculty : public virtual Employee{
    int d_office;
    bool d_tenure;
    vector<string> d_hours;
public:
    Faculty();
    Faculty(const Faculty &);
    Faculty &operator = (const Faculty &);
    ~Faculty();
    void iFaculty();
    void pFaculty();
};
#endif /* Faculty_h */
