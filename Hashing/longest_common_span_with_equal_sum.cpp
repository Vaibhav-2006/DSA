//Given two binary arrays, arr1[] and arr2[] of the same size n. Find the length of the longest common span
//(i, j) where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j].

/*Input: arr1[] = {0, 1, 0, 0, 0, 0};
       arr2[] = {1, 0, 1, 0, 0, 1};
Output: 4
The longest span with same sum is from index 1 to 4.

Input: arr1[] = {0, 1, 0, 1, 1, 1, 1};
       arr2[] = {1, 1, 1, 1, 1, 0, 1};
Output: 6
The longest span with same sum is from index 1 to 6.

Input: arr1[] = {0, 0, 0};
       arr2[] = {1, 1, 1};
Output: 0

Input: arr1[] = {0, 0, 1, 0};
       arr2[] = {1, 1, 1, 1};
Output: 1 */

// A Simple C++ program to find longest common
// subarray of two binary arrays with same sum
#include<bits/stdc++.h>
using namespace std;

//Naive approach
// Returns length of the longest common subarray
// with same sum
int LongestCommonSum(bool arr1[], bool arr2[], int n)
{
	// Initialize result
	int maxlen = 0;

	// One by one pick all possible starting points
	// of subarrays
	for (int i=0; i<n; i++)
	{
	// Initialize sums of current subarrays
	int sum1 = 0, sum2 = 0;

	// Consider all points for starting with arr[i]
	for (int j=i; j<n; j++)
	{
		// Update sums
		sum1 += arr1[j];
		sum2 += arr2[j];

		// If sums are same and current length is
		// more than maxLen, update maxLen
		if (sum1 == sum2)
		{
			int len = j-i+1;
			maxlen=max(maxlen,len);
		}
	}
	}
	return maxlen;
}
/*
Time Complexity : O(n2) 
Auxiliary Space : O(1)
*/

//Efficient approach
//This problem is very similar to longest subarray with 0 sum problem. It just involves a small trick.
//Find difference array arr[] such that arr[i] = arr1[i] – arr2[i] as the longest common span will have equal
//sum, which means if 0 in arr1 is subtracted from 0 in arr2 then result does not change. Similarly if
//1's are subtracted from each other then result remains same. Also the number of remaining 1's will be same
//as we are finding the longest span with EQUAL sum in both arrays. So 1 in arr1 subtracted from 0 in arr2
//will result in 1 but you have to keep in mind that since the sums of longest spans are equal meaning there
//are equal 1's and now since there has been a 1 in arr1 corresponding to a 0 in arr2, THERE HAS TO BE a
//1 in arr2 for which there will be a 0 in arr1 and this will result in -1. So altogether we need to find
//the longest subarray with 0 sum in arr.
//arr1[] = {0, 1, 0, 1, 1, 1, 1}
//arr2[] = {1, 1, 1, 1, 1, 0, 1}
//arr[] = {-1, 0,-1, 0, 0, 1, 0} 
//Checkout arr from index 1 to 6. It has equal number of -1 and 1 resulting in 0 sum. 
int longestCommonSum(bool arr1[], bool arr2[], int n)
{
    // Find difference between the two
    int arr[n];
    for (int i=0; i<n; i++)
      arr[i] = arr1[i] - arr2[i];
      
      
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
		
		else {//if (um.find(sum) != um.end())
			int len = i-um[sum];
			maxLen=max(maxLen,len);
		}
	}

	// required maximum length
	return maxLen;
}

/*
Time Complexity: O(n) 
Auxiliary Space: O(n) for aux array arr and hashmap.  
*/
// Driver program to test above function
int main()
{
	bool arr1[] = {0, 1, 0, 1, 1, 1, 1};
	bool arr2[] = {1, 1, 1, 1, 1, 0, 1};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	cout << "Length of the longest common span with same "
			"sum is "<< longestCommonSum(arr1, arr2, n);
	return 0;
}


