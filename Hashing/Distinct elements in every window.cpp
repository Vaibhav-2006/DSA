/* For an array of size n and size of window=k there are n-k+1 total windows.
Input: arr[] = {1, 2, 1, 3, 4, 2, 3};
       k = 4.. There are total 7-4+1 windows
Output: 3 4 4 3

Explanation:
First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3

Input: arr[] = {1, 2, 4, 4};
       k = 2
Output: 2 2 1

Explanation:
First window is {1, 2}, count of distinct numbers is 2
First window is {2, 4}, count of distinct numbers is 2
First window is {4, 4}, count of distinct numbers is 1
*/
/*
Naive Approach: The naive solution is to traverse the given array considering every window
in it and keeping a count on the distinct elements of the window. 

Algorithm: 

For every index i from 0 to len_array(n) – k, i.e n – k, traverse the array from i to i + k. This is the window
Traverse the window, from i to that index and check if the element is present or not.
If the element is not present in the prefix of the array, i.e no duplicate element is present from i to 
index-1, then increase the count.
Print the count.*/

// Simple C++ program to count distinct
// elements in every window of size k
#include <bits/stdc++.h>
using namespace std;

// Counts distinct elements in window of size k
int countWindowDistinct(int win[], int k)
{
	int dist_count = 0;
	bool flag=false;

	// Traverse the window
	for (int i = 0; i < k; i++) {
		// Check if element arr[i] exists in arr[0..i-1]
		flag=false;
		for (int j = 0; j < i; j++)
			if (win[i] == win[j])
				{
					flag=true;
					break;
				}
		if (flag==false)
			dist_count++;
	}
	return dist_count;
}

// Counts distinct elements in all windows of size k
void CountDistinct(int arr[], int n, int k)
{
	// Traverse through every window
	for (int i = 0; i <= n - k; i++)
		cout << countWindowDistinct(arr + i, k) << " ";//find distinct elements in every window
}

/*
Time complexity: O((n-k+1)*k*k). 
The time complexity can be improved to O(n*k*log k) by modifying countWindowDistinct() by the use of sorting.
We would sort every window win[] in such a way that original array is not changed and then find distinct
elements in a sorted array using arr[j]!=arr[j-1] kind of condition. 
The function can further be optimized to use hashing to find distinct elements in a window. 
This can be done using a hash set and simply inserting all window elements into hash set and printing
size of hash set. Using hashing this way the time complexity becomes O(n*k).
Space Complexity: O(1) No extra space is needed.
*/

//Now an approach similar to sliding window and also using hashing

void countDistinct(int arr[], int k, int n)
{
    // Create an empty hashmap hm
    unordered_map<int, int> hm;
    
    // Traverse the first window and store count
    // of every element in hash map
    for (int i = 0; i < k; i++) {
        hm[arr[i]]++;//if a new element is inserted its count becomes 1 and for a duplicate element count 
    }				//increases by 1.
 	
    // Print count of first window
    cout << hm.size() << " ";
    //Now elements from 0 to k-1 are in hashmap so iterate from i= k to i=n-1.
 	    // Traverse through the remaining array
    
	for (int i = k; i < n; i++) {
        // Decrease frequenct of first element of previous window
        // If there was only one occurrence meaning its frequency was 1, then remove that element from hm.
        hm[arr[i - k]]--;
        
        if(hm[arr[i-k]]==0)
        hm.erase(arr[i-k]);//see below for explanation

        // Add new element of current window
        // If this element appears first time,
        // it is added to map with frequency 1 else its frequency is incremented.
 
        hm[arr[i]]++;
 
        // Print count of current window
        cout << hm.size() << " ";
    }
}
/*
Complexity Analysis: 
Time complexity O(n). A single traversal of the array is required.
Space Complexity O(k). Since the hashmap requires maximum space k for every window if there are distinct
elements.
*/
// Driver program
int main()
{
	int arr[] = { 1, 2, 1, 3, 4, 2, 3}, k=4;
	int n = sizeof(arr) / sizeof(arr[0]);
	countDistinct(arr, k, n);
	return 0;
}
/*erasing by iterator: It takes an iterator as a parameter and erases the key and value present at that iterator.
Syntax:
unordered_map.erase(const iterator);
Now this iterator could be found using find() function
erasing by key: It takes a key as a parameter and erases the key and value.
Syntax:
unordered_map.erase(const key);
we are using this above form.
*/
