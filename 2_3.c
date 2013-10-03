//Implement an algorithm to delete a node in the middle of a single linked list,given only access to that node.

#include "Node.h"

void removeAStrangeNode(Node* toBeDeleted){

	if(toBeDeleted == NULL|| toBeDeleted->next == NULL) return ;

	Node* q = toBeDeleted->next;
	
	toBeDeleted->data = q->data;	
	toBeDeleted -> next = q ->next;
	free(q);
	
}

void main(){
	int n = 10;
    	int a[] = { 9, 2, 1, 3, 5, 6, 2, 6, 3, 1  };
    	Node *head = init0(a, n);

    	print(head);
    	Node* c = head;
    	int i;
    	for(i=1; i<4; ++i) c = c->next;
    	removeAStrangeNode(c);
    	print(head);
}