//
//  class.hpp
//  MP3
//
//  Created by Fei Gao on 2022/4/21.
//

#ifndef class_h
#define class_h
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

template <typename T> class DIYList;

template <typename T>
class ListNode
{
    friend class DIYList<T>;
private:
    ListNode<T> *next;
    T d_data;
public:
    ListNode(const T& info): d_data(info), next(nullptr) {}
    T getData() const { return d_data;}
};

template <typename T>
class DIYList
{
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    ListNode<T> *getNewNode(const T & value);
public:
    DIYList();
    ~DIYList();
    void print() const;
    bool isEmpty() const;
    void pushFront(const T & value);
    void pushBack(const T & value);
    void popFront();
    void popBack();
    T front();
    T back();
    int size();
    DIYList<T> operator = (const DIYList<T> & rhs);
    bool find(T);
    void calculate();
};

template <typename T>
DIYList<T>::DIYList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DIYList<T>::~DIYList()
{}

template <typename T>
ListNode<T>* DIYList<T>::getNewNode(const T & value)
{
    return new ListNode<T>(value);
}

template <typename T>
void DIYList<T>::print() const
{
    ListNode<T> *temp = head;
    
    if (isEmpty())
    {
        cout << "Empty List" << endl;
        return;
    }
    
    while (temp != nullptr)
    {
        cout << temp->d_data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
bool DIYList<T>::isEmpty() const
{
    if (head == nullptr)
        return true;
    else
        return false;
}

template <typename T>
void DIYList<T>::pushFront(const T & value)
{
    ListNode<T> *p = getNewNode(value);
    
    if (isEmpty())
        head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
}

template <typename T>
void DIYList<T>::pushBack(const T & value)
{
    ListNode<T> *p = getNewNode(value);
    
    if (isEmpty())
        head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
}

template <typename T>
void DIYList<T>::popFront()
{
    if (isEmpty())
        return;
    
    ListNode<T> *temp = head;
    
    if (head == tail)
        head = tail = nullptr;
    else
        head = head->next;
    
    delete temp;
}

template <typename T>
void DIYList<T>::popBack()
{
    if (isEmpty())
        return;
    
    ListNode<T> *temp = head;
    
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    
    tail = temp;
    delete temp->next->next;
    temp->next = nullptr;
}

template <typename T>
T DIYList<T>::front()
{
    if (!isEmpty())
        return head->d_data;
    
    return NULL;
}

template <typename T>
T DIYList<T>::back()
{
    if (!isEmpty())
        return tail->d_data;
    
    return NULL;
}

template <typename T>
int DIYList<T>::size()
{
    DIYList<T> *temp = head;
    int counter = 0;
    
    if (isEmpty())
        return counter;
    
    counter++;
    while (temp != tail)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}


template <typename T>
DIYList<T> DIYList<T>::operator = (const DIYList<T> & rhs)
{
    ListNode<T> *temp = rhs.head;
    
    if (rhs.isEmpty())
        return DIYList<T>();
    
    while (temp != nullptr)
    {
        this->pushBack(temp->d_data);
        temp = temp->next;
    }
    
    return *this;
}

template <typename T>
bool DIYList<T>::find(T item)
{
    ListNode<T> *temp = this->head;
//    cout << "debug1" << endl;
    
    if (this->isEmpty())
        return false;
//    cout << "debug2" << endl;
    
    while (temp != nullptr)
    {
//        cout << "debug3" << endl;
        
        if (temp->d_data == item)
        {
//            cout << "debug4" << endl;
            
            return true;
        }
//        cout << "debug5" << endl;
        temp = temp->next;
    }
//    cout << "debug6" << endl;
    
    return false;
}

template <typename T>
void DIYList<T>::calculate()
{
    ListNode<T> *temp = this->head;
    int sum = 0;
    int index = 0;
    float average;
    
    if (this->isEmpty())
        return;
    
    while (temp != nullptr)
    {
        sum += temp->d_data;
        index++;
        temp = temp->next;
    }
    average = float(sum) / float(index);
    cout << "The sum of the final list’s elements is : " << sum << endl;
    cout << "The average of the final list is : " << fixed << setprecision(2) << average;

}
#endif /* class_h */
