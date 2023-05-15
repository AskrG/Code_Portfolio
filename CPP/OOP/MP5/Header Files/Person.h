//
//  Person.hpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#ifndef Person_h
#define Person_h
#include <stdio.h>
#include <string>
#include "MyDate.h"

using namespace std;

class Person{
protected:
    MyDate d_birth;
    string d_name;
    string d_number;
    string d_email;
public:
    Person();
    Person(const Person &);
    Person &operator = (const Person &);
    virtual ~Person(){};
    void iPerson();
    void pPerson();
};


#endif /* Person_h */
