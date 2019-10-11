/*
Self Referential Node Class decleration and definition that are going to serve as our basic building blocks 
for all other data structures
*/
#include<iostream>
#include<fstream>
using namespace std;

class cNode {
	//Data carrier of cNode objetct and operator carrier
	int data;
public:
	//Reference to next cNode Object
	cNode* nextNode;

	//Priority element of each node element
	int priority;

	//Using this pointer to refer to the same class object
	//Basic Class Constructors / Overlaoded constructors
	cNode() { this->data = -1; }
	cNode(int number) { this->data = number; }

    //Class constructor for imput from File
    cNode(ifstream &inFile) { inFile.read((char*)this, sizeof(*this)); }

    //Member function for input from File
    cNode readFromFile(ifstream &inFile) { inFile.read((char*)this, sizeof(*this)); }

    //Memeber function for wrirting output to File
    cNode writeToFile(ofstream &oFile) { oFile.write((char*)this, sizeof(*this)); }
    
	//Class Getter
	int getData() { return data; }

	//Class Setter
	void setData(int number) { this->data = number; }

	//Printing the value of data carrier
	void printData() { cout << data; }

};
#pragma once
