/*A simple solution is to consider all subarrays one by one and check the sum of every subarray. 
Following program implements the simple solution. Run two loops: the outer loop picks 
a starting point I and the inner loop tries all subarrays starting from i.*/

/* A simple program to print subarray
with sum as given sum */
#include <bits/stdc++.h>
using namespace std;

//Naive approach

/* Returns true if the there is a subarray
of arr[] with sum equal to 'sum' otherwise
returns false. Also, prints the result */
bool SubArraySum(int arr[], int n, int sum)
{
	int curr_sum, i, j;

	// Pick a starting point
	for (i = 0; i < n; i++) {
		curr_sum = 0;

		// try all subarrays starting with 'i'. arr[i] itself is also a subarray
		for (j = i; j < n; j++) {
			curr_sum+=arr[j];
			if (curr_sum == sum) {
				cout << "Sum found between indexes "
					<< i << " and " << j ;
				return 1;
			}
		}
	}

	cout << "No subarray found";
	return 0;
}
/*Time Complexity: O(n^2) in worst case. 
Nested loop is used to traverse the array so the time complexity is O(n^2)
Space Complexity: O(1). 
As constant extra space is required.
*/


/*Efficient Approach: There is an idea if all the elements of the array are POSITIVE. 
If a subarray has sum greater than the given sum then there is no possibility that adding 
elements to the current subarray the sum will be x (given sum). Idea is to use a similar approach 
to a sliding window. Start with an empty subarray, add elements to the subarray until the sum is 
less than x. If the sum is greater than x, remove elements from the start of the current subarray.*/

int subArraySum(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of
    first element and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;
 
    /* Add elements one by one to curr_sum and
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }
 
        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum) {
            cout << "Sum found between indexes "
                 << start << " and " << i - 1;
            return 1;
        }
 
        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }
 
    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
}
/*
Time Complexity : O(n). 
Only one traversal of the array is required. So the time complexity is O(n).
Space Complexity: O(1). 
As constant extra space is required.

Above solution does not handle negative numbers but is the best solution for non negative 
numbers.*/


//The idea is to store the prefix sum in a hash set if prefix sum - sum is not present in array
//or prefix sum is not equal to sum itself(edge case).

 bool subArrayExists(int arr[], int n, int sum)
{
    unordered_set<int> s;
 
    // Traverse through array
    // and store prefix sums
    int pre_sum=0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
 
        // If arr[0] is sum or pre_sum upto i (edge cases) is sum or
        // prefix sum - sum is present meaning there is a subarray evaluating to sum as
        // pre_sum -(pre_sum-sum)=sum.// 5 13 32 35 48.. and sum = 22 then when you find pre_sum 
        // 35 and search for 35-22 you find 13 is present in set meaning the subarray from
		// presfix sum= 13 to prefix sum= 35 forms a subarray of sum 22. 
        if (pre_sum == sum|| s.find(pre_sum-sum)!= s.end())
            return true;//sum 5 and arr[]= 1 2 3 9 11 is an edge case for which pre_sum==sum is 
 						//required. In general if prefix sum beginning from index 0 is sum then we 
        s.insert(pre_sum);// need this condition.
    }
    return false;
}

//Time complexity: O(N). 
//Space Complexity: O(N).

// Driver Code
int main()
{
	int arr[] = { 10, 2, -2, -20, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if(subArrayExists(arr, n,-12))
	cout<<"\nSubarray with given sum exists\n";
	else
	cout<<"\nSubarray with given sum does not exist\n";
	return 0;
}


