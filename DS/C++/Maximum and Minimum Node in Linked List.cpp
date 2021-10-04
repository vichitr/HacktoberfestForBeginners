#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};


void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node;

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

int Max(Node * ptr)
{
    int m=-34234; 
    while(ptr!=NULL)
    {
        if(ptr->data>m)
        {
            m=ptr->data;
        } 
      ptr=ptr->next;
        
    }

    return m;
}

int Min(Node * ptr)
{
    int m=100000; 
    while(ptr!=NULL)
    {
        if(ptr->data<m)
        {
            m=ptr->data;
        } 
      ptr=ptr->next;
        
    }

    return m;
}

int main()
{
    Node* head = NULL;
 
    push(&head, -10);
    push(&head, 1);
    push(&head, 8);
    push(&head, 6);
    push(&head, 7);
    push(&head, 10);
    push(&head, 15);
    push(&head, 18);
    push(&head, 25);
    push(&head, 50);

    cout<<"Max Element: "<<Max(head)<<endl;

    cout<<"Min Element: "<<Min(head);

    return 0;
}


