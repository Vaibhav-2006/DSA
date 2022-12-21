//Check this for a couple on inputs
// C++ implementation of De-queue using circular array
#include<iostream>
using namespace std;

// A structure to represent a Deque
class Deque
{
	int *arr;
	int front;
	int rear;
	int size;
public :
	Deque(int size)
	{
		front = 0;
		rear = 0;
		this->size = size;
		arr=new int[size];
	}

	// Operations on Deque:
	void insertfront(int key);
	void insertrear(int key);
	void deletefront();
	void deleterear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();
};

// Checks whether Deque is full or not.
bool Deque::isFull()
{
	return front==(rear+1)%size;// or front==(rear+1)%size
}

// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
	return (front == rear);
}

// Inserts an element at front
void Deque::insertfront(int key)
{
	// check whether Deque if full or not
	if (isFull())
	{
		cout << "Overflow\n" << endl;
		return;
	}
	arr[front] = key;
	// front is at first position of queue
	if (front == 0)
		front = size - 1 ;

	else // decrement front end by '1'
		front = front-1;

	// insert current element into Deque
}

// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
	if (isFull())
	{
		cout << " Overflow\n " << endl;
		return;
	}

	// If queue is initially empty
	if (front == 0)
	{
		front = size-1;
		rear=0;
	}
	//Move rear in a circular fashion
	//When rear= size-1 it is set as 0
	//else it is set as rear+1.. Can be done using two else conditions.
	else
	{
		rear=(rear+1)%size;
	}
	// insert current element into Deque
	arr[rear] = key ;
}

// Deletes element at front end of Deque
void Deque ::deletefront()
{
	// check whether Deque is empty or not
	if (isEmpty())
	{
		cout << "Queue Underflow\n" << endl;
		return ;
	}

	front=(front+1)%size;
}

// Delete element at rear end of Deque
void Deque::deleterear()
{
	if (isEmpty())
	{
		cout << " Underflow\n" << endl ;
		return ;
	}

	if (rear == 0)
		rear = size-1;
	else
		rear = rear-1;
}

// Returns front element of Deque
int Deque::getFront()
{
	// check whether Deque is empty or not
	if (isEmpty())
	{
		cout << " Underflow\n" << endl;
		return -1 ;
	}
	return arr[(front+1)%size];
}

// function return rear element of Deque
int Deque::getRear()
{
	// check whether Deque is empty or not
	if(isEmpty())
	{
		cout << " Underflow\n" << endl;
		return -1 ;
	}
	return arr[rear];
}

// Driver program to test above function
int main()
{//5 10
	Deque dq(5);
	cout << "Insert element at rear end : 5 \n";
	dq.insertrear(5);

	cout << "insert element at rear end : 10 \n";
	dq.insertrear(10);
	
	cout << "get rear element " << " "
		<< dq.getRear() << endl;

	dq.deleterear();
	cout << "After delete rear element new rear"
		<< " become " << dq.getRear() << endl;

	cout << "inserting element at front end \n";
	dq.insertfront(15);

	cout << "get front element " << " "
		<< dq.getFront() << endl;

	dq.deletefront();

	cout << "After delete front element new "
	<< "front become " << dq.getFront() << endl;
	return 0;
}

