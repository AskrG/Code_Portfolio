//
//  Line.hpp
//  MP2
//
//  Created by Fei Gao on 2022/4/20.
//

#ifndef Line_h
#define Line_h
#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <list>
#include <iomanip>
#include <stdio.h>
using namespace std;

class Line
{
private:
    queue<int> d_q;
    int d_time;
    int d_maxTime;
    int d_currentTime;
    int d_maxNumber;
    int d_currentNumber;
    int d_nextTime;
    int d_serviceTime;
public:
    Line(int);
    void show();
    void initialize();
    void work();
    int roll();

};

#endif /* Line_hpp */
