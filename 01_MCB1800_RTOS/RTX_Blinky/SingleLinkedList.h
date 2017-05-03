#pragma once


typedef struct node_t{
  int data;
  node_t *next;
}NODE;


// List class
class List{
	NODE *head;
	int count;
	
	public:
		List() {head = nullptr; count = 0;};
		int Print();							// returns count
		int Append(int data);			// returns count
		int Delete(int data);	    // returns -2: No matching node, -1: List is empty, >-1: count
		void Test(void);					
};
