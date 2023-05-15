//
//  MyDate.cpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//

#include "MyDate.h"
#include <iostream>
using namespace std;
void MyDate::pDate(){
    cout << d_year << "." << d_month << "." << d_day << "." << endl;
}

void MyDate::iDate(){
    cout << "(yyyy mm dd) ";
    cin >> d_year >> d_month >> d_day;
}

MyDate::MyDate(){};
MyDate::MyDate(const MyDate &d){
    d_year = d.d_year;
    d_month = d.d_month;
    d_day = d.d_day;
}
MyDate &MyDate::operator = (const MyDate &d){
    d_year = d.d_year;
    d_month = d.d_month;
    d_day = d.d_day;
    return *this;
}
