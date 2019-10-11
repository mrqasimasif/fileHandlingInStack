/*
FIRST IN FIRST OUT
The topRef is always pointing to the HEAD element of the Queue
The tailRef will be pointing to the last node element of the Queue
*/
#include<iostream>
#include"nodeClass.cpp"
#include"cStack.cpp"
using namespace std;

class cQueue : protected cStack {
protected:
	// The trailing tail pointer to keep look at the last node of the Queue
	cNode *tailRef;
public:
	//Default and Parameterized constructor
	cQueue() : tailRef(NULL) {}
	cQueue(cStack *&stackRef) : cStack(*stackRef), tailRef(topRef) {}

	//cQueue Class copy constructor
	cQueue(const cQueue &src) {
		this->topRef = src.topRef;
		this->tailRef = src.tailRef;

		if (src.topRef) {
			cNode *sptr, *dptr;
			dptr = this->topRef = new cNode(*src.topRef);
			sptr = topRef->nextNode;

			while (sptr) {
				dptr = new cNode(*sptr);
				dptr = dptr->nextNode;
				sptr = sptr->nextNode;
			}
			tailRef = dptr;
		}
	}

	/*
	Retrives node element at the top of the Queue
	As only the first element is to be retrieved from the Queue
	so the pop function of stack can can work
	*/
	cNode* remove() { return cStack::pop(); }

	/*
	Add node element at last of the Queue
	To accomplish First In First Out
	*/
	cQueue& add(cNode *&nodeRef) {
		if (tailRef)
		{
			tailRef->nextNode = nodeRef;
			tailRef = tailRef->nextNode;
		}
		else
		{
			tailRef = topRef = nodeRef;
		}
		tailRef->nextNode = NULL;
		nodeRef = NULL;
		
		return *this;
	}

	/*
	Ptinting the Queue from Top to Bottom
	Just elements form Queue are printed in an arranged manner
	printStack function of cStack class can work well
	*/
	void printQueue() { cStack::printStack(); }

	/*
	THe overloaded Assignment operator
	Cascaded assignments also enabled by returning reference
	*/
	cQueue& operator = (const cQueue &src) {
		if (this == &src) { return *this; }
		if (true) { cQueue temp; temp.topRef = topRef; temp.tailRef = tailRef; }
		if (true) {
			cQueue temp = src; topRef = temp.topRef; tailRef = temp.tailRef; temp.topRef = temp.topRef = NULL;
		}
		return *this;
	}

	/*
	Destructor of stack class is called implicitely and work fine
	No need to redefne the destructor
	*/

};
#pragma once