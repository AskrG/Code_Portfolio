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
#include <algorithm>

using namespace std;

int check(int denom) {
    if (denom == 0)
        throw Excptn("Failed. Denominator cannot be zero.");
    else
        return denom;
}

int gcd(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    
    if (a == 0)
       return b;
    else if (b == 0)
       return a;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a-b, b);
    else
        return gcd(a, b-a);
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
    setNumerator(inNum);
    setDenominator(inDenom);
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

ostream& operator<<(ostream& os, const Fraction& rhs)
{
    try {
        if (check(rhs.d_denominator)) {
            os << rhs.d_numerator << "/" << rhs.d_denominator << endl;
        }
    }
    
    catch(Excptn &exception) {
        os << exception.errormsg() << endl;
    }
    
    return os;
}

istream& operator>>(istream& is, Fraction& rhs)
{
    is >> rhs.d_numerator;
    is >> rhs.d_denominator;
    return is;
}

Fraction Fraction::operator += (const Fraction & rhs)
{
    d_numerator = d_numerator * rhs.d_denominator + d_denominator * rhs.d_numerator;
    d_denominator = d_denominator * rhs.d_denominator;
    return *this;
}

Fraction Fraction::operator -= (const Fraction & rhs)
{
    d_numerator = d_numerator * rhs.d_denominator - d_denominator * rhs.d_numerator;
    d_denominator = d_denominator * rhs.d_denominator;
    return *this;
}

Fraction Fraction::operator *= (const Fraction & rhs)
{
    d_numerator = d_numerator * rhs.d_numerator;
    d_denominator = d_denominator * rhs.d_denominator;
    return *this;
}

Fraction Fraction::operator /= (const Fraction & rhs)
{
    d_numerator = d_numerator * rhs.d_denominator;
    d_denominator = d_denominator * rhs.d_numerator;
    return *this;
}

Fraction Fraction::operator + (const Fraction & rhs) const
{
    return Fraction(d_numerator * rhs.d_denominator + d_denominator * rhs.d_numerator, d_denominator * rhs.d_denominator);
}

Fraction Fraction::operator - (const Fraction & rhs) const
{
    return Fraction(d_numerator * rhs.d_denominator - d_denominator * rhs.d_numerator, d_denominator * rhs.d_denominator);
}

Fraction Fraction::operator * (const Fraction & rhs) const
{
    return Fraction(d_numerator * rhs.d_numerator, d_denominator * rhs.d_denominator);
}

Fraction Fraction::operator / (const Fraction & rhs) const
{
    return Fraction(d_numerator * rhs.d_denominator, d_denominator * rhs.d_numerator);
}

Fraction & Fraction::operator = (const Fraction & rhs)
{
    if (this != &rhs )
    {
        d_numerator = rhs.numerator();
        d_denominator = rhs.denominator();
    }
    return *this;
}

Fraction Fraction::operator - ()
{
    return Fraction(-d_numerator, d_denominator);
}
Fraction Fraction::operator ~ ()
{
    return Fraction(d_denominator, d_numerator);
}

Fraction Fraction::operator++()
{
    d_numerator = d_numerator + d_denominator;
    return *this;
}

Fraction Fraction::operator++(int i)
{
    Fraction temp = *this;
    d_numerator = d_numerator + d_denominator;
    return temp;
}

Fraction Fraction::operator--()
{
    d_numerator = d_numerator - d_denominator;
    return *this;
}

Fraction Fraction::operator--(int i)
{
    Fraction temp = *this;
    d_numerator = d_numerator - d_denominator;
    return temp;
}


bool Fraction::operator < (const Fraction & rhs) const
{
    return (d_numerator * rhs.d_denominator < d_denominator * rhs.d_numerator);
}

bool Fraction::operator > (const Fraction & rhs) const
{
    return (d_numerator * rhs.d_denominator > d_denominator * rhs.d_numerator);
}

bool Fraction::operator <= (const Fraction & rhs) const
{
    return (d_numerator * rhs.d_denominator <= d_denominator * rhs.d_numerator);
}

bool Fraction::operator >= (const Fraction & rhs) const
{
    return (d_numerator * rhs.d_denominator >= d_denominator * rhs.d_numerator);
}

bool Fraction::operator == (const Fraction & rhs) const
{
    return (d_numerator == rhs.d_numerator && d_denominator == rhs.d_denominator);
}

bool Fraction::operator != (const Fraction & rhs) const
{
    return (d_numerator != rhs.d_numerator || d_denominator != rhs.d_denominator);
}

bool Fraction::operator ! () const
{
    return !d_numerator; //"!d_denominator" is meaningleass since we will check zero_denominator before using the print function.
}

Fraction::operator double()
{

    return ((static_cast<double>(d_numerator)) / d_denominator);
}
Fraction::operator float()
{
    return ((static_cast<float>(d_numerator)) / d_denominator);
}

Fraction Fraction::Reduce()
{
    if (d_denominator == 0)
    {
        return *this;
    }
    else if (d_numerator == 0)
        return *this;
    else
    {
        int k = gcd(d_numerator, d_denominator);
        d_numerator /= k;
        d_denominator /= k;
        return *this;
    }
}

