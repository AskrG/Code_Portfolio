//
//  MyDate.hpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#ifndef MyDate_h
#define MyDate_h
#include <stdio.h>

class MyDate{
protected:
    int d_year;
    int d_month;
    int d_day;
public:
    MyDate();
    MyDate(const MyDate &);
    MyDate &operator = (const MyDate &);
    virtual ~MyDate(){};
    void pDate();
    void iDate();
};

#endif /* MyDate_h */
