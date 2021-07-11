/*
 * Queue is a FIFO (First In First Out) dat structue. But this is a priority queue. Here each element has its priority
 * and higher its priority, it will be deleted first. Here lower intiger value is taken as higher priority. For elements
 * of same priority, original queue rule(FIFO) will be followed. Queue is implemented using linked list.
 */


#include<iostream>

struct node											//queue structue
{
    int data;
	int prn;			
	node* next;
};
	
class queue													//queue class for implementing priority queue
{
	private:
		node* frontPtr;										// front pointer to track first element to poppped
	
	public:
		queue() : frontPtr(NULL) {}							// no-arg ctor
		
		void push(int element, int priority)				// insertion function
		{
			
			node* newNode;									// creating new Node
			newNode = new node;
			
			newNode->data = element;
			newNode->prn = priority;
			
			
			
			if(frontPtr == NULL || frontPtr->prn > priority)			// if  it is first element  or has higher priority
			{													// than all the elements present
				newNode->next = frontPtr;
				frontPtr = newNode;
				
				return;
			}
			
			node* itr = frontPtr;
			node* old = itr;
			
			while(itr != NULL)
			{
				if(itr->prn > priority)
				{
					break;
				}
				
				old = itr;
				itr = itr->next;
			}
			
			
			newNode->next = old->next;
			old->next = newNode;
	
		}
		
		void pop()									// deletion function
		{
			
			if(frontPtr == NULL)
			{
				std::cout << "\n Queue already empty\n";
				return;
			}
			
			node* temp = frontPtr;
			frontPtr = frontPtr->next;			// simply delete the elemnt at front
			
			delete temp;
		}
		
		void display()								// to display the queue (not a necessary function)
		{
			if(frontPtr == NULL)
			{
				std::cout << "\nQueue is empty\n";
				return;
			}
			node* itr = frontPtr;
			
			std::cout << "\n\tData" << "\t\t" << "Priority" << std::endl;
			
			while(itr != NULL)
			{
				std::cout << "\t" << itr->data << "\t\t" << itr->prn << std::endl;
				itr = itr->next;
			}
		}
		
		int front()										// returns data of first element not its priority
		{
			if(frontPtr == NULL)
			{
				std::cout << "\nQueue is empty\n";
				return -1;
			}
			return frontPtr->data;
		}
		
	};
	
	
	int main()
	{
		queue q;
		int ch;
		
		do
		{
			std::cout << "\n1- Insert element in queue";
			std::cout << "\n2- Delete element from queue";
			std::cout << "\n3- Display queue";
			std::cout << "\n4- Return front element";
			std::cout << "\n0- Exit Programming";
			std::cout << "\n\tEnter your choice: ";
			
			std::cin >> ch;
			
			switch(ch)
			{
				case 1:
					int element, priority;
					std::cout << "\nEnter element and its priority: ";
					std::cin >> element >> priority;
					q.push(element, priority);
					break;
				case 2:
					q.pop();
					break;
				case 3:
					q.display();
					break;
				case 4:
					if(q.front() != -1)
						std::cout << "\nFront element --> " << q.front() << std::endl;
					break;
				case 0:
					std::cout << "\n Exiting Program";
					break;
				default:
					std::cout << "Invalid choice :(";
					break;
				
			}
			
		}while(ch != 0);
		

	return 0;

	}
	
