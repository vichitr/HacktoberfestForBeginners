#include<iostream>
using namespace std;

class node{
	public:
		node *next;
		int value;
};

class stack{
	node *head;
	node *tail;
	public:
		stack(){
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
				while(forward->next!=NULL){
						prev=prev->next;
						forward=forward->next;
				}
				tail=prev;
				prev->next=NULL;
				
				delete(forward);
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
		}
};
int main()
{
	stack st;
	st.push(23);
	st.push(25);
	st.push(35);
		
	st.display();
	return 0;
}

