// Simple C++ program to find k'th smallest element
#include <algorithm>
#include <iostream>
using namespace std;
//Naive approach:
/*
A simple solution is to sort the given array using a O(N log N) sorting algorithm like Merge Sort, 
Heap Sort, etc, and return the element at index k-1 in the sorted array. 
Time Complexity of this solution is O(N Log N).
If you do not wish to change the original array then you have to use an aux array.
*/
// Function to return k'th smallest element in a given array
int KthSmallest(int arr[], int n, int k)
{
	// Sort the given array
	sort(arr, arr + n);

	// Return k'th element in the sorted array
	return arr[k - 1];
}
//Optimized solution: Quickselect method
/*This is an optimization over method 1 if QuickSort is used as a sorting algorithm in first step. 
In QuickSort, we pick a pivot element, then move the pivot element to its correct position and partition the 
surrounding array. The idea is, not to do complete quicksort, but stop at the point where 
pivot itself is k’th smallest element. Also, not to recur for both left and right sides of pivot,
but recur for one of them according to the position of pivot. 
The worst case time complexity of this method is O(n2), but it works in O(n) on average. */
int partition(int arr[], int l, int r);
 
// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int n, int k)
{
	int l=0,r=n-1;
    // If k is smaller than number of elements in array and positive. Basically k should lie inside the array.
    if (k > 0 && k <=n) {//k is position and not index.. indices are till n-1 
    	while(l<=r)
        {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int p = partition(arr, l, r);
 
        // If position is same as k
        if (p == k - 1)
            return p;
        if (p > k - 1) // If position is more, recur for left subarray
            r=p-1;
 		else
 			l=p+1;
		}
    }
 
    // If k is more than number of elements in array
    return -1;
}
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
//In the worst case(sorted array) Quickselect is O(N^2). To improve this we must use randomized quick sort
//so that last element is not always picked as pivot. Randomized quickselect works in O(N) time. Link below:
//https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
// Driver program to test above methods
int main()
{
	int arr[] = { 12 ,5, 787 ,1 ,23 };//1 5 12 23 787 
	int n = sizeof(arr) / sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " << arr[kthSmallest(arr, n, k)];
	return 0;
}

