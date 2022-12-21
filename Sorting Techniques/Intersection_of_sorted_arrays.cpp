// C++ program to find intersection of
// two sorted arrays
#include <iostream>
using namespace std;
//Naive approach: Use two for loops and for every element in first array arr such that 
//arr[i]!=arr[i-1] , search for the element in the second array. if found print.
//Efficient approach using merging.
/* Function prints Intersection of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
void printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n) {
		if(i>0&&arr1[i]==arr1[i-1])
		{
			i++;
			continue;
		}
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else /* if arr1[i] == arr2[j] */
		{
			cout << arr1[i] << " ";
			i++;
			j++;
		}
	}
}
//Time Complexity : O(m + n) because array is already sorted

/* Driver program to test above function */
int main()
{
	int arr1[] = { 1, 2, 2, 2, 3, 4 };
	int arr2[] = { 2, 2, 4, 6, 7, 8 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// Function calling
	printIntersection(arr1, arr2, m, n);

	return 0;
}

