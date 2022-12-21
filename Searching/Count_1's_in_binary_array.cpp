// C++ program to find number of 1's in a binary sorted array
//example: 0 0 1 1 1 1
#include <bits/stdc++.h>
using namespace std;

//Naive approach using linear search

// Returns number of times 1 occurs in arr[0..n-1]
int CountOccurrences(int arr[], int n)
{
	int i;
    for (i=0; i<n; i++)
        if (arr[i] == 1)//as soon as you find 1 you know that array is sorted so break.
          break;
    return n-i;//returns 0 if element not present
}
//Time Complexity: O(n)

//Best approach using iterative binary search functions like first occurence

int firstandcount(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
         
        // Normal Binary Search Logic
        int mid = (low + high) / 2;
         
//        if (arr[mid] > 1) This condition is not possible as it is a binary array
//            high = mid - 1;
        if (arr[mid] == 0)//sort of like arr[mid]<x
            low = mid + 1;
        else
        {
            if(mid==0||arr[mid-1]==0)//if arr[mid-1] is zero then you have found the first occurence of 1.
            	return n-mid;
            else
            	high=mid-1;
        }
    }
    return 0;//0 occurences if element is not present
}
// Driver program
int main()
{
  int arr[] = {0,0,1,1,1,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = firstandcount(arr, n);
  printf("%d occurs %d times ", 1, c);
  return 0;
}

