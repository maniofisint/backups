#include <iostream>
#include <string>
using namespace std;

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
    T& operator [] (int );
private:
    int stackCap;
    int stackSize;
    T *vec;
};

int main()
{

    int n;
    cin >> n;
    getchar();
    Stack<string > s(n);
    for(int i =0 ;i < n ;i++ )
        getline(cin ,s[i]);

    for( int j =0 ;j < n ;j++){
        for(int i = s[j].size()-1 ; i>=0 ; i--)
            cout << s[j][i];
        cout << endl;
        
    }

    return 0;
}

template <typename T, int Size>

Stack<T, Size>::Stack(int s)
{
    vec = new T[s];
    stackSize = 0;
    stackCap = s;
}

template <typename T, int Size>
Stack<T, Size>::~Stack()
{
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


template <typename T , int  Size>
T& Stack<T , Size > :: operator[](int index)
{
    return vec [index];
}
