#include "Stack.h"
#include <iostream>
using namespace std;

template <typename T, int Size>
Stack<T, Size>::Stack(int s)
{
    vec = new T[s];
    stackSize = 0;
    stackCap = s;
    cout << "Stack constructed, with capacity: " << stackCap << endl;
}

template <typename T, int Size>
Stack<T, Size>::~Stack()
{
    cout << "Stack destructed, with capacity: " << stackCap << endl;
    delete[] vec;
}

template <typename T, int Size>
bool Stack<T, Size>::isEmpty()
{
    return stackSize == 0;
}

template <typename T, int Size>
bool Stack<T, Size>::isFull()
{
    return stackSize == stackCap;
}

template <typename T, int Size>
void Stack<T, Size>::push(T e)
{
    if(isFull())
        return;
    vec[stackSize++] = e;
}

template <typename T, int Size>
T Stack<T, Size>::pop()
{
    if(isEmpty())
        return -1;
    return vec[--stackSize];
}

