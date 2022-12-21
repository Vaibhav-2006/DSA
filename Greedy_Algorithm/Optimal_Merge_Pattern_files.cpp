/*Given n number of sorted files, the task is to find the minimum computations done to 
  reach Optimal Merge Pattern. */
//C++ program to implement
//Optimal File Merge Pattern
#include<bits/stdc++.h>
using namespace std;

struct file
{
  int file_weight;
  file operator+(file file2)
  {
    file temp;
    temp.file_weight=this->file_weight+file2.file_weight;
    return temp;
  }
};
//Comparator class needed to compare two files
struct Compare {
    bool operator()(file file1, file file2) {
    	
        return file1.file_weight > file2.file_weight;
    
	}
};
// Function to find minimum computation
int minComputation(int size, struct file files[])
{
	//2, 3, 4, 5, 6, 7
	// Create a min heap
	priority_queue<file, vector<file>, Compare > pq;

	for(int i = 0; i < size; i++)
	{
		
		// Add sizes to priorityQueue
		pq.push(files[i]);
	}
	
	// Variable to count total Computation
	int count = 0;

	while(pq.size() > 1)
	{
		
		// pop two smallest size element
		// from the min heap
		file first_smallest = pq.top();
		pq.pop();
		file second_smallest = pq.top();
		pq.pop();
		//Add objects using operator overloading
		file temp = first_smallest + second_smallest;

		// Add the current computations
		// with the previous one's
		count += temp.file_weight;

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
	int n = 6;
	
	// 6 files with their sizes
	struct file f[] = { 2, 3, 4, 5, 6, 7 };
	
	// Total no of computations
	// to be done final answer
	cout << "Minimum Computations for optimal merging= "
		<< minComputation(n, f);

	return 0;
}


