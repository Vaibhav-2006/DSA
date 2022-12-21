//Stack using two queues
#include "C:\Users\vaibh\OneDrive\Desktop\Ds_Udemy_ABdul_Bari\Queue\Queue_linked_cpp_header.h"
#include <iostream>
using namespace std;
  
class Stack {
    Queue q1, q2;
  
public:
  
    void push(int x)
    {//push all elements in q1. Last element is at rear. It should actually be the
    //top of stack but here we are using queues.
        q1.enqueue(x);
    }
  	
  	int pop()//Actually the return type depends on the element we are popping
    {
    	int x=-1;
        if (q1.isEmpty())
        {
        	cout<<"Stack is empty!\n";
        	return -1;
		}

        // Leave one element in q1 and
        // push others in q2.
        while (!q1.isEmpty()) 
		{
        	x=q1.dequeue();
        	if(!q1.isEmpty())
            q2.enqueue(x);
        }
  		//The value of x now is the element that should have been popped from stack
  		//We should stop it from getting added to rear of q2.
  		
        // swap the names of two queues
        Queue q3 = q1;
        q1 = q2;
        q2 = q3;
        return x;
    }
};
  
// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
  
    cout<<s.pop()<<endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}

