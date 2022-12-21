#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *next;
};

class Queue
{
	private:
	Node *front,*rear; 
	public:
	Queue()
	{
		front = rear = NULL;
	}
	void enqueue(int x);
	int dequeue();
	void Display();
	bool isEmpty();
};
void Queue::enqueue(int x)
{
struct Node *t;
t=(struct Node*)malloc(sizeof(struct Node));
if(t==NULL)
printf("Queue is FUll\n");
else
{
t->data=x;
t->next=NULL;
if(front==NULL)
front=rear=t;
else
{
rear->next=t;
rear=t;
}
}
}
int Queue::dequeue()
{
int x=-1;
struct Node* t;
if(front==NULL)
printf("Queue is Empty\n");
else
{
x=front->data;
t=front;
front=front->next;
free(t);
}
return x;
}
void Queue::Display()
{
struct Node *p=front;
while(p)
{
printf("%d ",p->data);
p=p->next;
}
printf("\n");
}
bool Queue::isEmpty()
{
	return front==NULL;
}
