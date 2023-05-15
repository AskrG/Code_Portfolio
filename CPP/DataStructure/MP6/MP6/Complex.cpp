//
//  Complex.cpp
//  MP6
//
//  Created by Fei Gao on 2022/4/29.
//


#include "Complex.h"

void Complex::convertStringToComplex(const string& input)
{
    string strreal, strimag;
    size_t foundPlus = input.find("+");
    size_t foundi = input.find("i");
    
    if (foundPlus == string::npos || foundi == string::npos)
    {
        cout << "Invalid Input.";
        return;
    }
    
    strreal = input.substr(0, foundPlus);
    strimag = input.substr(foundPlus+1, foundi-foundPlus-1);

    this->real = stod(strreal.c_str());
    this->imag = stod(strimag.c_str());
}


double Complex::getReal() const
{
    return real;
}

double Complex::getImaginary() const
{
    return imag;
    
}

void Complex::setReal(double real)
{
    this->real = real;
}

void Complex::setImaginary(double imag)
{
    this->imag = imag;
}

//Operator overloading
ostream& operator<<(ostream& os, const Complex& num)
{
    os << "(" << num.real << " + " << num.imag << " i)";
    return os;
}

istream& operator>>(istream& is, Complex& num)
{
    string temp;
    is >> temp;
    num.convertStringToComplex(temp);
    return is;
}

Complex operator+(const Complex& l , const Complex& r)
{
    Complex copy;
    copy.real = l.real + r.real;
    copy.imag = l.imag + r.imag;
    return copy;
}

Complex operator-(const Complex& l, const Complex& r)
{
    Complex copy ;
    copy.real = l.real - r.real;
    copy.imag = l.imag - r.imag;
    return copy;
}

Complex operator*(const Complex& l, const Complex& r )
{
    Complex copy;
    copy.real = (l.real * r.real ) - (l.imag * r.imag);
    copy.imag = ( l.real * r.imag ) + (l.imag * r.real);
    return copy;
}

Complex operator/(const Complex& l, const Complex& r)
{
    Complex copy;
    copy.real = ((l.real*r.real ) +(l.imag * r.imag))/ ((pow(r.real,2))+ pow(r.imag,2));
    copy.imag = (( l.imag * r.real)- (l.real*r.imag))/ ((pow(r.real,2) ) + (pow(r.imag,2)) );
    return copy;
}
