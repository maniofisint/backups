// Friends can access private members of a class.
#include <iostream>
using namespace std;

class Count
{
    friend class Test;
    //friend void setX(Count&, int); // friend declaration
    public:
        Count()
            : x(0)
        {}

        void print() const
        {
            cout << x << endl;
        }
    private:
        int x;
};
class Test
{
    //...
};
// function setX can modify private data of Count
// because setX is declared as a friend of Count
void setX(Count &c, int val)
{
    c.x = val;          // allowed because setX is a friend of Count
}

int main()
{
    Count counter;

    cout << "counter.x after instantiation: ";
    counter.print();

    setX(counter, 8);   // set x using a friend function
    cout << "counter.x after call to setX friend function: ";
    counter.print();
}

