#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "Node.cpp"

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void setHead(Node<T> *);
    void setTail(Node<T> *);
    bool isEmpty();
    Node<T> *getHead();
    void insertFront(T);
    void insertBack(T);
    T front();
    T back();
    void removeFront();
    void removeBack();
    void print();
private:
    Node<T> *head;
    Node<T> *tail;
};

#endif // LINKEDLIST_H_INCLUDED
