//how would you desigin a stack which ,in addition to push and pop , also has a function min which returns the minimum element? push . pop and min should all operate in O(1) time.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int val,min;
}Node;

typedef struct minStack
{
	Node* nodes;
	int max_len;
	int top;

}minStack;

void init(minStack *s){
	s->max_len = 10;
	s->nodes = malloc(s->max_len*sizeof(Node));
	s->top = 0;
}

static void resize(minStack *s){
	s->max_len*= 2;
	s->nodes = realloc(s->nodes,s->max_len*sizeof(Node));
	//assert(s->nodes);
}

void push(minStack *s, int val){
	
	if(s->top == s->max_len){
		resize(s);
	}	
	s->nodes[s->top] .val = val;
	int tmp = s->nodes[s->top-1].min;
	if(val >= tmp) s->nodes[s->top].min = tmp;
	else s->nodes[s->top].min = val;
	s->top++;
	
} 


int pop(minStack *s){
	int res = s->nodes[--s->top].val;
	return res;
}

int min(minStack *s){
	int min = s->nodes[s->top-1].min;
	return min;
}

void main(){
	minStack *ms;
	init(ms);
	push(ms,10);
	push(ms,20);
	push(ms,30);
	push(ms,5);
	push(ms,40);

	int m = min(ms);
	int p1 = pop(ms);
	int p2 = pop(ms);
	int p3 = pop(ms);
	m = min(ms);
	printf("%d %d %d %d\n",m,p1,p2,p3 );



}