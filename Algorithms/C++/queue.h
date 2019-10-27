 #include <string>
 #include <cassert>
 #include <iostream>
 using namespace std;

 class Queue {
 private:

  struct Node
    {
	string name; 	//stores name of group
        int people;	//stores position of each group memebers
   	Node *next;
    };

    Node *front;
    Node *rear;
    int count;

    public:
       Queue();
       void enqueue(string, int);
       string dequeue();	//removes queue item 
       bool isEmpty();		//tests if queue is empty
       void clear();		//clears entire queue
       int size(); 		//returns the counter  
       };

   Queue::Queue()
   {                 //Constructor
      front = NULL;
      rear = NULL;
      count = 0;
   }
         		
                
   void Queue::enqueue(string x, int y)
   {  	  // inserts value 
      Node *temp = new Node; //at the rear
      temp->name = x;
      temp->people = y;
      temp->next = NULL;

      if(isEmpty())
      {
         front = temp;
         rear = temp;
      } 

      else
      {
         rear->next = temp;
         rear = temp;
      }

      count++;
   }
  
   string Queue::dequeue()
    {  // removes value at the front teturns it

       assert(!isEmpty());
    
       string groupName;
       int members;

       Node *temp = new Node;
       temp->name = front->name;
       temp->people = front->people;
       front = front->next;

       groupName = temp->name;

       members = temp->people;
       delete temp;

       count--;

       string convert = to_string(members);
       string total = groupName + " " + convert;
       return total;
		}

   bool Queue::isEmpty()
   { // tests if queue is empty using bool
   
      bool flag;

      if(count > 0)
         flag = false;

      else
         flag = true;
	
      return flag;
	}


	int Queue::size()
        { // returns counter 
	   
           return count;
	}
	                	    	    	                                        																						
   void Queue::clear()
   { // clears the queue
			
      string x;
    
      while(!isEmpty())
      {
         x = dequeue();
         cout << x << endl;
      }	
   }

