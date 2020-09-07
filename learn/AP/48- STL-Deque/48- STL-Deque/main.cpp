#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

template <typename T>
void printList(deque<T>);

int main()
{
    deque<int> d;

    d.push_back(5);
    d.push_back(7);
    d.push_front(3);
    d.push_back(2);
    d.pop_back();
    d.push_back(4);
    printList(d);
    sort(d.begin(), d.end());
    printList(d);

    deque<char> d2;
    d2.push_front('c');
    d2.push_front('b');
    d2.push_front('a');

    printList(d2);
    return 0;
}

template <typename T>
void printList(deque<T> l)
{
    for(auto it = l.begin(); it != l.end(); ++it)
        cout << *it << ", ";
    cout << endl;
}
