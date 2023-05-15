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
#include <algorithm>
using namespace std;

int check(int denom);
int gcd(int a, int b);

class Fraction {
    //extraction/insertion
    friend ostream& operator<<(ostream& os, const Fraction& rhs);
    friend istream& operator>>(istream& is, Fraction& rhs);

private:
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
    
    inline int numerator() const { return d_numerator; };
    inline int denominator() const { return d_denominator; };
    
    //binary functions
    Fraction operator += (const Fraction &);
    Fraction operator -= (const Fraction &);
    Fraction operator *= (const Fraction &);
    Fraction operator /= (const Fraction &);
    Fraction operator + (const Fraction &) const;
    Fraction operator - (const Fraction &) const;
    Fraction operator * (const Fraction &) const;
    Fraction operator / (const Fraction &) const;
    Fraction & operator = (const Fraction &);
    
    //unary functions
    
    Fraction operator - ();
    Fraction operator ~ ();
    
    Fraction operator ++ (); //pre
    Fraction operator ++ (int); //post

    Fraction operator -- (); //pre
    Fraction operator -- (int); //post
    
    //boolean
    bool operator < (const Fraction & ) const;
    bool operator > (const Fraction & ) const;
    bool operator <= (const Fraction & ) const;
    bool operator >= (const Fraction & ) const;
    bool operator == (const Fraction & ) const;
    bool operator != (const Fraction & ) const;
    bool operator ! () const;

    //casting functions
    operator double();
    operator float();
    
    //Reduce
    Fraction Reduce();

};

class Excptn: public exception {
    const char * msg;
    Excptn();
public:
    Excptn(const char * s) throw() : msg(s) {}
    const char * errormsg() const throw() {return msg;}
};

#endif /* functions_hpp */
