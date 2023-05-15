//
//  Employee.cpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//

#include "Employee.h"
#include <iostream>
using namespace std;



void Employee::iEmployee(){
    iPerson();
    cout << "The salary is: ";
    cin >> d_salary;
    cout << "The hired date is:";
    d_hired.iDate();
}
void Employee::pEmployee(){
    pPerson();
    cout << "Salary: " << d_salary << endl << "Hired date: ";
    d_hired.pDate();
}









Employee::Employee(){};
Employee::Employee(const Employee &e){
    d_birth = e.d_birth;
    d_name = e.d_name;
    d_number = e.d_number;
    d_email = e.d_email;
    d_salary = e.d_salary;
    d_hired = e.d_hired;
}
Employee & Employee::operator = (const Employee &e){
    d_birth = e.d_birth;
    d_name = e.d_name;
    d_number = e.d_number;
    d_email = e.d_email;
    d_salary = e.d_salary;
    d_hired = e.d_hired;
    return *this;
}
