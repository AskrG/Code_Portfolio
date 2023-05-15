//
//  Staff.cpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//

#include "Staff.h"
#include <iostream>
using namespace std;

void Staff::pStaff(){
    pEmployee();
    cout << "Title: " << d_title << endl;
    
}
void Staff::iStaff()
{
    iEmployee();
    cout << "The title is: ";
    string temp = "\n";
    getline(cin, temp);
    getline(cin, d_title);
}






Staff::Staff(){};
Staff::Staff(const Staff & stf){
    d_birth = stf.d_birth;
    d_name = stf.d_name;
    d_number = stf.d_number;
    d_email = stf.d_email;
    d_salary = stf.d_salary;
    d_hired = stf.d_hired;
    d_title = stf.d_title;
}
Staff & Staff::operator = (const Staff & stf){
    d_birth = stf.d_birth;
    d_name = stf.d_name;
    d_number = stf.d_number;
    d_email = stf.d_email;
    d_salary = stf.d_salary;
    d_hired = stf.d_hired;
    d_title = stf.d_title;
    return *this;
}
Staff::~Staff(){};
