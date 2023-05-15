//
//  main.cpp
//  MP6
//
//  Created by Fei Gao on 2022/4/29.
//

#include <iostream>
#include "Complex.h"

int main()
{
    Complex a, b;

    cout << "No spaces between the real and imaginary number in each string." << endl << "Make sure you read the entry at once as a string." << endl;
    cout << "Input the first complex number: ";
    cin >> a;
    cout << "Input the second complex number: ";
    cin >> b;
    cout << a << " + " << b << " = " << a+b << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << a << " / " << b << " = " << a/b << endl;
    return 0;
}
