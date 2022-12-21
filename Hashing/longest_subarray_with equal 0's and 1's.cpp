// C++ program to find largest subarray with equal number of
// 0's and 1's.
#include<bits/stdc++.h>
using namespace std;
//Naive approach
int longestSub(int arr[], int n)
{
	int res=0;
	for(int i=0; i<n; i++)
	{
		int c0=0, c1=0;
		for(int j=i;j<n;j++)
		{
			if(arr[j]==0)
			c0++;
			else
			c1++;
			
			if(c0==c1)
			res=max(res,j-i+1);//can also use 2*c0
		}
	}
	return res;
}
//Time complexity: O(N^2)
//Space complexity: O(1)

//Efficient approach
/*
Method 2: Hashmap.
Make this problem same as longest subarray with given sum=0.
Approach: The concept of taking prefix sum, taking 0’s as -1 will help us in optimizing the approach. 
While taking the cumulative sum, there are two cases when there can be a sub-array with 
equal number of 0’s and 1’s. 

1)When prefix sum=0, which signifies that sub-array from index (0) till present index has equal number 
of 0’s and 1’s. Recall that this is an edge case in longest subarray with given sum=0.

When we encounter a prefix sum value which we have already encountered before, which means 
that sub-array from the previous occurrence till the present occurence has equal number of 0’s and 1’s
as they give a sum of 0 because 0's are taken as -1.*/

int lenOfLongSubarr(int arr[],int n)
{
	//firts change all 0's to -1
	for(int i=0; i<n; i++)
	if(arr[i]==0)
		arr[i]=-1;
	// unordered_map 'um' implemented
	// as hash table
	unordered_map<int, int> um;
	int sum = 0, maxLen = 0;

	// traverse the given array
	for (int i = 0; i < n; i++) {

		// accumulate sum
		sum += arr[i];

		// when subarray starts from index '0'(edge case).
		if (sum == 0)
			maxLen = i + 1;

		// make an entry for 'sum' if it is
		// not present in 'um'.. 
		if (um.find(sum) == um.end())
			um[sum] = i;
	
		// check if 'sum' is present in 'um'
		// or not
		if (um.find(sum) != um.end()) {
			if (maxLen < (i - um[sum]))
                maxLen = i - um[sum];
		}
	}

	// required maximum length
	return maxLen;
}
/*
Time Complexity: O(n). 
As the given array is traversed only once.
Auxiliary Space: O(n). 
As hash_map has been used which takes extra space.
*/
int main()
{
    int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
 
    cout<<lenOfLongSubarr(arr, size);
    return 0;
}
