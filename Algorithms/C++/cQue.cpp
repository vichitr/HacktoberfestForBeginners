#include <iostream>
#include "cQue.h"

using namespace std;

cQue::cQue():tail(NULL)
{
}

cQue::cQue(cNode* &ptr):cStack(ptr),tail(top){
	}
	
bool cQue::isNotEmpty()const{
	return cStack::isNotEmpty();
	}
	
bool cQue::isEmpty()const{
	return cStack::isEmpty();
	}
	
cNode* cQue::remove(){
		if(!top->next)
		tail=NULL;
		return cStack::pop();
	}
	
cQue& cQue::add(cNode* &ptr){
		if(tail){
			tail->next=ptr;
			tail=tail->next;
		}
		else
		{
			tail=ptr;
			top=ptr;
		}
		tail->next=NULL;
		ptr=NULL;
		return *this;
	}
	
void cQue::print()const{            //
	cStack::print();
	}
	
cQue::cQue(const cQue &src){           ///
		this->top=src.top;
		this->tail=src.tail;
		if(src.top){
			cNode *sptr,*dptr;
			dptr=top=new cNode(*src.top);
			sptr=top->next;
			while(sptr){
				dptr->next=new cNode(*sptr);
				dptr=dptr->next;
				sptr=sptr->next;
			}
			tail=dptr;
		}
	}
	
cQue& cQue::operator=(const cQue& obj){
			if(this==&obj)
			return *this;
			if(true){
				cQue temp;
				temp.top=top;
				temp.tail=tail;
			}
			if(true){
				cQue temp=obj; 
				top=temp.top;
				tail=temp.tail;
				temp.top=NULL;
				temp.tail=NULL;
			}
			return *this;
		}

cQue::~cQue()
{
 cNode *ptr = top;
  
  tail = NULL;

  while (ptr)
   {
     ptr = ptr -> next;
     delete top;
     top = ptr;
   }
}
