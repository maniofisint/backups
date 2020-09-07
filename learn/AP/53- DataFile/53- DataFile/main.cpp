#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream myFile("data.dat", ios::binary | ios::in | ios::out | ios::trunc);

    int arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    //for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
    //  out.write(reinterpret_cast<const char*>(arr + i), sizeof(int));
    myFile.write(reinterpret_cast<const char*>(arr), sizeof(arr));

    myFile.seekp(0, ios::beg);
    int n;
    long pos;
    pos = myFile.tellp();
    myFile.read(reinterpret_cast<char *>(&n), sizeof(int));
    while(!myFile.eof())
    {
        if(n == 256)
        {
            n = 1024;
            myFile.seekp(pos, ios::beg);
            myFile.write(reinterpret_cast<const char*>(&n), sizeof(int));
        }
        pos = myFile.tellp();
        myFile.read(reinterpret_cast<char *>(&n), sizeof(int));
    }

    myFile.close();
    return 0;
}
