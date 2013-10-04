#include "Node.h"

Node* loopstart(Node* head){
	if(head==NULL){
		return NULL;
	}

	Node* fast = head,*slow=head;

	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) break;
	}
	slow = head;
	while(fast!=slow){
		fast = fast->next;
		slow = slow->next;

	}

	return fast;
}
void main(){
	int n = 12;
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	Node* head = init0(a,n);
	Node* p = head,*q = head;
	int count = 0;
	while(p && p->next){
		p = p->next;
		count++;
		if(count==3){
			q = p;
		}
	}

	p->next = q;

	Node* res = loopstart(head);
	printf("%d\n",res->data);
	print(res);
}