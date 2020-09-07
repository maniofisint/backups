#include <iostream>
#include <string>
using namespace std;
class node
{
public:
   node (string val)
   {
       key = val;
       next = NULL;
   }
   node * getNext();
   string getKey()
   {
       return key;
   }
private:
   string key;
   node * next;

};

class ll
{
public:
    ll()

    void insert(string s );
    bool isEmpty();
    void fun();
    /*(void func ()
    {
        node * n = new node("ali");
        node * fuck = head;
        fuck = n;
        cout << head->getKey()<< 12 << endl;


    }*/
private:
    node  head;
};


int main()
{
    ll str;
    str.func();
    return 0;

    int n;
    cin >> n;
    string s;
    for(auto i = 0 ; i < n ; i++){
        cin >> s;
        str.insert(s);
    }

    str.fun();
    return 0;
}
node * node :: getNext()
{
    return next;
}
bool ll::isEmpty()
{
    return head == NULL ;
}
void ll::insert(string s)
{
    cout << 43;
    node  newNode = new node(s);
    node  after = head;

    while ( head != NULL)
        head = head->getNext();

    head = newNode;
    
    return ;
}

void ll:: fun()
{
    cout << 123;
    for ( node * p = head ; p != NULL ; p = p->getNext())
        cout << p->getKey() << endl;
    return ;
}

void insertBack(node * h , string val)
{
    if ( h == NULL )
    {
        node * newNode = new node (val);
        h = newNode;
        return ;
    }
    else 
        insertBack(h->getNext,val);
    
    return ;
}