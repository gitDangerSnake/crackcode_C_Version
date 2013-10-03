// Implement an algorithm to find the nth to the last element of a singly linked list

#include "Node.h"



Node* findnthToTheLast(Node* head,int n){
	if(head==NULL) return NULL;
	if(n < 1) return NULL;

	Node *q,*p;
	q=p=head;

	while(n>0 && q){
		q = q->next;
		n--;
	}

	if(n>0) return NULL;

	while(q){
		q = q->next;
		p=p->next;
	}
	return p;
	

}

void main(){
	int n = 10;
	int a[] = {3,2,1,3,5,6,2,6,3,1};

	Node *head = init0(a,n);
	Node *found = findnthToTheLast(head,3);

	printf("%d\n",found->data );

}