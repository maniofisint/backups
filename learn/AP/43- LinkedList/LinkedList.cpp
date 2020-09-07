#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
    setHead(NULL);
    setTail(NULL);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while(!isEmpty())
        removeFront();
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return head == NULL;
}

template <typename T>
void LinkedList<T>::setHead(Node<T> *h)
{
    head = h;
}

template <typename T>
void LinkedList<T>::setTail(Node<T> *t)
{
    tail = t;
}

template <typename T>
void LinkedList<T>::insertFront(T val)
{
    Node<T> *newNode = new Node<T>(val);
    newNode->setNext(head);
    if(isEmpty())
        tail = newNode;
    head = newNode;
}

template <typename T>
void LinkedList<T>::insertBack(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if(isEmpty())
        head = newNode;
    tail = newNode;
}

template <typename T>
T LinkedList<T>::front()
{
    return head->getKey();
}

template <typename T>
T LinkedList<T>::back()
{
    return tail->getKey();
}

template <typename T>
void LinkedList<T>::removeFront()
{
    if(isEmpty())
        return;
    Node<T> *temp = head;
    head = head->getNext();
    if(isEmpty())
        tail = NULL;
    delete temp;
}

template <typename T>
void LinkedList<T>::removeBack()
{
    if(isEmpty())
        return;
    Node<T> *temp = tail;
    if(head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        Node<T> *p = head;
        while(p->getNext() != tail)
            p = p->getNext();

        p->setNext(NULL);
        tail = p;
    }
    delete temp;
}

template <typename T>
void LinkedList<T>::print()
{
    for(Node<T> *p = head; p != NULL; p = p->getNext())
        cout << p->getKey() << ", ";
    cout << endl;
}
