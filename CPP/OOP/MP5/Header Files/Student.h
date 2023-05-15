//
//  Student.hpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#ifndef Student_h
#define Student_h
#include <stdio.h>
#include "Person.h"

class Student : public virtual Person{
    enum d_stat {Freshman, Sophomore, Junior, Senior};
    double d_gpa;
    d_stat d_grade;
public:
    Student();
    Student(const Student &);
    Student &operator = (const Student &);
    ~Student();
    void iStudent();
    void pStudent();
};


#endif /* Student_h */
