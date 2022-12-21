// A C++ program for merging overlapping intervals
#include<bits/stdc++.h>
using namespace std;

// An interval has start time and end time
struct Interval
{
	int start, end;
};

// Compares two intervals according to their staring time.
// This is needed for sorting the intervals using library
// function std::sort(). See http://goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
	// Test if the given set has at least one interval
	if (n <= 0)
		return;

	// sort the intervals in increasing order of start time
	sort(arr, arr+n, compareInterval);

	int res=0;//The interval at index 0

	// Start from the next interval and merge if necessary
	for (int i = 1 ; i < n; i++)
	{
		if(arr[res].end>=arr[i].start)
		{
			arr[res].end=max(arr[res].end,arr[i].end);
			arr[res].start=min(arr[res].start,arr[i].start);//redundant statement because of sorting
		}
					//if interval at i does not merge with interval at res then move res to next position and copy that interval 
					//there. Note that since interval at i did not merge with interval at res, the interval i+1 cannot possibly
					//merge with interval at res since :
					//arr[i].start>arr[res].end (did not merge)
				    //arr[i+1].start>=arr[i].start  (non decreasing order sorting)
				    //which implies arr[i+1].start>arr[res].start
		else	
		{		
			res++;
			arr[res]=arr[i];	
		}	   	
	}
	cout << "\n The Merged Intervals are: ";
	for(int i=0;i<=res;i++)
	{
		cout<<"("<<arr[i].start<<" , "<<arr[i].end<<")"<<endl;
	}
	return;
}
//Time complexity: O(N*logN)
// Driver program
int main()
{
	Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} };
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeIntervals(arr, n);
	return 0;
}

