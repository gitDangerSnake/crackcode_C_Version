
//describe how you could use a single array to implement three stacks.

#include<stdio.h>
#include<stdlib.h>

typedef struct ThriStack
{
	/* data */

	int * elems;
	int pSize;
	int top[3];
	int stackId;
}ThriStack;

void init(ThriStack *s,int size){
	//assert(size > 0);
	s->pSize = size;
	s->elems = malloc(s->pSize*3*sizeof(int));
	memset(s->elems,0,s->pSize*3*sizeof(int));
	s->top[0] = s->top[1] = s->top[2]=-0;
	s->stackId = -1;
}

void push(ThriStack *s,int num,int stackid){
	int pos = stackid*s->pSize + s->top[stackid] ;
	s->elems[pos] = num;
	++s->top[stackid];

}

int pop(ThriStack *s,int stackid){
	int res = s->elems[stackid*s->pSize+s->top[stackid]-1];
	--s->top[stackid];
	return res;
}

void main(){
	ThriStack ts;
	init(&ts,200);
	push(&ts,2,1);
	push(&ts,2,2);
	push(&ts,2,0);
	int i;
	for(i=0;i<600;i++){
		printf("%d ",ts.elems[i]);
	}
	putchar('\n');
	int p1 = pop(&ts,1);
	int p2 = pop(&ts,2);
	int p3 = pop(&ts,0);

	printf("%d%d%d",p1,p2,p3);
	putchar('\n');
	for(i=0;i<600;i++){
		printf("%d ",ts.elems[i]);
	}
	putchar('\n');
}

