//Queue using two stacks
#include "C:\Users\vaibh\OneDrive\Desktop\Ds_Udemy_ABdul_Bari\Stacks\Stack_header.h"
#include<iostream>
using namespace std;

class Queue
{
	private:
		Stack s1;
		Stack s2;
	public:
		void enqueue(int x);
		int dequeue();		
};

void Queue::enqueue(int x)
{//if Stack is implemented using array then you have to check if the stack is full
	s1.push(x);
}
int Queue::dequeue(){
	if(s2.isEmpty())
	{
		if(s1.isEmpty())
		{
			cout<<"Queue is empty";
			return -1;
		}
		else while(!s1.isEmpty())
				s2.push(s1.pop());	
	}
	return s2.pop();
}

int main()
{
	int x;
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	x=q.dequeue();
	if(x!=-1)
	cout<<x<<endl;
}
