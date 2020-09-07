#include <iostream>
#include <string>
using namespace std;

void f1()
{
    cout << "begin of f1" << endl;
    bool someCond = true;

    if(someCond)
        throw "Some error in f1";
    cout << "end of f1" << endl;
}

void f2()
{
    bool someCond = true;

    if(someCond)
        try{
            f1();
        }
        catch(const char *err)
        {
           cout << "Exception handled in f2" << endl;
           throw;
        }
}
void f3()
{
    try{
        f2();
    }
    catch(const char *err)
    {
       throw;
    }
}

class StringErrorMessage : public logic_error
{
public:
    StringErrorMessage(const char *s = "")
        :logic_error(s) {}
};

class IntErrorMessage : public invalid_argument
{
public:
    IntErrorMessage(int n = 0)
        :invalid_argument(to_string(n)) {}
    virtual string what () { return msg;}
protected:
    string msg ="alo lai amli";
};

class notbalanced : public IntErrorMessage
{
public:
    notbalanced()
    {
        msg = "parentheses not balanced";
    }
};
int main()
{
   /* try {
        throw notbalanced()
    }
    catch (notbalanced & {
        
    }*/
    IntErrorMessage &err;
    bool someCond = false;
    cout << "before try" << endl;
    try{
        //f3();
        cout << "before throw" << endl;
        if(someCond)
            throw StringErrorMessage("I feel some error.");
        else
            throw IntErrorMessage(5);
        cout << "after throw" << endl;
    }
    catch( )
    {
        cout << "exception handled!" << endl
             << "Message: " << err.what() << endl;
    }
    cout << "after catch" << endl;
    return 0;
}
