// C++ program to solve chocolate distribution
// problem
#include <bits/stdc++.h>
using namespace std;

// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
	// if there are no chocolates or number
	// of students is 0
	if (m == 0 || n == 0)
		return 0;

	// Sort the given packets
	sort(arr, arr + n);

	// Number of students cannot be more than
	// number of packets
	if (n < m)
		return -1;

	// Largest number of chocolates
	int min_diff = arr[m-1]-arr[0];

	// Find the subarray of size m such that
	// difference between last (maximum in case
	// of sorted) and first (minimum in case of
	// sorted) elements of subarray is minimum.
	// The approach below is similar to sliding window.
	for (int i = 1; i + m - 1 < n; i++) {
		int diff = arr[i + m - 1] - arr[i];
		min_diff=min(min_diff,diff);
	}
	return min_diff;
}
//Time Complexity:O(N*logN)
int main()
{
	int arr[] = { 12, 4, 7, 9, 2, 23, 25, 41, 30};
	int m = 3; // Number of students
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum difference is "
		<< findMinDiff(arr, n, m);
	return 0;
}

