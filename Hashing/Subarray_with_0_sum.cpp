/*A simple solution is to consider all subarrays one by one and check the sum of every subarray. 
Following program implements the simple solution. Run two loops: the outer loop picks 
a starting point I and the inner loop tries all subarrays starting from i.*/

/* A simple program to print subarray
with sum as given sum */
#include <bits/stdc++.h>
using namespace std;

//Naive approach

/* Returns true if the there is a subarray
of arr[] with sum equal to '0' otherwise
returns false. Also, prints the result */
bool subArraySum(int arr[], int n)
{
	int curr_sum, i, j;

	// Pick a starting point
	for (i = 0; i < n; i++) {
		curr_sum = 0;

		// try all subarrays starting with 'i'. arr[i] itself is also a subarray
		for (j = i; j < n; j++) {
			curr_sum+=arr[j];
			if (curr_sum == 0) {
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

/*We can also use hashing. The idea is to iterate through the array and for every element arr[i],
 calculate the sum of elements from 0 to i (this can simply be done as sum += arr[i]). 
 If the current sum has been seen before, then there is a zero-sum array. Hashing is used
 to store the sum values so that we can quickly store sum and find out whether the current sum
 is seen before or not.
 */
 bool subArrayExists(int arr[], int n)
{
    unordered_set<int> s;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
 
        // If arr[0] is 0 or arr[0...i](edge cases) is 0 or found
        // prefix sum is already present meaning there is a subarray evaluating to 0.
        if (sum == 0|| s.find(sum)!= s.end())
            return true;
 
        s.insert(sum);
    }
    return false;
}
//Time Complexity of this solution can be considered as O(n) under the assumption that 
//we have good hashing function that allows insertion and retrieval operations in O(1) time. 
//Space Complexity: O(n) .Here we required extra space for unordered_set to insert array elements
//Also check exercise below
// Driver Code
int main()
{
	int arr[] = { 1, 5, -2, -2, 11, -4, 3 };//0, 2, -4, 1, 6 //4, 2, -3, 1, 6
	int n = sizeof(arr) / sizeof(arr[0]);
	if(subArrayExists(arr, n))
	cout<<"\nSubarray with given sum exists\n";
	else
	cout<<"\nSubarray with given sum does not exist\n";
	return 0;
}//Exercise: 
//Extend the above program to print starting and ending indexes of all subarrays with 0 sum.
//Maybe use hashmap to store indices as values and sum as keys.


