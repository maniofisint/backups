#include <iostream>
using namespace std;

class A
{
public:
    A(int id = 0) : Aid(id)
    { cout << "Class A Constructor, Id = " << Aid << endl; }
    virtual ~A()
    { cout << "Class A Destructor, Id = " << Aid << endl; }
    virtual void print()
    { cout << "Class A, Id = " << Aid << endl; }
protected:
    int Aid;
};

class B : public A
{
public:
    B(int id = 0) : A(id)
    { cout << "Class B Constructor, Id = " << Aid << endl; }
    virtual ~B()
    { cout << "Class B Destructor, Id = " << Aid << endl; }
    void print()
    { cout << "Class B, Id = " << Aid << endl; }
};

class C : public B
{
public:
    C(int id = 0) : B(id)
    { cout << "Class C Constructor, Id = " << Aid << endl; }
    virtual ~C()
    { cout << "Class C Destructor, Id = " << Aid << endl; }
    void print()
    { cout << "Class C, Id = " << Aid << endl; }
};

int main()
{
    //C objC(5);
    A *p = new C(5);
    //objC.print();
    p->print();
    delete p;
    return 0;
}
