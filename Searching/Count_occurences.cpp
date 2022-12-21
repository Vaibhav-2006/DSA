// C++ program to find number of occurrences of
// a number in a given sorted array
#include <bits/stdc++.h>
using namespace std;

//Naive approach using linear search

// Returns number of times x occurs in arr[0..n-1]
int CountOccurrences(int arr[], int n, int x)
{
    int res = 0;
    for (int i=0; i<n; i++)
        if (x == arr[i])
          res++;
    return res;
}
//Time Complexity: O(n)

/*Method 2 (Better using Binary Search) 
We first find an occurrence using binary search. 
Then we match toward left and right sides of the matched the found index.*/

int binarySearch(int arr[], int l, int r, int x)
{
    if (r < l)
        return -1;
 
    int mid = l + (r - l) / 2;
 
    // If the element is present at the middle
    // itself
    if (arr[mid] == x)
        return mid;
 
    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);
 
    // Else the element can only be present
    // in right subarray
    return binarySearch(arr, mid + 1, r, x);
}
 
// Returns number of times x occurs in arr[0..n-1]
int countOccurrences(int arr[], int n, int x)
{
    int ind = binarySearch(arr, 0, n - 1, x);
 
    // If element is not present
    if (ind == -1)
        return 0;
 
    // Count elements on left side.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;
 
    // Count elements on right side.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;
 
    return count;
}
//O(Log n + count) where count is number of occurrences.
//In worst case it is also O(N)

//Best approach using iterative binary search functions like first occurence and last occurence

int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
         
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
         
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if(mid==0||arr[mid-1]!=arr[mid])
            	return mid;
            else
            	high=mid-1;
        }
    }
    return -1;
}
 
/* If x is present in arr[] then returns
the index of LAST occurrence of x in
arr[0..n-1], otherwise returns -1 */
int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
         
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
         
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if(mid==n-1||arr[mid+1]!=arr[mid])
            	return mid;
            else
            	low=mid+1;
        }
    }
    return -1;
}

int count(int arr[], int x, int n)
{   
  /* get the index of first occurrence of x */
  int low = first(arr, x, n);
 
  // If element is not present, return 0
  if (low == -1)
     return 0;
    
  /* Else get the index of last occurrence of x.*/  
  int high = last(arr, x, n);    
    
  /* return count */
  return high - low + 1;
}
/*
Time Complexity: O(Logn) 
Programming Paradigm: Divide & Conquer
*/
// Driver program
int main()
{
  int arr[] = {1, 2, 2, 3, 3, 3, 3};
  int x =  1;  // Element to be counted in arr[]
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = count(arr, x, n);
  printf("%d occurs %d times ", x, c);
  return 0;
}

