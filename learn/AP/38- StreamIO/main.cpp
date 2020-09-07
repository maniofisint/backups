#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const char *const sent = "Hello world!";
    int n;
    const int SIZE = 80;
    char buffer1[SIZE];
    char buffer2[SIZE];

    cout << sent << endl;
    cout << static_cast<const void *>(sent) << endl;
    cout << "\n-------------------------------------------------------------\n";
    cout.put('M').put('\n').put('N').put('\n');
    cout.put(65).put(77).put(97);
    /*
    cout << "\n-------------------------------------------------------------\n";
    int character;
    cout << cin.eof() << endl;
    while((character = cin.get()) != EOF)
        cout.put(character);
    cout << "\n-------------------------------------------------------------\n";
    //cin >> buffer1;
    //cout << buffer1 << endl;
    cin >> buffer1;
    cout << buffer1 << endl;
    cin.ignore();
    cin.get(buffer1, SIZE);
    cout << buffer1 << endl;
    cin.ignore();
    //cin.get(buffer1, SIZE);
    //cout << buffer1 << endl;
    cin.getline(buffer1, SIZE);
    cout << buffer1 << endl;
    cin.getline(buffer1, SIZE);
    cout << buffer1 << endl;
    cout << "\n-------------------------------------------------------------\n";
    cin >> buffer1;
    cout << buffer1 << endl;
    cout << cin.peek() << endl;
    cin.ignore();
    cout << cin.peek() << endl;
    cin.ignore();
    cout << cin.peek() << endl;
    cin.ignore();
    cout << cin.peek() << endl;
    cout << cin.peek() << endl;
    cin.putback('Q');
    cout << cin.peek() << endl;
    cout << "\n-------------------------------------------------------------\n";
    cin >> n;
    cout << n << endl;
    cout << hex << n << endl;
    cout << dec << n << endl;
    cout << oct << n << endl;
    cout << setbase(7) << n << endl;
    cout << "\n-------------------------------------------------------------\n";
    cout << fixed;
    cout.precision(10);
    double root2 = sqrt(2);
    cout << root2 << endl;
    for(int i = 0; i < 10; i++)
        cout << setprecision(i) << root2 << endl;
    cout << cout.precision() << endl;*/
    cout << "\n-------------------------------------------------------------\n";
    n = 123456;

    cout << n << endl;
    cout << setw(10) << n << endl;
    cout << n << endl;
    cout << setw(4) << n << endl;

    cout << left << setw(12) << n << n << endl;
    cout << setw(10) << n << endl;
    cout << right << setw(10) << n << endl;

    cout.fill('0');
    cout << setw(8) << n << endl;
    cout << left << setw(8) << n << endl;
    //cout.fill('#');
    cout << setfill('#') << setw(8) << n << endl;
    cout << right << setw(8) << n << endl;

    cout << setfill(' ') << internal << setw(10) << -n << endl;
    cout << setfill(' ') << setw(10) << -n << endl;
    cout << setfill(' ') << right << setw(10) << -n << endl;

    cout << showbase;
    cout << setw(10) << n << endl;
    cout << setw(10) << hex << n << endl;
    cout << setw(10) << dec << n << endl;
    cout << setw(10) << oct << n << endl;
    cout << noshowbase;
    cout << n << endl;
    cout << hex << n << endl;
    cout << dec << n << endl;
    cout << oct << n << endl;

    return 0;
}
