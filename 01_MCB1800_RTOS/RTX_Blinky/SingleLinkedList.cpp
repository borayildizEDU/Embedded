/*
Reference: http://www.sourcetricks.com/2008/07/c-singly-linked-lists.html#.WG4Qdn26NCg

*/

#include "SingleLinkedList.h"
#include "EventRecorder.h"
#include <string>
using namespace std;
//extern void EventRecorderPrint(string str);


/*----------------------------------------------------------------------------
 * Node Class
 *----------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------
 * List Class
 *----------------------------------------------------------------------------*/
int List::Print(){
	Node *ptrHead = head;
	string str;
	
	// No nodes
	if(ptrHead == NULL){
		//EventRecorderPrint("The list is empty.");
		return count;
	}
	
	while(ptrHead->next != NULL){		
		//EventRecorderPrint(ptrHead->data);
		ptrHead = ptrHead->next;		
	}
	
	return count;
}

int List::Append(int data){
	Node* ptrHead = head;
	// Create a new node
	Node* ptrNewNode = new Node();
	ptrNewNode->SetData(data);
	
	if(ptrHead == NULL){
		ptrHead = ptrNewNode;
		count++;
		return ++count;
	}
	
	while(ptrHead->next != NULL){		
		ptrHead = ptrHead->next;
	}
	ptrHead->next = ptrNewNode;
	return ++count;	
}

int List::Delete(int data){
	Node* ptrHead = head;
	Node* ptrDelete = NULL;
	int initialCount = count;
	
	if(ptrHead == NULL){		
		return -1;			// -1: List is empty.
	}
	
	while(ptrHead->next != NULL){
		if(ptrHead->next->GetData() == data){
			ptrDelete = ptrHead->next;
			ptrHead->next = ptrDelete->next;
			delete ptrDelete;
			--count;
		}
		else{
			ptrHead = ptrHead->next;
		}		
	}
	if(ptrHead->GetData() == data){
		delete ptrHead;
		--count;
	}
	
	if(initialCount == count) return -2;		// -2: No matching node.
	
	return count;
}

void List::Test(void){
	for(int i = 0; i < 4; i++) Append(1);
	Print();
	Delete(1);
	Print();
	Delete(0);
	Print();
	Delete(2);
	Print();
	Delete(3);
	Print();
	Delete(0);
	Print();	
}




