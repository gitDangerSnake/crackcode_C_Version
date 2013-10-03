
#include<stdio.h>
#include<stddef.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

//user define values stored in the linked list
Node* init0(int a[],int n){
	Node *head, *p;
	int i;
	for(i=0;i<n;i++){
		Node *nd = (Node*) malloc(sizeof(Node));
		nd->data = a[i];

		if(i==0){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	p->next = NULL;
	return head;
}

// the linked list init with default values . i.e 0,1,2,3,4,5....

Node* init1(int n){
	Node *head, *p;
	int i;
	for(i=0;i<n;i++){
		Node *nd = (Node*) malloc(sizeof(Node));
		nd->data = i;

		if(i==0){
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	p->next=NULL;
	return head;
}

//insert a node 



// print the Linked list
void print(Node* head){
	Node *p = head;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}

	putchar('\n');
}

//destory the linked list
void destroy(Node* head){
	Node *p = head,*q = head;
	while(p){
		p=p->next;
		free(q);
		q = p;
	}
}