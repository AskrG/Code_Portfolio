//
//  main.cpp
//  MP3 -> MP8
//
//  Created by Fei Gao on 2022/3/19.
//

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <list>
#include "functions.h"
using namespace std;

//Print function
template<typename T>
void show(T obj)
{
    typename T::iterator it;
    for (it = obj.begin(); it != obj.end(); ++it)
        cout << *it;
    cout << endl;
}

//Sort function for the vector
void vSort(vector<Fraction> & input) {
    unsigned long length = input.size();
    Fraction temp;
    int iteration, index;
    for (iteration = 1; iteration < length; iteration++) {
        for (index = 0; index < length - iteration; index++)
            if (input[index] > input[index + 1]) {
                temp = input[index];
                input[index] = input[index + 1];
                input[index + 1] = temp;
            }
    }
}

////    Discarded check duplicate function because I decided to use std::unique instead
//void vCheck(vector<Fraction> & input) {
//    unsigned long length = input.size();
//    Fraction temp;
//    int iteration, index;
//    for (iteration = 1; iteration < length; iteration++) {
//        for (index = 0; index < length; index++)
//            if (input[index] == input[index + 1]) {
//                input.erase(input.begin() + index);
//                index--;
//                length--;
//            }
//    }
//}

//Templated merge function
template<typename Ta, typename Tb>
vector<Fraction> Merge(Ta inputA, Tb inputB) {
    vector<Fraction> result;
    typename Ta::iterator itA;
    for (itA = inputA.begin(); itA != inputA.end(); ++itA)
        result.push_back(*itA);
    typename Tb::iterator itB;
    for (itB = inputB.begin(); itB != inputB.end(); ++itB)
        result.push_back(*itB);
    vSort(result);
    return result;
}

int main()
{
    //Read data 1
    vector<Fraction> fVector;
    ifstream inFileVector;
    inFileVector.open("FractsToVector.txt");
    Fraction inVector;
    while (inFileVector >> inVector) {
        inVector.Reduce();
        fVector.push_back(inVector);
    }
    //Sort the vector
    vSort(fVector);
    
    //Read data 2
    list<Fraction> fList;
    ifstream inFileList;
    inFileList.open("FractsToList.txt");
    Fraction inList;
    while (inFileList >> inList) {
        inList.Reduce();
        fList.push_back(inList);
    }
    
    //Sort the list
    fList.sort();
    
    //Merge the function and erase the duplicates
    vector<Fraction> merged = Merge(fList, fVector);
    merged.erase(unique(merged.begin(), merged.end()), merged.end());
    
    //Print section
    cout << "Vector (sorted)" << endl;
    show(fVector);
    cout << "List (sorted)" << endl;
    show(fList);
    cout << "Vector (merged, sorted, unique)" << endl;
    show(merged);
    
    return 0;
}

    
    
////    ______________________MP3______________________
//    bool quit = false;
//    Fraction a, b;
//    Fraction c{0, 1};
//    while (quit == false)
//    {
//        cout << "First:" << endl;
//        cin >> a;
//        cout << "Second:" << endl;
//        cin >> b;
//
//        bool q = true;
//        bool printA, printB, printD;
//        printA = true;
//        printB = true;
//        printD = false;
//        bool d;
//        while (q == true)
//        {
//            q = false;
//            cout << "Operator:(——: negative a. ++b: a =++b. q or Q: quit. )" << endl;
//
//            string o;
//            cin >> o;
//
//            printA = true;
//            printB = true;
//            printD = false;
//
//            if (o == "+=")
//                a += b;
//            else if (o == "-=")
//                a -= b;
//            else if (o == "*=")
//                a *= b;
//            else if (o == "/=")
//                a /= b;
//            else if (o == "+")
//            {
//                c = a + b;
//                printA = false;
//                printB = false;
//            }
//            else if (o == "-")
//            {
//                c = a - b;
//                printA = false;
//                printB = false;
//            }
//            else if (o == "/")
//            {
//                c = a / b;
//                printA = false;
//                printB = false;
//            }
//            else if (o == "*")
//            {
//                c = a * b;
//                printA = false;
//                printB = false;
//            }
//            else if (o == "=")
//            {
//                a = b;
//            }
//            else if (o == "——")
//            {
//                c = -a;
//                printB = false;
//            }
//            else if (o == "~")
//            {
//                c = ~a;
//                printB = false;
//            }
//            else if (o == "b++")
//            {
//                a = b++;
//            }
//            else if (o == "++b")
//            {
//                a = ++b;
//            }
//            else if (o == "b--")
//            {
//                a = b--;
//            }
//            else if (o == "--b")
//            {
//                a = --b;
//            }
//            else if (o == "<")
//            {
//                d = (a < b);
//                printD = true;
//            }
//            else if (o == ">")
//            {
//                d = (a > b);
//                printD = true;
//            }
//            else if (o == "<=")
//            {
//                d = (a <= b);
//                printD = true;
//            }
//            else if (o == ">=")
//            {
//                d = (a >= b);
//                printD = true;
//            }
//            else if (o == "==")
//            {
//                d = (a == b);
//                printD = true;
//            }
//            else if (o == "!=")
//            {
//                d = (a != b);
//                printD = true;
//            }
//            else if (o == "!")
//            {
//                d = (!a);
//                printD = true;
//            }
//            else if (o == "q" || o == "Q")
//            {
//                quit = true;
//                printA = false;
//                printB = false;
//                cout << "Program quitted.";
//                break;
//            }
//            else
//            {
//                cout << "Invalid input. Try again.";
//                q = true;
//            }
//        }
//
//        if (printD == true)
//        {
//            if (d == 1)
//                cout << "True" << endl;
//            else
//                cout << "False" << endl;;
//        }
//        else
//        {
//            if (printA == true)
//                cout << "a=" << a.Reduce();
//            if (printB == true)
//                cout << "b=" << b.Reduce();
//            if (!!c)
//            {
//                cout << "The result is " << c.Reduce();
//                c.setNumerator(0);
//            }
//        }
//    }
//
                
//
//
            

////    ______________________MP3 Test______________________
//    Fraction a, b, c, d, e, f, g;
//    cout << "a+=b";
//    a+=b;
//    a.print();
//
//    cout << endl << "a-=b";
//    a-=b;
//    a.print();
//
//    cout << endl << "a*=b";
//    a*=b;
//    a.print();
//
//    cout << endl << "a/=b";
//    a/=b;
//    a.print();
    
    

//
//    cin >> a;
//    cout << a;
    
//    cout << "a++" << endl;
//    d = a++;
//    d.print();
//    a.print();
//
//    cout << "++a" << endl;
//    e = ++a;
//    e.print();
//    a.print();
//
//    cout << "a--" << endl;
//    f = a--;
//    f.print();
//    a.print();
//
//    cout << "--a" << endl;
//    g = --a;
//    g.print();
//    a.print();
    
    
    
//    c = -a;
//    c.print();
//
//    d = ~a;
//    d.print();
    
    
    
//    cin >> a;
//    cout << a;
    
    
//    cin >> a;
//    cout << a;
//    cin >> b;
//    cout << b;
//    if (a!=b)
//        cout << "a!=b";
//    int x = !a;
//    cout << x;
    
    
    
    
//    cin >> b;
//    cout << b;
//    cin >> c;
//    cout << c;
//
//    a = b+c;
//    a.print();
//    cout << endl;
//    a = b*c;
//    a.print();
//    cout << endl;
//    a = b-c;
//    a.print();
//    cout << endl;
//    a = b/c;
//    a.print();
//    cout << endl;
//    a += b;
//    a.print();
//    cout << endl;
//    a *= b;
//    a.print();
//    cout << endl;
//    a -= b;
//    a.print();
//    cout << endl;
//    a /= b;
//    a.print();
//    cout << endl;
    
//    cin >> b;
//    cout << b;
//    a = ++b;
//    a.print();
//    b.print();
    
//    a = b++;
//    a.print();
//    b.print();
    
//    a = --b;
//    a.print();
//    b.print();
    
//    a = b--;
//    a.print();
//    b.print();
    
    
//    cin >> a;
//    cout << a;
//    
//    b = -a;
//    a.print();
//    b.print();
//    
//    c = ~a;
//    a.print();
//    c.print();
    
//    cin >> a;
//    cout << a;
//    double k = (double)a;、
//    float k = (float)a;
//    cout << k;

