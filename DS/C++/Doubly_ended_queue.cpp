#include <iostream>
#include <cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    node *next;
    node *prev;
 
}*head, *tail;
 
/*
 * Class Declaration
 */
class dqueue
{
    public:
        int top1, top2;
        void insert();
        void del();
        void display();
        dqueue()
        {
            top1 = 0;
            top2 = 0;
            head = NULL;
            tail = NULL;
        }
};
 
/*
 * Main: Contains Menu
 */
int main()
{
    int choice;
    dqueue dl;
    while (1)
    {
        cout<<"\n-------------"<<endl;
        cout<<"Operations on Deque"<<endl;
        cout<<"\n-------------"<<endl;
        cout<<"1.Insert Element into the Deque"<<endl;
        cout<<"2.Delete Element from the Deque"<<endl;
        cout<<"3.Traverse the Deque"<<endl;
        cout<<"4.Quit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 1:
            dl.insert();
            break;
        case 2:
            dl.del();
            break;
        case 3:
            dl.display();
            break;
        case 4:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;    
}
 
/*
 * Insert Element in Doubly Ended Queue
 */
void dqueue::insert()
{
    struct node *temp;
    int ch, value;
    if (top1 + top2 >= 50)
    {
        cout<<"Dequeue Overflow"<<endl;
        return;
    }
    if (top1 + top2 == 0)
    {
        cout<<"Enter the value to be inserted: ";
        cin>>value;
        head = new (struct node);
        head->info = value;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
        top1++;
        cout<<"Element Inserted into empty deque"<<endl; 
    }
    else
    {
        while (1)
        {
            cout<<endl;
            cout<<"1.Insert Element at first"<<endl;
            cout<<"2.Insert Element at last"<<endl;
            cout<<"3.Exit"<<endl;
            cout<<endl;
            cout<<"Enter Your Choice: ";
            cin>>ch;
            cout<<endl;
            switch(ch)
            {
            case 1:
                cout<<"Enter the value to be inserted: ";
                cin>>value;  
                temp = new (struct node);
                temp->info = value;
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
                top1++;
                break;
            case 2:
                cout<<"Enter the value to be inserted: ";
                cin>>value; 
                temp = new (struct node);
                temp->info = value;
                temp->next = NULL;
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
                top2++;
                break;
            case 3:
                return;
                break;
            default:
                cout<<"Wrong Choice"<<endl;
            }
        }
    }
}
 
/*
 * Delete Element in Doubly Ended Queue
 */
void dqueue::del()
{
    if (top1 + top2 <= 0)
    {
        cout<<"Deque Underflow"<<endl;
        return;
    }
    int ch;
    while (1)
    {
        cout<<endl;
        cout<<"1.Delete Element at first"<<endl;
        cout<<"2.Delete Element at last"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:  
            head = head->next;
            head->prev = NULL;
            top1--;
            break;
        case 2:
            tail = tail->prev;
            tail->next = NULL;
            top2--;
            break;
        case 3:
            return;
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
}
 
/*
 * Display Doubly Ended Queue
 */
void dqueue::display()
{
    struct node *temp;
    int ch;
    if (top1 + top2 <= 0)
    {
        cout<<"Deque Underflow"<<endl;
        return;
    }
    while (1)
    {
        cout<<endl;
        cout<<"1.Display Deque from Beginning"<<endl;
        cout<<"2.Display Deque from End"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice: ";
        cin>>ch;
        cout<<endl;
        switch (ch)
        {
        case 1:  
            temp = head;
            cout<<"Deque from Beginning:"<<endl;
            while (temp != NULL)
            {
                cout<<temp->info<<" ";
                temp = temp->next;                       
            }
            cout<<endl;
            break;
        case 2:
            cout<<"Deque from End:"<<endl;
            temp = tail;
            while (temp != NULL)
            {
                cout<<temp->info<<" ";
                temp = temp->prev;                      
            }
            temp = tail;
            cout<<endl;
            break;
        case 3:
            return;
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
}
