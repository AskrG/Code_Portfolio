//
//  Faculty.cpp
//  MP5
//
//  Created by Fei Gao on 2022/3/22.
//

#include "Faculty.h"
#include <iostream>
using namespace std;

void Faculty::iFaculty(){
    iEmployee();
    cout << "The track is:(1 for Tenure, 0 for Term Contract) ";
    cin >> d_tenure;
    
    cout << "The office is:(numbers only) ";
    cin >> d_office;
    
    string temp = "\n";
    getline(cin, temp);
        
    bool another = true;

    while (another == true)
    {
        cout << "Enter office hour line by line:(q for quit) " << endl;
        getline(cin, temp);
        if (temp == "q")
            another = false;
        else
            d_hours.push_back(temp);
    }
}
void Faculty::pFaculty(){
    pEmployee();
    
    cout << "Office room number: " << d_office << endl << "Hired track is: ";
    if (d_tenure == 1)
        cout << "Tenure-track" << endl;
    else
        cout << "Term contract" << endl;
    
    cout << "The office hours are: ";
    unsigned long k = d_hours.size();
    for (int i = 0; i < k; i++)
    {
        cout << d_hours[i];
        if (i < (k-1))
            cout << " | ";
    }
    cout << endl;
}













Faculty::Faculty(){};
Faculty::Faculty(const Faculty & f){
    d_birth = f.d_birth;
    d_name = f.d_name;
    d_number = f.d_number;
    d_email = f.d_email;
    d_salary = f.d_salary;
    d_hired = f.d_hired;
    d_office = f.d_office;
    d_tenure = f.d_tenure;
    d_hours = f.d_hours;
}
Faculty & Faculty::operator = (const Faculty &f){
    d_birth = f.d_birth;
    d_name = f.d_name;
    d_number = f.d_number;
    d_email = f.d_email;
    d_salary = f.d_salary;
    d_hired = f.d_hired;
    d_office = f.d_office;
    d_tenure = f.d_tenure;
    d_hours = f.d_hours;
    return *this;
}
Faculty::~Faculty(){};

