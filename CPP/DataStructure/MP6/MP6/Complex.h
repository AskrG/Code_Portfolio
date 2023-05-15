//
//  Complex.hpp
//  MP6
//
//  Created by Fei Gao on 2022/4/29.
//

#ifndef Complex_h
#define Complex_h

#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Complex {
    friend ostream& operator<<(ostream& out, const Complex& theComplex);
    friend istream& operator>>(istream& in, Complex& theComplex);
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator*(const Complex& lhs, const Complex& rhs);
    friend Complex operator/(const Complex& lhs, const Complex& rhs);
public:
    Complex(double real = 0.0, double imag = 0.0){
        this->real = real;
        this->imag = imag;
    };
    double getReal(void) const;            // return real part
    double getImaginary(void) const;        // return imaginary part
    void setReal(double re);            // sets the real part
    void setImaginary(double im);        // sets the imaginary part
    void convertStringToComplex(const string& complexString);
private:
    double real;
    double imag;
};


#endif /* Complex_h */
