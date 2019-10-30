#include <iostream>
#include "cNode.h"

using namespace std;

cNode::cNode() :data(0),priority(0)
{
}

cNode::cNode(int d):data(d), priority(0){
}

cNode::cNode(int d, int p):data(d), priority(p)
{}

int cNode::getData(){
			return data;
		}

cNode* cNode::setData(int data){
        	this->data=data;
		}
		
void cNode::print()const{
			cout<<data<<" ";
		}
int cNode::getPriority()const{
	return priority;
}

void cNode::setPriority(int Prior){
	this->priority=Prior;
}

cNode::~cNode()
{
}
