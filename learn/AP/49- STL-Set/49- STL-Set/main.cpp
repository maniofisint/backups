#include <iostream>
#include <set>
using namespace std;

template <typename T>
void printSet(set<T> s);

int main()
{
    set<int> intSet;

    intSet.insert(7);
    intSet.insert(2);
    intSet.insert(0);
    intSet.insert(5);
    intSet.insert(1);
    intSet.insert(8);
    intSet.insert(2);

    intSet.erase(2);

    set<int>::iterator it = intSet.find(6);
    if(it != intSet.end())
        cout << "Found!" << endl;
    else
        cout << "Not found!" << endl;

    printSet(intSet);

    return 0;
}

template <typename T>
void printSet(set<T> s)
{
    for(auto it = s.begin(); it != s.end(); ++it)
        cout << *it << ", ";
    cout << endl;
}
