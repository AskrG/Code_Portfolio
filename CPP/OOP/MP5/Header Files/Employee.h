//
//  Employee.hpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#ifndef Employee_h
#define Employee_h
#include <stdio.h>
#include "MyDate.h"
#include "Person.h"

class Employee : virtual public Person{
protected:
    long d_salary;
    MyDate d_hired;
public:
    Employee();
    Employee(const Employee &);
    Employee &operator = (const Employee &);
    virtual ~Employee(){};
    void iEmployee();
    void pEmployee();
};


#endif /* Employee_h */
