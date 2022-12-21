/* C++ implementation of QuickSort using Hoare's
partition scheme. */
#include <bits/stdc++.h>
using namespace std;

/* This function takes first element as pivot, and places
all the elements smaller than the pivot on the left side of index j(element at index j is also less than pivot)
and not the pivot itself and all the elements greater than and equal to the pivot on the right side of index j.
It returns the index of the last element on the smaller side. 
Remember that unlike Lomuto partitioning this partitioning does not place the pivot
itself in the correct sorted position but just sorts the elements about the index j.
Example if arr[]=8 4 7 9 3 10 5 then 8 is pivot and after 1st call to partition we get
arr[]=5 4 7 3 9 10 8 and we return j=3.Notice that array is sorted around j=3. all elements from 0 to 3(inclusive)
are less than all elements from j+1 to n-1*/
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1, j = high + 1;

	while (true) {
		// Find leftmost element greater than
		// or equal to pivot
		do {
			i++;
		} while (arr[i] < pivot);

		// Find rightmost element smaller than
		// or equal to pivot
		do {
			j--;
		} while (arr[j] > pivot);

		// If two pointers met.
		if (i >= j)
			return j;

		swap(arr[i], arr[j]);
	}
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver Code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

