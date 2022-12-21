// C++ program to find union of
// two sorted arrays
#include <iostream>
using namespace std;
//Naive approach is to add both these elements to an aux array c[m+n] of size m+n and then sort array c[]
//and then print duplicates by using if i>0 &&c[i]!=c[i-1] then print. Time: O((m+n)log(m+n))


//Better approach using merging
/* Function prints union of arr1[] and arr2[]
m is the number of elements in arr1[]
n is the number of elements in arr2[] */
void printUnion(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n) {//arr1[]=10 20 20 30 40   arr2[]=5 20 20 30 40 40
		if(i>0&&arr1[i]==arr1[i-1])
		{
			i++;
			continue;
		}
		if(j>0&&arr2[j]==arr2[j-1])
		{
			j++;
			continue;
		}
		if (arr1[i] < arr2[j])
			cout << arr1[i++] << " ";

		else if (arr2[j] < arr1[i])
			cout << arr2[j++] << " ";

		else 
		{
			cout << arr2[j++] << " ";
			i++;//move i and j both
		}
	}

	/* Print remaining elements of the larger array */
	while (i < m)
	{
		if(i>0&&arr1[i]!=arr1[i-1])
			cout << arr1[i++] << " ";
		else i++;//if element is same as previous element still i has to increment to avoid infinte loop. 
	}

	while (j < n)
	{
		if(j>0&&arr2[j]!=arr2[j-1])
		cout << arr2[j++] << " ";
		else
		j++;
	}
}

/* Driver program to test above function */
int main()
{
	int arr1[] = { 1 ,2 ,3 ,4 ,5};
	int arr2[] = { 1,2,3 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	// Function calling
	printUnion(arr1, arr2, m, n);

	return 0;
}

