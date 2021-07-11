#include<iostream>
#include<string>

//using namespace std;

struct node
{
    int data;
	int prn;			
	node* next;
};
	
class queue													//queue class for implementing priority queue
{
	private:
		node* front;
		node* rear;
	
	public:
		queue() : front(NULL), rear(NULL) {}
		
		void push(int element, int priority)
		{
			
			node* newNode;
			
			newNode = new node;
			
			newNode->data = element;
			newNode->prn = priority;
			
			
			
			if(front == NULL || front->prn > priority)
			{
				newNode->next = front;
				front = newNode;
				//rear = newNode;
				
				return;
			}
			
			node* itr = front;
			node* n = itr;
			
			while(itr != NULL)
			{
				if(itr->prn > priority)
				{
					break;
				}
				
				n = itr;
				itr = itr->next;
			}
			
			
			newNode->next = n->next;
			n->next = newNode;
	
		}
		
		void pop()
		{
			
			if(front == NULL);
			{
				std::cout << "\n Queue already empty";
				return;
			}
			
			node* temp = front;
			
			front = front->next;
			
			delete temp;
		}
		
		void display()
		{
			if(front == NULL)
			{
				std::cout << "\nQueue is empty\n";
				return;
			}
			node* itr = front;
			
			std::cout << "\n\tData" << "\t\t" << "Priority" << std::endl;
			
			while(itr != NULL)
			{
				std::cout << "\t" << itr->data << "\t\t" << itr->prn << std::endl;
				itr = itr->next;
			}
		}
		
	};
	
	
	int main()
	{
		queue q;
		
		q.display();
		q.push(76, 1);
		q.display();
		q.push(34, 3);
		q.display();
		q.push(19, 5);
		q.display();
		q.push(33, 2);
		q.display();
		q.push(12, 7);
		
		q.display();
		
		q.pop();
		
		q.display();

	}
	
	
	
	
	
	
	
		
		
