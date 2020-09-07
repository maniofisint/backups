#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<int> ll;

    ll.insertFront(10);
    ll.insertFront(5);
    ll.insertFront(2);

    ll.removeFront();

    ll.insertFront(20);
    ll.insertFront(12);

    ll.removeBack();
    ll.removeBack();

    ll.removeFront();
    //ll.removeBack();

    ll.print();
    return 0;
}
