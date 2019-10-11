/*
FIRST IN FIRST OUT
Same Queue Data Structure but with the priority of node elements of Queue
*/
#include<iostream>
#include"nodeClass.cpp"
#include"cStack.cpp"
#include"cQueue.cpp"

using namespace std;

class cPriorityQueue : public cQueue{

public:
    /*
    Default and Parameterized constructor of cPriorityQueue class
    We have used the the parameterized constructor so the system defined NULL constructor doesn't work
    We defined a NULL constructor too
    */
    cPriorityQueue(cStack *&stackRef): cQueue( stackRef ) {}
    cPriorityQueue() {}

    /*
    Add function that inserts nodes at the position in Queue depending upo thier priority
    Higher priority nodes at first
    */
    cPriorityQueue& add( cNode *& nodeRef) {
        if(!topRef) { topRef = tailRef = nodeRef; tailRef->nextNode = nodeRef; nodeRef = NULL; }
        else {
            if(topRef->priority < nodeRef->priority) { cStack::push(nodeRef); }
            else if( tailRef->priority >= nodeRef->priority ) { cQueue:add(nodeRef); }
            else { 
                cNode *rptr , *bptr;
                bptr = rptr = topRef;
                while(rptr->priority >= nodeRef->priority) { bptr= rptr ; rptr = rptr->nextNode; }
                nodeRef->nextNode = rptr;
                bptr->nextNode = nodeRef;
                nodeRef = NULL;
            }
            return *this;
        }
    }  

    /*
    copy consturctor of cPriorityQueue class
    */
    cPriorityQueue ( const cPriorityQueue &src ) {
        this->topRef = src.topRef;
        this->tailRef = src.tailRef;

        if (src.topRef) {
            cNode *sptr, *dptr;
            dptr = topRef = new cNode (*src.topRef);
            sptr = topRef->nextNode;
            
            while(sptr){
                dptr = new cNode (sptr);
                dptr = dptr->nextNode;
                sptr = sptr->nextNode;
            }
            tailRef = dptr;
        }
    }

    /*
    Assignment operator oveltoaded focPriorityQueue Class
    */
    cPriorityQueue& operator = ( const cPriorityQueue &src) {
        if (this == &src) { return *this; }
        if(true) { cPriorityQueue temp; temp.topRef = this->topRef ; temp.tailRef = this->tailRef; }
        if(true) { cPriorityQueue temp; topRef = temp.topRef; tailRef = temp.tailRef; temp.topRef=tailRef=NULL ;}
        return *this;
        //((char*)thia)->operator = ((cQueue&)src);
    }


};
#pragma once