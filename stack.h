#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Stack
{
	void *elems;
	int elemSize;
	int length;
	int top;

} Stack;

void init(Stack *s, int elemSize);

void destroy(Stack *s);

void push(Stack *s, void *elemAddr);

void pop(Stack *s , void *elemAddr);


void init(Stack *s,int elemSize){
	assert(elemSize > 0);
	s->length = 4;
	s->top = 0;
	s->elemSize = elemSize;
	s->elems = malloc(4*elemSize);
	assert(s->elems!=NULL);
}

void destroy(Stack *s){

	free(s->elems);
}

//can only used in this file , not allowed in other files
static void resize(Stack *s){
	s->length *= 2;
	s->elems = realloc(s->elems,s->length*s->elemSize);
	assert(s->elems);
}

int push(Stack *s, void *elemAddr){
	if(s->length == s->top){
		resize(s);
	}
	void *target = (char*)elemSize + s->top*s->elemSize;

	memcpy(target,elemAddr,s->elemSize);

	s->top++;

	return 1;
}

void pop(Stack *s, void *elemAddr){
	void *source = (char*)s->elems + (s->top-1)*s->elemSize;
	memcpy(elemAddr,source,s->elemSize);
	s->top--;
}