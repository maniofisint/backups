#include <iostream>
#include <list>
using namespace std;

template <typename T>
void printList(list<T>);

int main()
{
    list<int> li;

    li.push_back(5);
    li.push_back(7);
    li.push_front(3);
    li.push_back(2);
    li.pop_back();
    li.push_back(4);
    printList(li);
    li.sort();
    printList(li);
    li.reverse();
    printList(li);

    list<char> liChar;
    liChar.push_front('c');
    liChar.push_front('b');
    liChar.push_front('a');

    printList(liChar);
    return 0;
}

template <typename T>
void printList(list<T> l)
{
    for(auto it = l.begin(); it != l.end(); it++)
        cout << *it << ", ";
    cout << endl;
}
