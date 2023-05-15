//
//  myArray.hpp
//  MP6
//
//  Created by Fei Gao on 2022/3/26.
//

#ifndef myArray_h
#define myArray_h
#include <iostream>
#include <stdio.h>

class myArray{
    int d_size;
    int d_aQuo;
    int d_adQuem;
    int * d_ary;
public:
    myArray(int);
    myArray(int, int);
    ~myArray();
    void pArray();
    void operator[](int);
    bool check(int);
};

#endif /* myArray_h */
