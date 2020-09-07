#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input;
    int len;
    ofstream out("out.txt");
    ifstream in("in.txt");

    while(!in.eof())
    {
        in >> input >> len;
        out << input.substr(0, len) << endl;
    }

    in.close();
    out.close();
    return 0;
}
