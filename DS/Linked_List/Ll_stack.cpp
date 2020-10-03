#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *link;
};
class Stack{
	public:
	Node *head,*tail;
	Stack(){
		head = NULL;
	}
	void push(int ele);
	int pop();
	void display();
};
void Stack::push(int ele){
	Node *prev;
	Node *cur = new Node;
	cur -> data = ele;
	cur -> link = NULL;
	if (head == NULL)
		head = cur;
	else
		prev -> link = cur;
	prev = cur;
	tail = prev;
}
int Stack::pop(){
	Node *temp = head;
	while(temp -> link != tail){
		temp = temp -> link;
	}
	temp -> link = NULL;
	int x = tail -> data;
	tail = temp;
	if(x == NULL){
		return 0;
	}
	return x; 
}
void Stack::display(){
	Node *temp = head;
	while(temp != NULL){
		cout << temp -> data; 
		cout << " ";
		temp = temp -> link;
	}
	cout << "\n";
}
int main(){
	Stack s;
	int choice=0;
	cout << "Enter\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
	cin >> choice;
	while(choice != 4){
		switch(choice){
			case 1:
				cout << "Enter element to push:\n";
				int temp;
				cin >> temp;
				s.push(temp);
				break;
			case 2:
				cout << "The popped element is \n";
				cout << s.pop();
				cout << "\n";
				break;
			case 3:
				cout << "The Stack is\n";
				s.display();
				break;
			default:
				cout << "Enter 1,2,3 or 4 only.\n";
		}
		cout << "Enter\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
		cin >> choice;
	}
	return 0;
}





