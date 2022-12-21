/* Dynamic Programming C++ implementation
of LIS problem */
#include <bits/stdc++.h>
using namespace std;

/* lis() returns the length of the longest
increasing subsequence in arr[] of size n */
int Lis(int arr[], int n)
{
	int lis[n];

	lis[0] = 1;//no element on left of 1st element

	/* Compute optimized LIS values in
	bottom up manner */
	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[j]<arr[i])
				lis[i] = max(lis[i],lis[j]+1);
	}

	// Return maximum value in lis[]
	return *max_element(lis, lis + n);
}

/*
Time Complexity: O(n2). 
Auxiliary Space: theta(n). 
*/

// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r > l) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m+1;
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];//tail[i] stores the minimum possible tail value for lis of length i+1
    for (int i = 1; i < v.size(); i++) 
	{

        // v[i] extends largest subsequence
        if (v[i] > tail[length - 1])
            tail[length++] = v[i];
 
        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming greater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
        {
        	int index=CeilIndex(tail, 0, length - 1, v[i]);//index of ceil element
        	tail[index] = v[i];
		}
	}	
 
    return length;
}

/*
Time Complexity: O(n*logn). Think why it is not theta but big Oh.
Because we might not go into the ceil function for some inputs like elements given in 
ascending order. 
Auxiliary Space: O(n). because a vector is used. note that O(n) is better than theta(n).
*/

/* Driver program to test above function */
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lis is:\nO(n^2): %d", Lis(arr, n));
	vector<int> v(arr,arr+n);//initialize a vector with an existing array
	cout<<endl<<"O(n*logn): "<<LongestIncreasingSubsequenceLength(v);
	return 0;
}

