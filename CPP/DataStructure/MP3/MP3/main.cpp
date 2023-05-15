//
//  main.cpp
//  MP3
//
//  Created by Fei Gao on 2022/4/21.
//

#include <iostream>
#include "class.h"

using namespace std;

int roll()
{
    return rand() % 100;
}


template <typename T>
void merge(DIYList<T> &listA, DIYList<T> &listB, DIYList<T> &listC)
{
    DIYList<T> copyA, copyB;
    copyA = listA;
    copyB = listB;
    T temp;
    int n = 0;

    while (!copyA.isEmpty())
    {
        temp = copyA.front();
//        cout << "debug1" << endl;
        if (!listC.find(temp))
            listC.pushBack(temp);
//        cout << "debug2" << endl;
        copyA.popFront();
//        cout << "debug3" << n << endl;
    }
    
    while (!copyB.isEmpty())
    {
        temp = copyB.front();
        if (!listC.find(temp))
            listC.pushBack(temp);
        copyB.popFront();
    }
}



int main() {
    srand(time(0));
    
    DIYList<int> listA, listB, listC;
    
    for (int i = 0; i < 20; i++)
    {
        listA.pushBack(roll());
    }

    for (int i = 0; i < 15; i++)
    {
        listB.pushBack(roll());
    }

    
    merge(listA, listB, listC);

    cout << "If the first list has" << endl;
    listA.print();
    cout << endl << "And the second line has" << endl;
    listB.print();
    cout << endl << "The result will:" << endl;
    listC.print();
    cout << endl;
    listC.calculate();
    cout << endl;
    
    return 0;
}
