//write code to remove duplicates from an unsorted linkded list


//what if addtional buffer is not allowed?

#include 'Node.h'


//O(n^2)
void removeDuplicateWithoutAddtionalBuffer(Node *head){
	if(head == NULL) return;
	Node *p ,*q,*c;
	c = head;
	while(c){
		p = c,q=c->next;
		while(q){
			if(q->data == c->data){
				Node *tmp = q;
				p->next = q->next;
				q=p->next;
				free(tmp);
			}else{
				p = q;
				q = q->next;
				//p = p->next;
			}

		}
		c = c->next;
	}
}

void main(){
	int n = 10;
	int a[] = {3,2,1,3,5,6,2,6,3,1};

	Node *head = init0(a,n);
	print(head);
	printf("\n");
	removeDuplicateWithoutAddtionalBuffer(head);
	print(head);
	printf("\n");
	destroy(head);

}
















