/*
LAST IN FIRST OUT
The nextNode reference of the last node is always null to avoid GARBAGE ACCESS
*/
#include<iostream>
#include"nodeClass.cpp"
using namespace std;

class cStack {
	//The dynamic memory location that is going to serve as the BASE REFERENCE to the whole STACK
protected:
	cNode *topRef;
	int count;
public:
	/*
	Default Class Construstor
	Using Initializer list to set the topReference as NULL for the empty STACK
	*/
	cStack() : topRef(NULL) { count = 0; }

	/*
	Parameterized Class Constructor
	Generating a single node stack using pointer Reference to avoid multiple pointer to same node
	*/
	cStack(cNode *&topPtr) : topRef(topPtr) { topRef->nextNode = NULL; topRef = NULL; count = 1; }

	//cStack constructor to input nodes from file 
	cStack(ifstream &inFile) : topRef(NULL), count(0) {
		int size;
		inFile.read((char*)this, sizeof(*this));
		if (size > 0) {
			cNode *rptr;
			rptr = topRef = new cNode(inFile);
			count = size;
			for (int i = 0; i < count; ++i) {
				rptr->nextNode = new cNode(inFile);
				rptr = rptr->nextNode;
			}
			rptr->nextNode = NULL;
		}
	}

	//Member function to write cStack nodes to file
	void writeStackToFile(ofstream &oFile) {
		if (!(oFile.is_open())) {
			cout << "File is not opened !" << endl;
		}
		else {
			oFile.write((char*)&count, sizeof(count));

			if (count > 0) {
				cNode *rptr = topRef;
				for (int i = 0; i < count; ++i) {
					rptr->writeNodeToFile(oFile);
					rptr = rptr->nextNode;
				}
			}
		}
	}

	//Member function to read input nodes from file
	void readFromFile(ifstream &inFile) {

		if (true) {
			cStack temp;
			temp.topRef = this->topRef;
		}

		inFile.read((char*)&count, sizeof(count));
		cout << "count = " << count << endl;

		if (count > 0) {
			cNode *nodeRef;
			nodeRef = topRef = new cNode(inFile);
			
			for (int i = 1; i < count; ++i) {
				nodeRef->nextNode = new cNode(inFile);
				nodeRef = nodeRef->nextNode;
			}
			nodeRef->nextNode = NULL;
		}
	}

	/*
	Check the BASE REFERENCE to determin whether the STACK is empty or not
	*/
	bool isNotEmpty() const { if (topRef) return true; else return false; }
	bool isEmpty() const { if (topRef) return false; else return true; }

	/*
	Push a node at the end of the STACK using previousLastNode Next Reference to New node
	Returning Reference will allow cascadeability use
	*/
	cStack& push(cNode *&nodeRef) { nodeRef->nextNode = topRef; topRef = nodeRef; nodeRef = NULL; ++count; return *this; }

	//To extract the first node element of the STACK
	cNode* pop() { cNode *nodeRef = topRef; topRef = topRef->nextNode; nodeRef->nextNode = NULL; --count; return nodeRef; }

	//print function to print the whole stack from top to bottom order
	void printStack() const {
		if (!topRef)
			cout << "\nEMPTY DATA STRUCTURE\n";
		else {
			cout << "The elements from TOP to BOTTOM are \n";
			cNode *nodeRef = topRef;
			//print all elements until last node NULL reference is reached
			while (nodeRef) {
				nodeRef->printData();
				cout << "\n";
				nodeRef = nodeRef->nextNode;
			}
		}
	}

	/*
	The default copy constructor gives shallow copy so default constructor is redefined
	Two tracing pointers "sptr(source pointer) , dptr(destination pointer)" are used for assistance
	*/
	cStack(const cStack &src) {
		this->topRef = src.topRef;
		this->count = src.count;
		if (src.topRef) {
			cNode *sptr, *dptr;
			dptr = topRef = new cNode(*src.topRef);
			sptr = src.topRef->nextNode;
			while (sptr) {
				dptr = new cNode(*sptr);
				sptr = sptr->nextNode;
				dptr = dptr->nextNode;
			}
		}
	}

	/*
	Defining the assignment operator for the cStack class
	*/
	cStack& operator = (const cStack &src) {
		if (this == &src) { return *this; }
		if (true) { cStack temp; temp.topRef = this->topRef; }
		if (true) { cStack temp = src; topRef = temp.topRef; temp.topRef = NULL; }
		return *this;
	}


	/*
	Default destructor wouldn't delete the stack allocated on HEAP so the self defined deletes all nodes in STACK
	*/
	~cStack() {
		cNode *nodeRef = topRef;
		while (nodeRef) {
			nodeRef = nodeRef->nextNode;
			delete topRef;
			topRef = nodeRef;
		}
	}

};
#pragma once
