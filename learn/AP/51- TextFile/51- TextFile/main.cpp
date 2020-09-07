#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string input;
    ofstream out("out.txt");
    ifstream in("in.txt");

    //getline(in, input);
    while(!in.eof())
    {
        getline(in, input);
        out << input << endl;
    }
    out.seekp(0, ios::beg);
    out << "Helloooo" << endl;
    //in >> input;
    //cout << input << endl;
    //in.ignore();
    //getline(in, input);
    //cout << input << endl;
    //out << "Helloooooo" << endl;
    out.close();
    in.close();
    return 0;
}
