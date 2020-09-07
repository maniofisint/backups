#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("..\\DataFile\\data.dat", ios::binary);

    int n;
    in.read(reinterpret_cast<char *>(&n), sizeof(int));
    while(!in.eof())
    {
        cout << n << ", ";
        in.read(reinterpret_cast<char *>(&n), sizeof(int));
    }
    in.close();
    return 0;
}
