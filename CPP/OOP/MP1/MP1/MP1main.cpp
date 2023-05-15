//
//  main.cpp
//  MP1
//
//  Created by Fei Gao on 2022/3/9.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

double power(double, int);
long hms_to_secs(int, int, int);
void swap(int &a, int &b);

int main()
{
    //Function 1 ______________________________________________________
    double num;
    int pow;
    
    cout << "______________1. Function Power______________" << endl << "Input the number: ";
    cin >> num;
    cout << "Input the power: ";
    cin >> pow;
    
    cout << "The result is: " << power(num, pow);
    
    //Function 2 ______________________________________________________
    cout << endl << "______________2. Function Seconds______________";
    bool positive_hour_input = true;
    while (positive_hour_input == true)
    {
        string h, m, s;
        string timeformat;
        string resultstring;
        
        cout << endl << "Input hh:mm:ss. To quit, enter a negative hh" << endl;
        cin >> timeformat;
    
        long length = size(timeformat);
        long position1, position2;
        position1 = timeformat.find(":");
        h = timeformat.substr(0, position1);
        if (stoi(h) < 0)
            break;
        timeformat = timeformat.substr(position1+1, length);
        position2 = timeformat.find(":");
        m = timeformat.substr(0, position2);
        s = timeformat.substr(position2+1, length);
            //I have this block because
            //1. user input format has to be a string format with semicolons like 12:59:59
            //2. hms_to_secs() takes 3 int values
            //Thus, I have to place this lengthy conversion block in the main function.
        
        cout << hms_to_secs(stoi(h), stoi(m), stoi(s));
    }
    
    //Function 3 ______________________________________________________
    cout << "______________3. Function Swap______________" << endl;
    int a = 0;
    int b = 0;
    cout << "Input integer A: " << endl;
    cin >> a;
    cout << "Input integer B: " << endl;
    cin >> b;
    
    swap(a, b);
    cout << "Swapped! Now A = " << a << " and B = " << b << "." << endl;
    return 0;
}

double power(double num, int pow=2)
{
    double result = num;
    for (; pow > 1; pow--)
    {
        result = result * num;
    }
    return result;
}

long hms_to_secs(int h, int m, int s)
{
    long time;
    time = h * 3600 + m * 60 + s;
    return time;
}

void swap(int& a, int& b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

/*
 Raising a number n to a power p is the same as multiplying n by itself p times.
 
 Write a function called power() that takes a double value for n and an int value for p, and returns the result as a double value.
 
 Use a default argument of 2 for p, so that if this argument is omitted, the number n will be squared.
 */
