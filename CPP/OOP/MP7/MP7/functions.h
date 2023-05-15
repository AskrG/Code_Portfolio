//
//  functions.hpp
//  MP2
//
//  Created by Fei Gao on 2022/3/18.
//

#ifndef functions_h
#define functions_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <string>
#include <sstream>

using namespace std;

int gcd(int, int);
void Reduce(int &num, int &denom);

template <typename T>
class Fraction {
private:
    T * d_numerator;
    T * d_denominator;
public:
    //Constructors
    Fraction() {};
    Fraction(T * num, T * denom) {d_numerator = num; d_denominator = denom;}
    
    //Basic functions
    void setNumerator(T * num) {d_numerator = num;}
    void setDenominator(T * denom) {d_denominator = denom;}
    void print() {cout << d_numerator << "/" << d_denominator << endl;}
    void getNumerator() {cout << d_numerator << endl;}
    void getDenominator() {cout << d_denominator << endl;}
    ~Fraction(){};
    //Assignment
    Fraction<T> operator = (const Fraction<T> &rhs) {
        d_numerator = rhs.d_numerator;
        d_denominator = rhs.d_denominator;
        return *this;
    }

    //* * * * * * * * * * * * Version 1 * * * * * * * * * * * *
    void adds(const Fraction<T> & rhs) {
        if constexpr (is_same_v<T, char>) {
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*d + b*c;
            int iD = b*d;
            
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
//            *d_numerator = *pN;
//            *d_denominator = *pD;
            setNumerator(pN);
            setDenominator(pD);
            print();
            
            
        }
        else {
            d_numerator = d_numerator * rhs.d_denominator + d_denominator * rhs.d_numerator;
            d_denominator = d_denominator * rhs.d_denominator;
            print();
        }
    }
    
    //Operators overloading
    Fraction<T> &operator + (const Fraction<T> & rhs) const {
        static Fraction<T> result;
        if constexpr (is_same_v<T, char>) {
            /*
             I use abcd to fit in the following math formula quickly:
             a               c                  ad + bc
             --      +       --         =       -------
             b               d                     bd
             */
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*d + b*c;
            int iD = b*d;
            
            //reduce the numbers
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
            
            result.setNumerator(pN);
            result.setDenominator(pD);
            
            //Noteworthy that here
            result.print();
            
            //Please note that here the result is not the most ideal. I want to return it but it is not helpful. I tried static but it is not working. I don't want to use global variables.
            //I chose to overload the + operator here. I can avoid this by using add.
            return result;
        }
        else {
            result.setNumerator(d_numerator * rhs.d_denominator + d_denominator * rhs.d_numerator);
            result.setDenominator(d_denominator * rhs.d_denominator);
            result.print();
        }
        return result;
    }
    
    void subtracts(const Fraction<T> & rhs) {
        if constexpr (is_same_v<T, char>) {
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*d - b*c;
            int iD = b*d;
            
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
//            *d_numerator = *pN;
//            *d_denominator = *pD;
            setNumerator(pN);
            setDenominator(pD);
            print();
            
            
        }
        else {
            d_numerator = d_numerator * rhs.d_denominator - d_denominator * rhs.d_numerator;
            d_denominator = d_denominator * rhs.d_denominator;
            print();
        }
    }

    Fraction<T> &operator - (const Fraction<T> & rhs) const {
        static Fraction<T> result;
        if constexpr (is_same_v<T, char>) {
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*d - b*c;
            int iD = b*d;
            
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
            
            result.setNumerator(pN);
            result.setDenominator(pD);
            
            result.print();
            
            return result;
        }
        else {
            result.setNumerator(d_numerator * rhs.d_denominator - d_denominator * rhs.d_numerator);
            result.setDenominator(d_denominator * rhs.d_denominator);
            result.print();
        }
        return result;
    }
    
    void times(const Fraction<T> & rhs) {
        if constexpr (is_same_v<T, char>) {
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*c;
            int iD = b*d;
            
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
//            *d_numerator = *pN;
//            *d_denominator = *pD;
            setNumerator(pN);
            setDenominator(pD);
            print();
        }
        else {
            d_numerator = d_numerator * rhs.d_numerator;
            d_denominator = d_denominator * rhs.d_denominator;
            print();
        }
    }
    
    Fraction<T> &operator * (const Fraction<T> & rhs) const {
        static Fraction<T> result;
        if constexpr (is_same_v<T, char>) {
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*c;
            int iD = b*d;
            
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
            
            result.setNumerator(pN);
            result.setDenominator(pD);
            
            result.print();
            
            return result;
        }
        else {
            result.setNumerator(d_numerator * rhs.d_numerator);
            result.setDenominator(d_denominator * rhs.d_denominator);
            result.print();
        }
        return result;
    }
    
    void divides(const Fraction<T> & rhs) {
        if constexpr (is_same_v<T, char>) {
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*d;
            int iD = b*c;
            
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
//            *d_numerator = *pN;
//            *d_denominator = *pD;
            setNumerator(pN);
            setDenominator(pD);
            print();
        }
        else {
            d_numerator = d_numerator * rhs.d_denominator;
            d_denominator = d_denominator * rhs.d_numerator;
            print();
        }
    }
    
    Fraction<T> &operator / (const Fraction<T> & rhs) const {
        static Fraction<T> result;
        if constexpr (is_same_v<T, char>) {
            int a = atoi(d_numerator);
            int b = atoi(d_denominator);
            int c = atoi(rhs.d_numerator);
            int d = atoi(rhs.d_denominator);
            int iN = a*d;
            int iD = b*c;
            
            Reduce(iN, iD);
            
            //transfer to char arrays
            unsigned long lN = to_string(iN).length();
            char cN[lN+1];
            sprintf(cN, "%d", iN);
            
            unsigned long lD = to_string(iD).length();
            char cD[lD+1];
            sprintf(cD, "%d", iD);
            
            char * pN = cN;
            char * pD = cD;
            
            result.setNumerator(pN);
            result.setDenominator(pD);
            
            result.print();
            
            return result;
        }
        else {
            result.setNumerator(d_numerator * rhs.d_denominator);
            result.setDenominator(d_denominator * rhs.d_numerator);
            result.print();
        }
        return result;
    }

};

    
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

void Reduce(int &num, int &denom) {
    int k = gcd(num, denom);
    num /= k;
    denom /= k;
}

#endif /* functions_hpp */
