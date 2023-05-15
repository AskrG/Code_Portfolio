//
//  class.hpp
//  MP1
//
//  Created by Fei Gao on 2022/4/17.
//

#include <iostream>
#include <string>
#include <istream>
#include <stack>
#include <stdio.h>

using namespace std;

class Balance {
private:
    int d_penultima = 0;
    int d_ultima = 0;
    stack<char> count;
public:
    void stackTop();
    void stackPop();
    bool empty();
    bool pair();
    void read(char);
    int assign(char);
};




class Base {
private:
    int d_before;
    int d_base;
    int temp;
    string d_after;
    char c16[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
public:
    void input();
    int const getbefore();
    int const getbase();
    void show();
    void convert();
    void multibaseOutput();
};





class Pattern {
private:
    string d_first;
    string d_second;
public:
    void input();
    string getfirst();
    string getsecond();
    void show();
    void check();
};


