// A C++ program to find a peak element
//An array element is a peak if it is NOT smaller than its neighbours. 
//For corner elements, we need to consider only one neighbour. 
//NOTE:Array can be unsorted.
#include <bits/stdc++.h>
using namespace std;

//Naive approach
// Find the peak element in the array
int findPeak(int arr[], int n)
{
	// first or last element is peak element
	if (n == 1)
	return 0;
	if (arr[0] >= arr[1])
		return 0;
	if (arr[n - 1] >= arr[n - 2])
		return n - 1;

	// check for every other element
	for (int i = 1; i < n - 1; i++) {

		// check if the neighbors are smaller
		if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
			return i;
	}
}

//Complexity Analysis: 
//
//Time complexity: O(n). 
//One traversal is needed so the time complexity is O(n)
//Space Complexity: O(1). 
//No extra space is needed, so space complexity is constant

//Efficient approach using binary search
//Why binary search can be used to find a peak in an UNSORTED array?
//The fact is that every array has a peak. For example:
//5 20 40 30 20 50 60 
//here mid will be 30 but it is not peak.
//but since 40>=30 we are sure that the peak will be in that part of the array
//in this way we are able to half the size of the array under consideration which is the 
//very nature of binary search.NOTE: A peak might still be present in the other discarded array
//but since we are sure that there will be a peak in the other part we do not consider the discarded array. 
int getAPeak(int arr[], int n)
{
    int low=0, high =n-1;
    while(low<=high)
    {
    	int mid=(low+high)/2;
    	//An element is a peak if either there is nothing on its left or if there is then left element 
		//is smaller than it AND there is nothing on its right or if there is then the right element is smaller
		//than the element itself. 
    	if((mid==0||arr[mid]>=arr[mid-1])&&(mid==n-1||arr[mid]>=arr[mid+1]))
    		return mid;//works even if n=1  
    		
    	if(mid>0&&arr[mid-1]>=arr[mid])
    		high=mid-1;
    		
    	else low=mid+1;
    	
	}
	return -1;//This will never be reached because every array has a peak.
}
//Time complexity: O(logn)

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4, 1, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Index of a peak point is "<< getAPeak(arr, n);
	return 0;
}
