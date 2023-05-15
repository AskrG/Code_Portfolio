//
//  function1.hpp
//  MP8
//
//  Created by Fei Gao on 2022/4/1.
//


#define function1_hpp
#include <iostream>
#include <stdio.h>
class One
{
public:
   void print() const;   //Output the values of x and y
protected:
   void setData(int u, int v);    //Post condition: x = u; y = v;
private:
   int x;
   int y;
};


