/*
	You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
	eg. 		(3 –> 1 –> 5), (5 –> 9 –> 2)
	output.		8 –> 0 –> 8
*/

#include "Node.h"

Node * listAdd(Node* head1,Node* head2){	
	if(head1 == NULL ) return head2;
	if(head2 == NULL) return head1;
	Node* res,*pre=NULL,*p=head1,*q=head2;
	int flag = 0;
	while(q && p){
		int t = q->data + p->data+flag;
		Node* tmp = (Node*)malloc(sizeof(Node));
		tmp->data = t%10;
		if(pre){
			pre->next = tmp;
			pre = tmp;
		}else{
			pre = res = tmp;
		}
		flag = t/10;
		p = p->next;
		q=q->next;
	}

	while(p){
		int t = flag + p->data;
		Node* tmp = (Node*)malloc(sizeof(Node));
		tmp->data = t%10;
		pre->next = tmp;
		pre = tmp;
		flag = t/10;
		p=p->next;
	}

	while(q){
		int t = flag + q->data;
		Node* tmp = (Node*)malloc(sizeof(Node));
		tmp->data = t%10;
		pre->next = tmp;
		pre = tmp;
		flag = t/10;
		q=q->next;
	}

	if(flag){
		Node* tmp = (Node*)malloc(sizeof(Node));
		tmp->data = flag;
		pre->next = tmp;
		pre = tmp;
	}
	pre->next = NULL;
	return res;

}

void main(){
	int n = 4;
    	int a[] = {1, 2, 9, 3 };
    	int m = 3;
    	int b[] = { 9, 9, 2 };

    	Node* head1 = init0(a,n);
    	Node* head2 = init0(b,m);

    	Node* res = listAdd(head1,head2);
    	print(res);

    	destroy(head1);
    	destroy(head2);
    	destroy(res);
}