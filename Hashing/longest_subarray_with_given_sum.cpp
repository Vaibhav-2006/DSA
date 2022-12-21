// C++ implementation to find the length
// of longest subarray having sum k
#include <bits/stdc++.h>
using namespace std;

//Naive Approach: Consider the sum of all the sub-arrays and return the length of the longest sub-array 
//having sum ‘k’. Time Complexity is of O(n^2).
int maxlen( int arr[], int n, int sum)
{
	int len=0;
	for(int i=0;i<n;i++)
	{
		int curr_sum=0;
		for(int j=i;j<n;j++)
		{
			curr_sum+=arr[j];
			if(curr_sum==sum)
			len=max(len,j-i+1);// finding max length of subarray equal to sum
		}
	}
	return len;
}
//Time complexity: O(N^2)
//Space complexity: O(1)

//Efficient approach

// function to find the length of longest
// subarray having sum k
int lenOfLongSubarr(int arr[],int n,int k)
{

	// unordered_map 'um' implemented
	// as hash table
	unordered_map<int, int> um;
	int sum = 0, maxLen = 0;

	// traverse the given array
	for (int i = 0; i < n; i++) {

		// accumulate sum
		sum += arr[i];

		// when subarray starts from index '0'(edge case). 1 2 3 4 5 6.. sum is 6 then longest subarray is 1+2+3
		//1 2 3 -4 2 2 6...sum= 6 Here longest subarray is 1 2 3 -4 2 2
		if (sum == k)
			maxLen = i + 1;

		// make an entry for 'sum' if it is
		// not present in 'um'.. Explanation: arr[ 8,3,1,5,-6,6,2,2] sum 4
		// so prefix sums are 8 11 12 17 11 17 19 21
		//so while inserting in map there are two 17's or two 11's meaning that the subarray between the two
		//17's or 11's is 0. So to form the longest subarray we only include the earliest occursence of 17 and
		//11 because the later occrrences will never form the longest subarray. Note that we cannot possibly
		// include both the occurrences as duplicate keys( 17 for example) will be mapped onto the same
		//location in the hashmap and the later occurrence will overwrite the value(index) of 
		//the earlier occurence and this will give wrong ans. 
		if (um.find(sum) == um.end())
			um[sum] = i;
		//Also note if prefix sums are 8 11 12 17 11 17 19 21 25 21 
		//In this case later occurrence of 21 is not added to the map but it is used to calculate the 
		//longest subarray with sum 4
		// check if 'sum-k' is present in 'um'
		// or not
		if (um.find(sum - k) != um.end()) {
			if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
		}
	}

	// required maximum length
	return maxLen;
}

// Driver Code
int main()
{
	int arr[] = {8,3,1,5,-6,6,2,2,4,-4};//In this the longest subarray is 1 2 3 -4 2 2 0
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	cout << "Length = "
		<< lenOfLongSubarr(arr, n, k);
	return 0;
}

