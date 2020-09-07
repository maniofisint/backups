#include <iostream>
#include <string>
using namespace std;

template <typename T>
class node
{
    public:
    node ()
    {
        next = NULL ;
    }
    node (T val)
    {
        key = val ; 
        next = NULL;
    }
    T key;
    node * next;
};

template <typename T>
void insert ( node<T> ** h , T val)
{
    
    if ( *h == NULL ){

        node<T> * newNode = new node<T> (val);
        *h = newNode;
        return ;
    }
    insert ( &(*h)->next , val);
}
template <typename T>
void print ( node<T> ** h )
{
  
    if ( *h != NULL)
    {
        cout << (*h)->key ;
        if ( (*h)->next != NULL )
            cout << ' ';
        print ( &(*h)->next );
    }
}
template <typename T>
void dilit ( node<T> ** h , node <T> ** last , T val)
{

    if ( (*h)->key == val ){

        if ( *last == NULL ){
           
            if ( (*h)->next != NULL ){
               (*h) = (*h)->next;
                dilit ( h, last , val);
            }
            else{
                node<T> * newone = new node<T> ;
                (*h)= newone;
                //delete newone;
            }
        }

        else {
           
            if ( (*h)->next != NULL ){
                (*last)->next = (*h)->next;
                dilit ( &(*last)->next , last , val);
            }
            else{
                node<T> * newone = new node<T> ( (*last)->key);
                (*last) = newone;
                //delete newone;
            }
        }
    }
    else
    {
        if ( (*h)->next != NULL && (*h)!= NULL )
        dilit ( &(*h)->next , h , val);   
    }
    
       

}

template <typename T>
class linkedList
{
public:
    linkedList()
    {}
    void insertBack(T val)
    {
        insert( &head , val);
    }
    void Print ()
    {
        print( &head );
    }
    void del (T val)
    {
        node<T> * noidia = NULL;
        dilit ( &head , &noidia , val);
    }
    friend void insert <T> ( node<T> ** h , T val);
    friend void print <T> ( node<T> ** h );
    friend void dilit <T> ( node<T> ** h , node <T> ** last , T val);
private:
    node<T> * head = NULL; 

};
int main()
{
    int n;
    char c;
    cin >> n >> c;

    /*linkedList<string> ll;
    string s;
    for( ; n>0 ; n--){
        cin >> s;
        ll.insertBack(s);
    }
    cin >> n;
    for( ; n>0 ; n--){
        cin >> s;
        ll.del(s);
        ll.Print();
        cout << endl;
    }
    return 0;*/
    
    if ( c == 'i'){
        linkedList<int> ll;
        int x;
        for( ; n>0 ; n--){
            cin >> x;
            ll.insertBack(x);
        }
        cin >> n;
        for( ; n>0 ; n--){
            cin >> x;
            ll.del(x);
            ll.Print();
            cout << endl;
        }
    }
    
    if ( c == 's'){
        linkedList<string> ll;
        string s;
        for( ; n>0 ; n--){
            cin >> s;
            ll.insertBack(s);
        }
        cin >> n;
        for( ; n>0 ; n--){
            cin >> s;
            ll.del(s);
            ll.Print();
            cout << endl;
        }
    }

    return 0;
    linkedList<int> ll;
    int x =234;
    int y =786;
    ll.insertBack(x);
    ll.insertBack(y);
    ll.Print();


    return 0;
}
