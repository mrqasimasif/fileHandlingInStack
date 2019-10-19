#include<iostream>
#include<fstream>
#include"nodeClass.cpp"
#include"cStack.cpp"


using namespace std;

int main() {
	cStack stack;
	stack.printStack();

	// Declaring node pointers Array and declaring dynamic nodes 
	cNode *n[3];
	n[0] = new cNode(10);
	n[1] = new cNode(20);
	n[2] = new cNode(30);

	// Adding 5 nodes to queue in a seuence from n[1-1] to n[3-1]
	// The nodes are added as first node added first.
	for (int i = 0; i < 3; i++)
	{
		stack.push(n[i]);
		delete n[i];
	}

	stack.printStack();
	//Opeing file for write operation
	ofstream outFile;
	outFile.open("G:/uniBooksAndAssignments/3rdSemester/assignments/dsaTheory/fileHandlingInQueue/data.bin");
	
	if (outFile.is_open()) {
		cout << "\nStarted writing to file !" << endl;
		stack.writeStackToFile(outFile);
		cout << "Done writing to file !" << endl;
	}
	else {
		cout << "File not opened for writing !" << endl;
	}
	
	outFile.close();
	/*
	This example clearly describes the basic working of a basic Stack Data Strusture
	*/

	ifstream inFile;
	inFile.open("G:/uniBooksAndAssignments/3rdSemester/assignments/dsaTheory/fileHandlingInQueue/data.bin");
	cStack stack1;

	if (inFile.is_open()) {
		cout << "\nReading data of Stack1 from file data.bin !" << endl;
		stack1.readFromFile(inFile);
		cout << "Done Reading from file !\n";
	}
	else {
		cout << "The file is not opened for the Read operation !" << endl;
	}

	cout << "Printing stack object Read from file" << endl;
	stack1.printStack();

	inFile.close();


	system("pause");
	return 0;


}
