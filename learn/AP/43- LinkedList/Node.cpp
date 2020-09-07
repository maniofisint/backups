#include "Node.h"

template <typename T>
Node<T>::Node(T val)
{
    setKey(val); //key = val;
    setNext(nullptr);
}

template <typename T>
void Node<T>::setKey(T val)
{
    key = val;
}

template <typename T>
T Node<T>::getKey()
{
    return key;
}

template <typename T>
void Node<T>::setNext(Node *p)
{
    next = p;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return  next;
}
