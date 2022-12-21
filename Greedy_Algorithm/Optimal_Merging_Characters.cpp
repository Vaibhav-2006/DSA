/*Given n number of sorted files, the task is to find the minimum computations done to 
  reach Optimal Merge Pattern. */
//C++ program to implement
//Optimal File Merge Pattern
#include<bits/stdc++.h>
using namespace std;

struct Character
{
  char data; 
  int frequency;
  Character operator+(Character ch2)
  {
  	//temporary characters used for merging two characters do not need data to be intitialized.
    Character temp;
    temp.frequency=this->frequency+ch2.frequency;
    return temp;
  }
};
//Comparator class needed to compare two files
struct Compare {
    bool operator()(Character ch1, Character ch2) {
    	
        return ch1.frequency > ch2.frequency;
    
	}
};
// Function to find minimum computation
int minComputation(int size, struct Character ch[])
{
	//2, 3, 4, 5, 6, 7
	// Create a min heap
	priority_queue<Character, vector<Character>, Compare > pq;

	for(int i = 0; i < size; i++)
	{
		
		// Add sizes to priorityQueue
		pq.push(ch[i]);
	}
	
	// Variable to count total Computation
	int count = 0;

	while(pq.size() > 1)
	{
		
		// pop two smallest size element
		// from the min heap
		Character first_smallest = pq.top();
		pq.pop();
		Character second_smallest = pq.top();
		pq.pop();
		//Add objects using operator overloading
		Character temp = first_smallest + second_smallest;

		// Add the current computations
		// with the previous one's
		count += temp.frequency;

		// Add new combined file size
		// to priority queue or min heap
		pq.push(temp);
	}
	return count;
}

// Driver code
int main()
{
	
	// No of files
	int n = 0;
	
	// 6 files with their sizes
	Character ch[] = { {'A',6}, {'B',5}, {'C',2},{'D',3} };
	n=sizeof(ch)/sizeof(ch[0]);
	// Total no of computations
	// to be done final answer
	cout << "Minimum Computations for optimal merging= "
		<< minComputation(n, ch);

	return 0;
}


