//
//  function2.hpp
//  MP8
//
//  Created by Fei Gao on 2022/4/1.
//

#ifndef function2_hpp
#define function2_hpp
#include <stdio.h>
#include "function1.hpp"

class Two: public One
{
public:
   void setData(int a, int b, int c);    //Postcondition: x = a; y = b; z = c;
   void print() const;    //Output the values of x, y, and z
private:
   int z;
};


#endif /* function2_hpp */
