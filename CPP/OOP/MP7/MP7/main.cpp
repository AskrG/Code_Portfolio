//
//  main.cpp
//  MP7
//
//  Created by Fei Gao on 2022/3/19.
//
#include <iostream>
#include <exception>
#include <string>
#include <numeric>
#include <vector>
#include "functions.h"

using namespace std;

int main() {
    char arr1[] = "1";
    char arr2[] = "5";
    char arr3[] = "15";
    char arr4[] = "18";
    
    char * p1 = arr1;
    char * p2 = arr2;
    char * p3 = arr3;
    char * p4 = arr4;

    Fraction<char> fA(p1, p2); //fA = 1/5
    Fraction<char> fB(p2, p3); //fB = 1/3
    Fraction<char> fC(p3, p4); //fC = 15/18 or 5/6
    Fraction<char> fD(p1, p3); //fD = 1/15
    Fraction<char> fE(p1, p4); //fD = 1/18

    cout << "fA + fB = ";
    fA + fB;

    cout << "fB - fC = ";
    fB - fC;
    
    cout << "fA * fC = ";
    fA * fC;
    
    cout << "fB / fC = ";
    fB / fC;
    
    cout << "fA adds fB to itself. fA = ";
    fA.adds(fB);
    
    cout << "fB subtracts fC from itself. fB = ";
    fB.subtracts(fC);
    
    cout << "fD times fC to itself. fC = ";
    fC.times(fD);
    
    cout << "fD divides fE from itself. fD = ";
    fD.divides(fE);
    
    return 0;
}

