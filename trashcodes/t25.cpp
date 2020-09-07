#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class exer : public invalid_argument
{
private:
    string msg;
public:
    virtual string what (){ return msg; }
};

class nbp : public exer
{

};
void fun ()
{
    if (true)
        throw exer 
}

class ic : public exer 
{

};

int main()
{

}
