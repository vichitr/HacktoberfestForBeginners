#pragma once
#include"cStack.h"
class cQue:protected cStack{
protected:
	cNode *tail;
public:
	cQue();
	cQue(cNode* &ptr);
	bool isNotEmpty()const;
	bool isEmpty()const;
	cNode* remove();
	cQue& add(cNode* &ptr);
	void print()const;
	cQue(const cQue &src);
	cQue& operator=(const cQue& obj);
	~cQue();
};

