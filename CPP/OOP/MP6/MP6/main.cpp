//
//  main.cpp
//  MP6
//
//  Created by Fei Gao on 2022/3/26.
//

#include <iostream>
#include <fstream>
#include "myArray.h"
using namespace std;

int main() {

    myArray list(5);           //Line 1
    myArray myList(2, 13);     //Line 2
    myArray yourList(-5, 9);   //Line 3
    cout << "* * * * * * * * * * * * *     MP 6     * * * * * * * * * * * * *" << endl;
    cout << "I have included the print function in the operator[] overloading." << endl;
    cout << "This is a test program, so I didn't add the user input interface." << endl;
    cout << "* * * * * * * * * * * * *  Test Set 1  * * * * * * * * * * * * *" << endl;
    list[0];
    list[1];
    list[4];
    cout << "* * * * * * * * * * * * *  Test Set 2  * * * * * * * * * * * * *" << endl;
    myList[2];
    myList[3];
    myList[12];
    cout << "* * * * * * * * * * * * *  Test Set 3  * * * * * * * * * * * * *" << endl;
    yourList[-5];
    yourList[0];
    yourList[8];
    cout << "* * * * * * * * * * * * *  Test Set 4  * * * * * * * * * * * * *" << endl;
    yourList[10];
    cout << "* * * * * * * * * * * * *     End      * * * * * * * * * * * * *" << endl;

    return 0;
}
