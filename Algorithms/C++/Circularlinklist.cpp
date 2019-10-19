#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node* previous;
};
class DLL{
	public:
	node* head;
	node* tail;
	DLL()
	{
		head=NULL;
		tail=NULL;
	}
	void insert(int d)
	{
		node* ptr;
		ptr=head;
		node* nptr=new node;
		nptr->data=d;
		nptr->next=NULL;
		nptr->previous=NULL;
		if(head==NULL)
		{
			head=nptr;
			tail=head;
		}
		else
		{
			tail->next=nptr;
			nptr->previous=tail;
			nptr->next=head;
			tail=nptr;
		}
	}
	void print()
	{
		node* ptr;
		ptr=head;
		while(ptr->next!=head)
		{
			cout<<"THE VALUE INSERTED IS:"<<ptr->data<<endl;
			ptr=ptr->next;
					
		}
		cout<<"THE VALUE INSERTED IS:"<<ptr->data<<endl;

	}
	void search(int s)
	{
		node* ptr;
		ptr=head;
		while(ptr->next!=head)
		{
			if(ptr->data==s)
			{
				cout<<"THE VALUE IS FOUND"<<endl;
				return;
			
			}
				ptr=ptr->next;
		}
			if(ptr->data==s)
			{
				cout<<"THE VALUE IS FOUND"<<endl;
				return;
			
			}
	}
	
	

	
	void deletepos() {
   int pos, i;
   int count=1;
   node *ptr, *s;
   if (head == tail && head == NULL) {
      cout<<"List is empty, nothing to delete"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of element to be deleted: ";
   cin>>pos;
   s = head;
   if(pos == 1) {
      count--;
      tail->next = s->next;
      s->next->previous = tail;
      head = s->next;
      delete(s);
      cout<<"Element Deleted"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->next;
      ptr = s->previous;
   }
   ptr->next = s->next;
   s->next->previous = ptr;
   if (pos == count) {
      tail = ptr;
   }
   count--;
   delete(s);
   cout<<"Element Deleted"<<endl;
}

};
int main()
{
	DLL D;
	D.insert(1);
	D.insert(2);
	D.insert(3);
	D.insert(4);
	D.print();
	D.search(4);
	D.deletepos();
	D.print();
}
