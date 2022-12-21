// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <bits/stdc++.h>
using namespace std;
//Naive solution is to use linear search and solve in O(N) time.

//Recursive approach which uses system stack.

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
	if (l > h)
		return -1;

	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return mid;

	/* If arr[l...mid] is sorted */
	if (arr[l] <= arr[mid]) {
		/* As this subarray is sorted, we can quickly
		check if key lies in half or other half */
		if (key >= arr[l] && key <= arr[mid])
			return search(arr, l, mid - 1, key);
		/*If key not lies in first half subarray,
		Divide other half into two subarrays,
		such that we can quickly check if key lies
		in other half */
		return search(arr, mid + 1, h, key);
	}

	/* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
	must be sorted subarray */
	if (key >= arr[mid] && key <= arr[h])
		return search(arr, mid + 1, h, key);

	return search(arr, l, mid - 1, key);
}
/*
Time Complexity: O(log n). 
Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
*/

//Best solution using iterative binary search

int Bsearch(int arr[], int n, int key)
{
	int l=0,h=n-1;
	while(l<=h)
	{
	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return mid;
	//At least one half of the array is sorted at a time.
	/* If arr[l...mid] is sorted */
	if (arr[l] <= arr[mid]) 
	{
		/* As this subarray is sorted, we can quickly
		check if key lies in this half or other half */
		if (key >= arr[l] && key < arr[mid])//key cannot be equal to arr[mid] here as this condition is checked above.
			h=mid-1;
		/*If key does not lie in first half subarray*/
		else
			l=mid+1;
	}

	/* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
	must be sorted subarray */
	else 
	{
	if(key > arr[mid] && key <= arr[h])
		l=mid+1;
	else
		h=mid-1;
	}
	}
	return -1;
}
/*
Time Complexity: O(log n). 
Space Complexity: O(1).
*/
// Driver program
int main()
{
	int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 2;
	int i = Bsearch(arr, n , key);

	if (i != -1)
		cout << "Index: " << i << endl;
	else
		cout << "Key not found";
}

