//
//  main.cpp
//  MP2
//
//  Created by Fei Gao on 2022/3/12.
//

#include <iostream>
#include <exception>
#include <string>
#include "functions.h"
using namespace std;

int main()
{
    bool quit = false;
    Fraction a;
    Fraction b;
    Fraction c;
    int i;
    while (quit == false)
    {
        cout << "First Fraction:" << endl;
        a.input();
        cout << "Second Fraction:" << endl;
        b.input();
        
        bool q = true;
        while (q == true) {
            q = false;
            cout << "operator" << endl;
            i = mathoperator();
            if (i == 0)
                c = a.add(b);
            else if (i == 1)
                c = a.subtract(b);
            else if (i == 2)
                c = a.multiply(b);
            else if (i == 3)
                c = a.divide(b);
            else if (i == 4) {
                cout << "Program quitted." << endl;
                quit = true;
            }
            else if (i == 5) {
                cout << "Reinput your math operator: +, -, *, /. Input q or Q to quit." << endl;
                q = true;
            }
        }
            
        if (quit == true)
            break;
        else {
            cout << "Calculation: ";
            c.print();
            cout << "Next!" << endl;
        }
    }
    
    
    //-----------------------------block 0: basic tests
    
//    cout << "Test1" << endl;
//    Fraction frac;
//    frac.input();
//    frac.print();
//
//    cout << "Test2" << endl;
//    frac.setNumerator(5);
//    frac.setDenominator(4);
//    frac.print();
//
//    cout << "Test3" << endl;
//    frac.setNumerator(5);
//    frac.setDenominator(0);
//    frac.print();
    
//    cout << "Test4" << endl;
//    Fraction wholeNumber(3);
//    wholeNumber.print();
//
//    cout << "Test5" << endl;
//    Fraction aDoubleNumber(6.2830);
//    aDoubleNumber.print();
//
//    cout << "Test6" << endl;
//    Fraction withZero(3, 0);
//    withZero.print();
//
//    cout << "Test extra: 3/1 + 3/9 " << endl;
//    Fraction inputNew;
//    inputNew.print(); //random number initialized for this local object because we were asked to use the default empty constructor.
    
    //----------------------------- block 1.0: mainbody
//    cout << "Test7.1" << endl;
//    Fraction twoInputs(3, 9);
//    twoInputs.print();
//
//    cout << "Test7.2" << endl;
//    Fraction newInputs(3, 1);
//    newInputs.print();
    
    //*******Please only uncomment one of the four versions of block 1 to avoid redefinition.*******
    //----------------------------- block 1.1: algo_add
//    cout << "Test 8.1: 3/1 + 3/9 " << endl;
//    Fraction k;
//    k = newInputs.add(twoInputs);
//    k.print();

    
    //----------------------------- block 1.2: algo_subtract
//    cout << "Test 8.2: 3/1 - 3/9 " << endl;
//    Fraction k;
//    k = newInputs.subtract(twoInputs);
//    k.print();

    
    //----------------------------- block 1.3: algo_multiply
//    cout << "Test 8.3: 3/1 * 3/9 " << endl;
//    Fraction k;
//    k = newInputs.multiply(twoInputs);
//    k.print();

    
    //----------------------------- block 1.4: algo_divide
//    cout << "Test 8.4: 3/1 / 3/9 " << endl;
//    Fraction k;
//    k = newInputs.divide(twoInputs);
//    k.print();
//
//    ----------------------------- block 2.0: mainbody
//    Fraction a1;
//    a1.setNumerator(5);
//    a1.setDenominator(4);
//
//    Fraction b1;
//    b1.setNumerator(7);
//    b1.setDenominator(3);
//
//    Fraction c1;
//    c1.setNumerator(1);
//    c1.setDenominator(2);
//
//    ----------------------------- block 2.1: similarly only uncomment one of them
//    a1.add(b1, c1);
//    a1.print();
//
//    a1.subtract(b1, c1);
//    a1.print();
//
//    a1.multiply(b1, c1);
//    a1.print();
//
//    a1.divide(b1, c1);
//    a1.print();
    return 0;
}


/*



  
 In the main program, create a looping menu driven interface, which allows the user to enter in two Fractions using the Input() function and a mathematical operation. After the operation, print the Fraction result using the Print() function. The loop ends when the user enters Q or q to quit for the math operation.
  
 Please upload the following:
 The main program including .h and .cpp, please don't upload .sln, or .project or .exe
 Any input or output data files that you create
 Screen shots of an entire output with the result.

 
 */
