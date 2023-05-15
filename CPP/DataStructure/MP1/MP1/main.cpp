//
//  main.cpp
//  MP1
//
//  Created by Fei Gao on 2022/4/17.
//

#include <iostream>
#include <fstream>
#include "class.h"

using namespace std;

int main() {
    bool loop = true;
    
//    Test 1
    cout << "* * * * * * Test 1 * * * * * *" << endl;
    cout << "Input q# to quit!" << endl;
    Pattern Test1;
    while (loop == true) {
        Test1.input();
        if (Test1.getfirst() == "q")
            break;
        else {
            Test1.check();
            cout << endl;
        }
    }

    
    //Test 2
    cout << "* * * * * * Test 2 * * * * * *" << endl;
    Base Test2;
    while (loop == true) {
        Test2.input();
//        Test2.show();
        if (Test2.getbefore() == 0 & Test2.getbase() == 0)
            break;
        else {
            Test2.convert();
            Test2.multibaseOutput();
        }
    }
    
    //Test 3
    //We are not required to create a loop for input files.
    cout << "* * * * * * Test 3 * * * * * *" << endl;
    Balance Test3;
    string name;
    cout << "Run 1:" << endl << "Enter the file name: ";
    cin >> name;

    ifstream run1;
    run1.open(name);
    if (!run1)
        cout << "File cannot be found." << endl;
    
    char input;
    bool pair = true;
    while (run1 >> input) {
        Test3.read(input);
        pair = Test3.pair();
        if (pair == false)
            break;
    }
    
    if (pair == false || !Test3.empty()) //stackTop returns true is there is something left
        cout << "The symbols in " << name << " are not balanced." << endl;
    else
        cout << "The symbols in " << name << " are balanced." << endl;
    
    Balance Test4;
    cout << endl << "Run 2:" << endl << "Enter the file name: ";
    cin >> name;
    
    ifstream run2;
    run2.open(name);
    if (!run2)
        cout << "File cannot be found." << endl;
    
    pair = true;
    while (run2 >> input) {
        Test4.read(input);
        pair = Test4.pair();
        if (pair == false)
            break;
    }
    
    if (pair == false || !Test4.empty()) //stackTop returns true is there is something left
        cout << "The symbols in " << name << " are not balanced." << endl;
    else
        cout << "The symbols in " << name << " are balanced." << endl;

    cout << endl;
    return 0;
}
