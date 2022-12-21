// Note that by default C++ creates a max-heap
// for priority queue
// Syntax to create a min heap for priority queue 
//priority_queue <int, vector<int>, greater<int>> g = gq;  
#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int> gq)
{
	priority_queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main()
{
	priority_queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(20);
	gquiz.push(5);
	gquiz.push(1);

	cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top() : " << gquiz.top();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

	return 0;
}
//Priority Queue can also be made using your own min or max heap.
//It can also be done using an array in two ways:
//1)Input operation is O(n) as we input in a sorted place such that the element with highest peiority is at end of array
//so that deletion can be done from end in O(1). If deletion had been done from beginning then shifting of elements
//would have made deletion O(n).
//2)Input at the end of array is O(1) time and delete the element with highest priority after searching through the
//array. Then again do shifting of elements. Deletion is O(n) in this.
//Similarly we can use a linked list such that in 1) we would require sorted insert which is O(n) and deletion would be done
//from front such that it is O(1) in a singly linked list. Or in 2) insertion at end in O(1) time and then searching for
//the max priority element and then deleting it in O(n) time. Remember no shifting is required.
