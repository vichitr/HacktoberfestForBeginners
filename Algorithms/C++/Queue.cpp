#include<iostream>
using namespace std;

class node{
	public:
		node *next;
		int value;
};

class que{
	node *head;
	node *tail;
	public:
		que(){
			head=NULL;
			tail=NULL;
		}
		void push(int data){
			node *ptr=new node;
			ptr->value=data;
			ptr->next=NULL;
			if(head==NULL){
				head=ptr;
				tail=ptr;
			}
			else{
				tail->next=ptr;
				tail=ptr;
			}
		}
//   pop function started from here


		void pop(){
			node *prev,*forward;
			prev=head;
			forward=head->next;
			if(head!=NULL){
				head=head->next;
				delete(prev);

			}
			else{
				cout<<"list is empty"<<endl;
				}
		}
		void display(){
			node *ptr;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->value<<endl;
				ptr=ptr->next;
			}
				cout<<endl<<endl;
		}
};
int main()
{
	que ahsan;
	ahsan.push(23);
	ahsan.push(34);
	ahsan.push(345);
	ahsan.push(344);
	ahsan.display();
	ahsan.pop();
	ahsan.display();
}

