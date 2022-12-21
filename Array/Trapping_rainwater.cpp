// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;
//Naive approach
// Function to return the maximum
// water that can be stored
int maxWater(int arr[], int n)
{
	
	// To store the maximum water
	// that can be stored
	int res = 0;
	
	// For every element of the array
	for (int i = 1; i < n-1; i++) {
		
		// Find the maximum element on its left
		int left = arr[i];
		for (int j=0; j<i; j++)
		left = max(left, arr[j]);
		
		// Find the maximum element on its right
		int right = arr[i];
		for (int j=i+1; j<n; j++)
		right = max(right, arr[j]);
		
	// Update the maximum water
	res = res + (min(left, right) - arr[i]);
	}

	return res;
}
/*Time Complexity: O(n2). 
There are two nested loops traversing the array, So time Complexity is O(n2).
Space Complexity: O(1). 
No extra space is required.
*/

//Efficient approach

int findWater(int arr[], int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
 
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);
 
    // Fill right array
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);
 
    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
 
    return water;
}

// Driver code
int main()
{
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << findWater(arr, n);
	
	return 0;
}

/*Time Complexity: O(n). 
Only one traversal of the array is needed, So time Complexity is O(n).
Space Complexity: O(n). 
Two extra arrays are needed each of size n.
*/

