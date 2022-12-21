#include <iostream>
using namespace std;
//Approach: Naive approach
//O(N^2)
// Function to find the longest subarray
int LongestEvenOddSubarray(int a[], int n)
{
	// Length of longest
	// alternating subarray
	int ans = 0;

	// Iterate in the array
	for (int i = 0; i < n ; i++) {
		int cnt = 1;
		// Iterate for every subarray
		for (int j = i + 1; j < n; j++) {
			if ((a[j - 1] % 2 == 0 && a[j] % 2 != 0)
				|| (a[j - 1] % 2 != 0 && a[j] % 2 == 0))
				cnt++;
			else
				break;
		}
		// store max count
		ans = max(ans, cnt);
	}

	return ans;
}

//Efficient approach similar to kadane's algorithm

int longestEvenOddSubarray(int a[], int n)
{
	// Length of longest
	// alternating subarray
	int longest = 1;
	int cnt = 1;

	// Iterate in the array
	for (int i = 1; i < n ; i++) {
		
		// increment count if consecutive
		// elements has an odd sum
		if ((a[i] + a[i - 1]) % 2 == 1) {//even+odd=odd
			cnt++;//you can use two ifs also 
          	longest = max(longest, cnt);
		}
		else{

			// Reinitialize cnt as 1 consecutive
			// elements does not have an odd sum
			cnt = 1;
		}
	}
	return longest;
}
//Time Complexity: O(N)

/* Driver code*/
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 7, 8 };

	int n = sizeof(a) / sizeof(a[0]);

	cout << longestEvenOddSubarray(a, n);
	return 0;
}

