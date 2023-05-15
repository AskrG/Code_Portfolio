//
//  functions.hpp
//  MP2
//
//  Created by Fei Gao on 2022/3/18.
//

#ifndef functions_h
#define functions_h
#include <stdio.h>
#include <iostream>
#include <exception>
#include <string>
using namespace std;

int check(int denom);
int mathoperator();

class Fraction {
    int d_numerator;
    int d_denominator;
    
public:
    Fraction();
    Fraction(int whole);
    Fraction(double withDot);
    Fraction(int num, int denom);
    
    void setNumerator(int num);
    void setDenominator(int denom);
    void input();

    void print();
    
    Fraction add(Fraction adder);
    Fraction subtract(Fraction subtracter);
    Fraction multiply(Fraction multiplier);
    Fraction divide(Fraction divider);

    void add(Fraction adder1, Fraction adder2);
    void subtract(Fraction subtracter1, Fraction subtracter2);
    void multiply(Fraction multiplier1, Fraction multiplier2);
    void divide(Fraction divider1, Fraction divider2);
};

class Excptn: public exception {
    const char * msg;
    Excptn();
public:
    Excptn(const char * s) throw() : msg(s) {}
    const char * errormsg() const throw() {return msg;}
};

#endif /* functions_hpp */
