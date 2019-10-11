#include<iostream>
#include"nodeClass.cpp"
#include"cQueue.cpp"

using namespace std;

int main() {
	cQueue que;
	que.printQueue();

	// Declaring node pointers Array and declaring dynamic nodes 
	cNode *n[5];
	n[0] = new cNode(10);
	n[1] = new cNode(20);
	n[2] = new cNode(30);
	n[3] = new cNode(40);
	n[4] = new cNode(50);

	// Adding 5 nodes to queue in a seuence from n[1-1] to n[5-1]
	// The nodes are added as first node added first.
	for (int i = 0; i < 5; i++)
	{
		que.add(n[i]);
	}
	que.printQueue();

	// Now retriving the nodes back from the queue 
	// They are retrived in an order "The first Entered will be retrived first"
	for (int i = 0; i < 5; i++) {
		cNode *temp;
		temp = que.remove();
		cout << "The retrieved node elelemt is " << temp->getData()<<endl;
		que.printQueue();
		cout << endl;
		delete temp;
	}

	/*
	This example clearly describes the basic working of a basic Queue Data Strusture
	*/
	system("pause");
	return 0;
	

}
