#include<iostream>
#include<string>

using namespace std;

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

int main()
{
	LinkedList<int> ll;
	int n;
	cin >> n;
	
    ll.insertBack(10);
    ll.insertBack(5);
    ll.insertBack(2);
	ll.print();
    ll.removeFront();

	ll.print();

    ll.insertFront(20);
    ll.insertFront(12);

    ll.removeBack();
    ll.removeBack();

    ll.removeFront();
    //ll.removeBack();

    ll.print();
    return 0;
}

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







