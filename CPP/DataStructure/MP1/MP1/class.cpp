//
//  class.cpp
//  MP1
//
//  Created by Fei Gao on 2022/4/17.
//

#include "class.h"



void Balance::read(char input){
    if (input == '{' || input == '}' || input == '[' || input == ']' || input == '(' || input == ')' ) {
        count.push(input);
        d_penultima = d_ultima;
        d_ultima = assign(count.top());
    }
}

void Balance::stackTop(){
    if (!count.empty()) {
        cout << count.top();
    }
}

void Balance::stackPop(){
    if (!count.empty()) {
        count.pop();
    }
}

bool Balance::empty(){
    return count.empty();
}

bool Balance::pair(){
    bool result = true;

    if (count.size() == 1)
        return result;

    if (d_ultima > 0) {
        if (d_ultima + d_penultima != 0)
            result = false;
        else {
            count.pop();
            count.pop();
            if (!count.empty())
                d_ultima = assign(count.top());
            else
                d_ultima = 0;
        }
    }

    return result;
}

int Balance::assign(char input){
    switch (input)
    {
        case '{': {
            return -3;
            break;
        }
        case '[': {
            return -2;
            break;
        }
        case '(': {
            return -1;
            break;
        }
        case ')': {
            return 1;
            break;
        }
        case ']': {
            return 2;
            break;
        }
        case '}': {
            return 3;
            break;
        }
        default: {
            cout << "Error" << endl;
            return 0;
        }
    }
}




void Base::input(){
    cout << "Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate: ";
    cin >> d_before;
    cin >> d_base;
    temp = d_before;
    d_after = "";
}

int const Base::getbefore(){
    return d_before;
}
int const Base::getbase(){
    return d_base;
}

void Base::show(){
    cout << "Inputs are: " << d_before << ", the base is: " << d_base << ", and the outcome is: " << d_after;
}

void Base::convert(){
    if (d_base == 16) {
        while (temp != 0) {
            d_after += c16[temp % 16];
            temp /= 16;
        }
        reverse(d_after.begin(), d_after.end());
    }
    else {
        while (temp!= 0) {
            d_after += c16[temp % d_base];
            temp /= d_base;
        }
    reverse(d_after.begin(), d_after.end());
    }
}


void Base::multibaseOutput(){
    cout << "    " << d_before << " base " << d_base << " is " << d_after << endl;
}









void Pattern::input(){
    cout << "Input a string: ";
    getline(cin, d_first, '#');
    getline(cin, d_second);
}

string Pattern::getfirst(){
    return d_first;
}

string Pattern::getsecond(){
    return d_second;
}

void Pattern::show(){
    cout << "The first string is: " << d_first << ", and the second string is: " << d_second << endl;
}

void Pattern::check(){
    bool result = true;
    unsigned long length = d_first.size();
    if (length != d_second.size())
        result = false;
    else {
        for (int i = 0; i < length; i++) {
            unsigned long j = length - i - 1;
            if (d_first[i] != d_second[j])
                result = false;
            }
    }
    
    if (result == false)
        cout << d_first << "#" << d_second << " does not match the pattern" << endl;
    else
        cout << d_first << "#" << d_second << " matches the pattern" << endl;

}


