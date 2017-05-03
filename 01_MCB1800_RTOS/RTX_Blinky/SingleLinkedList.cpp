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
	NODE *ptrHead = head;
	string str;
	
	// No nodes
	if(head == NULL){
    printf("The list is empty.\n");
		return count;
	}
	
  printf("%d\n", ptrHead->data);
	while(ptrHead->next != NULL){		    
		ptrHead = ptrHead->next;		
    printf("%d\n", ptrHead->data);
	}
	
  
	return count;
}

int List::Append(int data){  
  NODE *ptrHead = head;
	NODE* ptrNewNode = new NODE();
	ptrNewNode->data = data;
	
	if(head == NULL){
		head = ptrNewNode;
    count++;
		return count;
	}
	
	while(ptrHead->next != NULL){		
		ptrHead = ptrHead->next;
	}
	ptrHead->next = ptrNewNode;
  count++;
	return count;	
}

int List::Delete(int data){
	NODE* ptrHead = head;
	NODE* ptrDelete = NULL;
	int initialCount = count;
	
	if(ptrHead == NULL){		
		return -1;			// -1: List is empty.
	}
	
	while(ptrHead->next != NULL){
		if(ptrHead->next->data == data){
			ptrDelete = ptrHead->next;
			ptrHead->next = ptrDelete->next;
			delete ptrDelete;
			--count;
		}
		else{
			ptrHead = ptrHead->next;
		}		
	}
	if(ptrHead->data == data){
		delete ptrHead;
		--count;
	}
	
	if(initialCount == count) return -2;		// -2: No matching node.
	
	return count;
}

void List::Test(void){
	for(int i = 0; i < 4; i++) Append(i);
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




