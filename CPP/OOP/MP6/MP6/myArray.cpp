//
//  myArray.cpp
//  MP6
//
//  Created by Fei Gao on 2022/3/26.
//

#include "myArray.h"
#include "error.h"
using namespace std;

void myArray::operator[](int index) {
    try {
        check(index);
        cout << d_ary[index-d_aQuo] << endl;
    }
    catch (Excptn &exception) {
        cout << exception.errormsg() << endl;
    }
}

bool myArray::check(int index) {
    if ((index >= d_aQuo) && (index < d_adQuem))
        return true;
    else
        throw Excptn("Error: index out of range.");
}


myArray::myArray(int n) {
    d_aQuo = 0;
    d_adQuem = n;
    d_size = n;
    d_ary = new int(d_size);
    
    for (int i = 0; i < d_size; i++) {
        d_ary[i] = (i+1)*10;
    }
}
myArray::myArray(int n, int k) {
    d_aQuo = n;
    d_adQuem = k;
    d_size = k - n;
    d_ary = new int(d_size);
    
    for (int i = 0; i < d_size; i++) {
        d_ary[i] = (i+1)*100;
    }
}

void myArray::pArray() {
    for (int i = 0; i < d_size; i++)
    {
        cout << d_ary[i] << endl;
    }
}

myArray::~myArray(){
    delete[] d_ary;
}


