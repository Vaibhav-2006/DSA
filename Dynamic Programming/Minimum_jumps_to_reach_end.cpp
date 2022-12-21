// C++ program to find Minimum
// number of jumps to reach end
#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum number
// of jumps to reach arr[h] from arr[l]
int minJumps(int arr[], int n)
{

	// Base case: when source and
	// destination are same
	if (n == 1)
		return 0;

	// Traverse through all the points
	// reachable from arr[l]
	// Recursively, get the minimum number
	// of jumps needed to reach arr[h] from
	// these reachable points
	int res = INT_MAX;
	for (int i = 0; i <= n-2; i++) {
		if (i + arr[i] >= n - 1) {
			int sub_res = minJumps(arr, i + 1);
			if (sub_res != INT_MAX)
				res = min(res, sub_res + 1);
		}
	}

	return res;
}
/*
Complexity Analysis: 

Time complexity: O(n^n). 
There are maximum n possible ways to move from a element. So maximum number of steps
can be N^N so the upperbound of time complexity is O(n^n)
Auxiliary Space: O(1). 
There is no space required (if recursive stack space is ignored).
*/


//Tabulation solution
int MinJumps(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int* jumps = new int[n];
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (arr[j]+j>=i ){
            	if(jumps[j]!=INT_MAX)
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    return jumps[n - 1];
}

//Time Complexity: O(n^2) 
//Auxiliary Space: O(n)

// Driver Code
int main()
{
	int arr[] = { 1, 3, 6, 3, 2,
				3, 6, 8, 9, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum number of jumps to";
	cout << " reach the end is " << MinJumps(arr, n);
	return 0;
}
