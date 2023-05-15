//
//  functions.cpp
//  MP2
//
//  Created by Fei Gao on 2022/3/18.
//

#include "functions.h"
#include <iostream>
#include <exception>
#include <string>
using namespace std;

int check(int denom) {
    if (denom == 0)
        throw Excptn("Failed. Denominator cannot be zero.");
    else
        return denom;
}

Fraction::Fraction() {
}

Fraction::Fraction(int whole) {
    d_numerator = whole;
    d_denominator = 1;
}

Fraction::Fraction(double withDot) {
    d_numerator = withDot * 100000;
    setDenominator(100000);
}

Fraction::Fraction(int num, int denom) {
    d_numerator = num;
    setDenominator(denom);
}

void Fraction::setNumerator(int num) {
    d_numerator = num;

}
void Fraction::setDenominator(int denom) {
    d_denominator = denom;
}

void Fraction::input() {
    int inNum, inDenom;
    cout << "Input the numerator: ";
    cin >> inNum;
    cout << "Input the denominator: ";
    cin >> inDenom;
    
//    bool isZero = true;
//    while (isZero == true) {
//        cout << "Input the denominator: ";
//        cin >> inDenom;
//        if (inDenom == 0) {
//            isZero = true;
//            cout << "Invalid denominator, please try again." << endl;
//        }
//        else
//            isZero = false;
//    }

    setNumerator(inNum);
    setDenominator(inDenom);
}

int mathoperator() {
    string matho;
    cin >> matho;
    if (matho == "+")
        return 0;
    else if (matho == "-")
        return 1;
    else if (matho == "*")
        return 2;
    else if (matho == "/")
        return 3;
    else if (matho == "q" || matho == "Q")
        return 4;
    else
        return 5;
    
}

void Fraction::print() {
    try {
        if (check(d_denominator)) {
            cout << d_numerator << "/" << d_denominator << endl;
        }
    }
    
    catch(Excptn &exception) {
        cout << exception.errormsg() << endl;
    }
}

Fraction Fraction::add(Fraction adder) {
    Fraction result;
    result.d_numerator = d_numerator * adder.d_denominator + d_denominator * adder.d_numerator;
    result.d_denominator = d_denominator * adder.d_denominator;
    return result;
}

Fraction Fraction::subtract(Fraction subtracter) {
    Fraction result;
    result.d_numerator = d_numerator * subtracter.d_denominator - d_denominator * subtracter.d_numerator;
    result.d_denominator = d_denominator * subtracter.d_denominator;
    return result;
}

Fraction Fraction::multiply(Fraction multiplier) {
    Fraction result;
    result.d_numerator = d_numerator * multiplier.d_numerator;
    result.d_denominator = d_denominator * multiplier.d_denominator;
    return result;
}

Fraction Fraction::divide(Fraction divider) {
    Fraction result;
    result.d_numerator = d_numerator * divider.d_denominator;
    result.d_denominator = d_denominator * divider.d_numerator;
    return result;
}

void Fraction::add(Fraction adder1, Fraction adder2) {
    Fraction temp;
    temp = adder1.add(adder2);
    d_numerator = d_numerator * temp.d_denominator + d_denominator * temp.d_numerator;
    d_denominator = d_denominator * temp.d_denominator;
}

void Fraction::subtract(Fraction subtracter1, Fraction subtracter2) {
    Fraction temp;
    temp = subtracter1.add(subtracter2); //a-b-c = a-(b+c)
    d_numerator = d_numerator * temp.d_denominator - d_denominator * temp.d_numerator;
    d_denominator = d_denominator * temp.d_denominator;
}

void Fraction::multiply(Fraction multiplier1, Fraction multiplier2) {
    Fraction temp;
    temp = multiplier1.multiply(multiplier2);
    d_numerator = d_numerator * temp.d_numerator;
    d_denominator = d_denominator * temp.d_denominator;
}

void Fraction::divide(Fraction divider1, Fraction divider2) {
    Fraction temp;
    temp = divider1.multiply(divider2); // a/b/c = a/(b*c)
    d_numerator = d_numerator * temp.d_denominator;
    d_denominator = d_denominator * temp.d_numerator;
}
