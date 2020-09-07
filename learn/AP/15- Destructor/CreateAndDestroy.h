#include <string>
using namespace std;

#ifndef CREATEANDDESTROY_H_INCLUDED
#define CREATEANDDESTROY_H_INCLUDED

class CreateAndDestroy
{
    public:
        CreateAndDestroy(int, string);
        ~CreateAndDestroy();
    private:
        int objectID;
        string message;
};

#endif // CREATEANDDESTROY_H_INCLUDED
