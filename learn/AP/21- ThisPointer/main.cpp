// Using the this pointer to refer to object members.
#include <iostream>
using namespace std;

class Test
{
    public:
        explicit Test(int = 0);
        void print() const;
    private:
        int x;
};

Test::Test(int value)
   : x(value) // initialize x to value
{ }

// print x using implicit and explicit this pointers;
// the parentheses around *this are required
void Test::print() const
{
   cout << "        x = " << x << endl;
   cout << "  this->x = " << this->x << endl;
   cout << "(*this).x = " << (*this).x << endl;
}
int main()
{
   Test testObject(131);

   testObject.print();
}
