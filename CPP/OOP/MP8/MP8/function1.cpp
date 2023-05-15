//
//  function1.cpp
//  MP8
//
//  Created by Fei Gao on 2022/4/1.
//

#include "function1.hpp"
using namespace std;

void One::setData(int u, int v) {
    x = u;
    y = v;
}

void One::print() const {
    cout << "x = " << x << ", y = " << y;
}
