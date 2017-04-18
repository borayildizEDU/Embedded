#pragma once

// Node class
class Node{
	int data;
	
	public:
		Node* next;
		Node(){};
		void 	SetData(int Data) {data = Data;};
		int 	GetData() {return data;};		
};

// List class
class List{
	Node *head;
	int count;
	
	public:
		List() {head = nullptr; count = 0;};
		int Print();							// returns count
		int Append(int data);			// returns count
		int Delete(int data);	    // returns -2: No matching node, -1: List is empty, >-1: count
		void Test(void);					
};
