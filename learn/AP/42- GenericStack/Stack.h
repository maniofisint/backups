#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <typename T, int Size = 10>
class Stack
{
public:
    Stack(int s = Size);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(T e);
    T pop();
private:
    int stackCap;
    int stackSize;
    T *vec;
};


#endif // STACK_H_INCLUDED
