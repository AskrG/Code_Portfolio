//
//  main.cpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "MyDate.h"
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
using namespace std;

int main() {
    
    vector<Person *> total;
    
    bool quit = false;
    int number;
    
    while (quit == false){
        cout << "New Input" << endl;
        cout << "The type is:(0 for Student, 1 for Faculty, 2 for Staff, 3 for quit) " ;
        cin >> number;
        
        switch (number){
            case 0:{
                Student * pS = new Student();
                pS -> iStudent();
                cout << "Your input was:" << endl << "Student" << endl;
                pS -> pStudent();
                total.push_back(pS);
                break;
            }
            case 1:{
                Faculty * pF = new Faculty();
                pF -> iFaculty();
                cout << "Your input was:" << endl << "Faculty" << endl;
                pF -> pFaculty();
                total.push_back(pF);
                break;
            }
            case 2:{
                Staff * pStf = new Staff();
                pStf -> iStaff();
                cout << "Your input was:" << endl << "Staff" << endl;
                pStf -> pStaff();
                total.push_back(pStf);
                break;
            }
            case 3:{
                quit = true;
                cout << "Successfully quitted." << endl;
                break;
            }
            default:{
                cout << "Invalid input." << endl;
            };
            }
        }
    
    cout << "___________People___________" << endl;
    cout << "____________________________" << endl;
    //https://www.cplusplus.com/reference/vector/vector/begin/
    for (vector<Person *>::iterator it = total.begin(); it != total.end(); ++it)
    {
            Person *tp = *it;
            tp->pPerson();
            delete tp;
            cout << "____________________________" << endl;
    }
    return 0;
}

/*
 Write a menu driven main program which allows the user to enter in information for a Student, Faculty and Staff.  Objects of type Person and Employee are not allowed therefore they must be pure virtual classes.
 
 
 Finally, to demonstrate your knowledge of dynamic binding versus static binding, using either the List, Array or Vector container shown in Chapter 12 (Malik book), create an list/array/vector of pointers to Person which will allow you to dynamically create derived objects and store them. Once you put a handful of items in the list/array/vector, then loop thru it and print out the information for each object by using the Print() function.
 
 
 Similar to Homework 4, create an Inheritance Diagram which shows your class heirarchy and submi

 */
