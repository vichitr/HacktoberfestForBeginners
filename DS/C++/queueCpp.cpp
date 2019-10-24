#include<iostream>
using namespace std;

struct queue
{
	int value;
	queue *next;
};

void removeFromQueue(queue*& head) // remove first element from queue
{
	if (head)
	{
		queue* ptr = head->next;
		delete head;
		head = ptr;
	}
}

void addToQueue(queue*& head, int nValue) // add new value to queue
{
	if (head == nullptr) // first element 
	{
		head = new queue;
		head->value = nValue;
		head->next = nullptr;
	}
	else  // add element on the end of the queue 
	{
		auto ptr = head;
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = new queue{ nValue, nullptr };
	}
}

void deleteQueue(queue *&head) // delete queue 
{
	while (head)
	{
		auto ptr = head->next;
		delete head;
		head = ptr;
	}
}

void printQueue(queue *head)
{
	while (head)
	{
		cout << head->value << endl;
		head = head->next;
	}
}

int main()
{
	// TEST
	queue* pHead = nullptr;
	addToQueue(pHead, 231);
	addToQueue(pHead, 121);
	addToQueue(pHead, 251);
	addToQueue(pHead, 12);
	addToQueue(pHead, 14);
	addToQueue(pHead, 99);
	printQueue(pHead);
	removeFromQueue(pHead);
	removeFromQueue(pHead);
	removeFromQueue(pHead);
	printQueue(pHead);
	deleteQueue(pHead);
	


}
