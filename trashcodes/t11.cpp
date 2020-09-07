#include <iostream>
#include <string>
#include <vector>

using namespace std;
class node
{
	public:
	string key;
	int value;
	node * next;
};

class database
{
public:
	friend class node;

	static database& getInstance()	
	{
		static database instance;
		return instance;
	}
	void add(){
		cout << "enter" << endl;
		string k;
		int v;
		cin >> k >> v;

		node* newnode= new node();
		newnode->key = k;
		newnode->value = v;

		node * last= head;

		if(head == NULL ){
			*head =  newnode ;
			return;
		}
		
		while (last->next != NULL )
			last = last->next;


		last->next = newnode;
		return;	


	}
	void print ()
	{
		node* newone = head;
	        if(head == NULL)
		{
			return;
		}
		while (newone->next != NULL )
		{
			cout << newone->key << ' ' << newone->value;
			newone=newone->next;
		}
		return;
	}

			
	void get(){}
	void  size(){}
private:
	database(){
		cout <<" constructor is called; " << endl;	
	}
	vector <int> value;
	vector <string> key;	
	database (const database & ) = delete;
	node * head=NULL;

};



int main()
{
	database& instanc = database::getInstance();

	/*while (1)
	{
		string s;
		cin >> s;
		if ( s == "exit" )
			exit(0);
		if ( s == "add" )
			instanc.add();
		if ( s == "get" )
			instanc.get();
		if ( s == "size" )
			instanc.size();
	}*/
	for(int i=0 ; i< 4 ;i++)
		instanc.add();

}			
