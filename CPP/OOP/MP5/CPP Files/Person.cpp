//
//  Person.cpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#include "Person.h"
#include <iostream>
using namespace std;

void Person::pPerson(){
    cout << "Date of birth: ";
    d_birth.pDate();
    cout << "Name: " << d_name << endl << "Number: " << d_number << endl << "Email: " << d_email << endl;
}

void Person::iPerson(){
    cout << "The date of birth is:";
    d_birth.iDate();
    cout << "The name is: ";
    string str = "\n";
    getline(cin, str);
    getline(cin, d_name);
    cout << "The number: ";
    cin >> d_number;
    cout << "The email is: ";
    cin >> d_email;
}





Person::Person(){};
Person::Person(const Person &p){
    d_birth = p.d_birth;
    d_name = p.d_name;
    d_number = p.d_number;
    d_email = p.d_email;
}
Person & Person::operator = (const Person &p){
    d_birth = p.d_birth;
    d_name = p.d_name;
    d_number = p.d_number;
    d_email = p.d_email;
    return *this;
}

