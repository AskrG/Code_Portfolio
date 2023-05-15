//
//  Line.cpp
//  MP2
//
//  Created by Fei Gao on 2022/4/20.
//

#include "Line.h"

void Line::show() {
    cout << endl << "The maximum waiting period is " << d_maxTime << endl;
    cout << "The maximum waiting number is " << d_maxNumber << endl;
//while (!d_q.empty()) {
//    cout << d_q.front() << " ";
//    d_q.pop();
//}
//    cout << endl;
}

Line::Line(int period) {
    d_time = period;
    initialize();
}

void Line::initialize() {
    int initial = roll();
    d_time -= initial;
    int first = roll();
    d_q.push(first);
    d_nextTime = roll();
    d_maxNumber = 0;
    d_currentNumber = 1;
    d_currentTime = first + 1;
    d_maxTime = 0;
}

int Line::roll() {
    int num = 1 + rand() % 2;
    return num;
}

void Line::work() {
    cout << left << setw(5) << "Time" << setw(10) << "Serving" << setw(10) << "Queue" << setw(10) << "Next";
    cout << setw(10) << "Max Time" << setw(10) << "WaitNum" << "Max Number";
    while (d_time > 0) {
        //* * * * * * * * * * * * * * * * * * * * PRINT * * * * * * * * * * * * * * * * * * * *
        //each new minute is indicated by a new row
        cout << endl;
        
        //time counter
        cout << setw(4) << d_time;
        
        //current serving time left
        //(1 means it will be finished at the end of this horizontal line)
        if (!d_q.empty()) {
            if (d_q.front() == 0)
                cout << "<";
            else
                cout << " ";
            cout << setw(10) << d_q.front() + 1;
        }
        else {
            cout << setw(11) << " Free";
        }
        
        //current time in queue
        cout << setw(9) << d_currentTime;
        
        //next customer arrival time
        //"<1" means the next customer will arrive at the end of this horizontal line
        if (d_nextTime == 0) {
            cout << "<";
        }
        else {
            cout << " ";
        }
        
        cout << setw(10) << d_nextTime + 1 << setw(10) << d_maxTime << setw(10) << d_currentNumber << d_maxNumber;
        
        //* * * * * * * * * * * * * * * * * * * * EXECUTE * * * * * * * * * * * * * * * * * * * *
        
        d_time--;
        if (d_currentTime > 0)
            d_currentTime--;
        
        if (d_q.front() == 0){
            d_q.pop();
            d_currentNumber--;
        }
        
        d_q.front()--;
        
        if (d_nextTime == 0) {
            d_serviceTime = roll();
            d_q.push(d_serviceTime);
            d_currentTime += d_serviceTime;
            d_currentNumber++;
            d_nextTime = roll();
        }
        d_nextTime--;
        
        d_maxTime = max(d_currentTime, d_maxTime);
        d_maxNumber = max(d_currentNumber, d_maxNumber);
    }
}
