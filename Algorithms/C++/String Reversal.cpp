#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
	public:
		void Node_Add(char);
		void Node_Rev();
		Node()	{prev=next=NULL;}
		~Node()	{prev=next=NULL;}
	private:
		char info;
		Node *prev, *next;
}*HEAD;

void Node::Node_Add(char info)
{
	Node *node=new Node;
	node->info=info;
	if(HEAD!=NULL)
	{
		node->prev=HEAD;
		HEAD->next=node;
	}
	HEAD=node;
}

void Node::Node_Rev()
{
	Node *temp=HEAD;
	cout<<"The reversed string is :- \n";
	while(temp!=NULL)
	{
		cout<<temp->info;
		temp=temp->prev;
	}
}

main()
{
	Node ptr;
	char str[50];
	cout<<"Enter string: ";	gets(str);
	for(int i=0;str[i]!='\0';i++)
		ptr.Node_Add(str[i]);
	ptr.Node_Rev();
}
