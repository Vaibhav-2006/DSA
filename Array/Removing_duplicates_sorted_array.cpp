// Simple C++ program to remove duplicates from sorted array
//Using auxillary space approach
#include<iostream>
using namespace std;

// Function to remove duplicate elements
// This function returns new size of modified
// array.
int removeDuplicates(int arr[], int n)
{
	// Return, if array is empty
	// or contains a single element
	if (n==0 || n==1)
		return n;
	//temp is made of size n because arr[] can have n unique elements
	int temp[n];
	temp[0]=arr[0];//first element is always unique
	int temp_size=1;
	// Start traversing elements
	for (int i=1; i<n; i++)
		if (arr[i] != temp[temp_size-1])
			temp[temp_size++] = arr[i];


	// Modify original array
	for (int i=0; i<temp_size; i++)
		arr[i] = temp[i];

	return temp_size;
}

/*
Time Complexity : O(n) 
Auxiliary Space : O(n)
*/

//Method 2
int remove_duplicates(int arr[],int n)
{
	if(n==0)
	return -1;//to show array is empty
	int res=1;
	for(int i=1;i<n;i++)
	{
		if(arr[res-1]!=arr[i])
			arr[res++]=arr[i];
	}
	return res;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // removeDuplicates() returns new size of
    // array.
    n = removeDuplicates(arr, n);
 
    // Print updated array
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
 	
    return 0;
}
//Time Complexity : O(n) 
//Auxiliary Space : O(1)

