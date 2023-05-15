//
//  Student.cpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//

#include "Student.h"
#include <iostream>
using namespace std;

void Student::iStudent(){
    iPerson();
    cout << "The GPA is: ";
    cin >> d_gpa;
    
    bool valid = false;
    int number;
    while (valid == false){
        cout << "The grade status is:(0 for Freshman, 1 for Sophomore, 2 for Junior, 3 for Senior) ";
        cin >> number;
        
        switch (number){
            case 0:{
                d_grade = Freshman;
                valid = true;
                break;
            }
            case 1:{
                d_grade = Sophomore;
                valid = true;
                break;
            }
            case 2:{
                d_grade = Junior;
                valid = true;
                break;
            }
            case 3:{
                d_grade = Senior;
                valid = true;
                break;
            }
            default:{
                valid = false;
            }
        }
    }
}

void Student::pStudent(){
    pPerson();
    cout << "GPA: " << d_gpa << endl << "Grade: ";
    
    switch (d_grade){
        case 0:{
            cout << "Freshman" << endl;
            break;
        }
        case 1:{
            cout << "Sophomore" << endl;
            break;
        }
        case 2:{
            cout << "Junior" << endl;
            break;
        }
        default:{
            cout << "Senior" << endl;
        }
    }
}




Student::Student(){};
Student::Student(const Student &s){
    d_birth = s.d_birth;
    d_name = s.d_name;
    d_number = s.d_number;
    d_email = s.d_email;
    d_grade = s.d_grade;
    d_gpa = s.d_gpa;
}
Student & Student::operator = (const Student &s){
    d_birth = s.d_birth;
    d_name = s.d_name;
    d_number = s.d_number;
    d_email = s.d_email;
    d_grade = s.d_grade;
    d_gpa = s.d_gpa;
    return *this;
}
Student::~Student(){};

