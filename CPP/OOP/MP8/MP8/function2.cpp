//
//  function2.cpp
//  MP8
//
//  Created by Fei Gao on 2022/4/1.
//

#include "function2.hpp"
using namespace std;
void Two::setData(int a, int b, int c) {
    One::setData(a, b);
    z = c;

}

void Two::print() const {
    One::print();
    cout << ", z = " << z << "." << endl;
}
