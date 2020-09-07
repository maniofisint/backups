#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename T>
class Node
{
public:
    Node(T val);
    void setKey(T val);
    T getKey();
    void setNext(Node *p);
    Node *getNext();
private:
    T key;
    Node *next;
    //Node *prev;
};

#endif // NODE_H_INCLUDED
