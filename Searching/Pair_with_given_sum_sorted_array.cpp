// A C++ program to find if there is a pair with a given sum in a sorted array.
//If the array is unsorted then we might use these methods:
//1) Naive approach: O(N^2) approach with two for loops
//2) Sorting the array and applying two pointer approach. O(N*logN + N)
//3) Best solution: Using hashing. Time:O(N), Space: O(N) 
#include <bits/stdc++.h>
using namespace std;

//Since array is sorted we can use two pointer approach in this.
//Time Complexity: O(N)
//The two pointer approach never misses a pair in sorted array.
bool isPair( int arr[], int n, int sum)
{
	int left=0, right=n-1;
	while(left<right)
	{
		if(arr[left]+arr[right]==sum)
			return true;
		else if(arr[left]+arr[right]>sum)
			right--;
		else
			left++; 
	}
	return false;//if left becomes equal to right 
//	NOTE: left can never be greater than right as we are moving one pointer at a time.
}

int main()
{
	int arr[]={2,4,8,9,11,12,20,30};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<isPair(arr,n,23);
}
