#include <iostream>
using namespace std;

class A
{
public:
    A(int id = 0) : Aid(id)
    { cout << "Class A Constructor, Id = " << Aid << endl; }
    ~A()
    { cout << "Class A Destructor, Id = " << Aid << endl; }
    void print()
    { cout << "Class A, Id = " << Aid << endl; }
protected:
    int Aid;
};

class B : public A
{
public:
    B(int id = 0) : A(id)
    { cout << "Class B Constructor, Id = " << Aid << endl; }
    ~B()
    { cout << "Class B Destructor, Id = " << Aid << endl; }
    void print()
    { cout << "Class B, Id = " << Aid << endl; }
};

class C : public B
{
public:
    C(int id = 0) : B(id)
    { cout << "Class C Constructor, Id = " << Aid << endl; }
    ~C()
    { cout << "Class C Destructor, Id = " << Aid << endl; }
    void print()
    { cout << "Class C, Id = " << Aid << endl; }
};

int main()
{
    C   objC(5);
    objC.print();
    return 0;
}
