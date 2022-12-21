
#ifndef Stack_c
#define Stack_c
#include<stdio.h>
#include<stdlib.h>
struct Stack
{
	int size;
	int top;
	struct Node* *stack;
};
void Create_Stack(struct Stack* stck,int size)
	{
		stck->size=size;
		stck->top=-1;
		stck->stack=(struct Node**) malloc(stck->size*sizeof(struct Node*));
	}
	void push(struct Stack* stck,struct Node* ptr)
	{
		if(stck->top<stck->size-1)
		stck->stack[++stck->top]=ptr;
		else 
		printf("Stack is full");
	}
	struct Node* pop(struct Stack *stck)
	{
		if(stck->top>-1)
		{
		return stck->stack[stck->top--];
	}
	else {
		printf("Underflow");
		return NULL;
	}
	}
		bool isEmpty_Stack(struct Stack stck)
	{
		return stck.top==-1;
	}
		struct Node* top(struct Stack *stck)
	{
		if(!isEmpty_Stack(*stck))
		{
		return stck->stack[stck->top];
	}
	else {
		printf("Underflow");
		return NULL;
	}
	}
#endif

