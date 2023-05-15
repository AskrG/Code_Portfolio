//
//  main.cpp
//  Final
//
//  Created by Fei Gao on 2022/4/28.
//

#include <iostream>
#include <list>
#include <queue>
#include <iterator>
#include <vector>

using namespace std;

template <typename T>
void f(node<T> * & front)
{    node<T> *prev, *curr, *p;

    if (front != NULL || front->next != NULL)
    {
        curr = front->next;
        prev = front;

        do
        {    p = curr->next;
            curr->next = prev;
            if (p != NULL)
            {    prev = curr;
                curr = p;
            }
        }
        while (p != NULL);

        front->next = NULL;
        front = curr;
    }
}


int main ()
{
    
   


  return 0;
}


