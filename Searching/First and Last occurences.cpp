// C++ program to find first and last occurrences of
// a number in a given sorted array
#include <bits/stdc++.h>
using namespace std;
//Naive approach using linear search
void findFirstAndLast(int arr[], int n, int x)
{
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (x != arr[i])
            continue;
        if (first == -1)
            first = i;
        last = i;//we can also do it using two functions in which we search from index 0 for first occurence 
    }//and from n-1 for last occurence and break when we find the element.
    if (first != -1)
        cout << "First Occurrence = " << first
             << "\nLast Occurrence = " << last<<endl;
    else
        cout << "Not Found";
}

/*Time Complexity: O(n) 
Auxiliary Space: O(1)
*/

//Recursive approach
/* if x is present in arr[] then returns the index of
FIRST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int first(int arr[], int low, int high, int x)
{
	if (high >= low) {
		int mid =(low+high) / 2;
		if (x > arr[mid])
			return first(arr, (mid + 1), high, x);
		else if(x<arr[mid])
			return first(arr, low, (mid - 1), x);
		else
		{
		//It is equal
		if(mid==0 || arr[mid-1]!=arr[mid])//5 10 10 10 10 20 30 in this 1 will be returned 
			return mid;// also if element is present at index 0 then it is obviously the first occurence and we cant
			//possibly check with arr[0-1]!=arr[0] example case: 5,5,5
		else 
			return first(arr,low,mid-1,x);	
		}
	}
	return -1;
}

/* if x is present in arr[] then returns the index of
LAST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int last(int arr[], int low, int high, int x, int n)
{//Here n has to be passed 
	if (high >= low) {
		int mid =(low+high) / 2;
		if (x > arr[mid])
			return last(arr, (mid + 1), high, x, n);
		else if(x<arr[mid])
			return last(arr, low, (mid - 1), x, n);
		else
		{
		//It is equal
		if(mid==n-1 || arr[mid+1]!=arr[mid])//5 10 10 10 10 20 30 in this 4 will be returned 
			return mid;// also if element is present at index n-1 then it is obviously the last occurence and we cant
			//possibly check with arr[n]!=arr[n-1]
		else 
			return last(arr,mid+1,high,x,n);	
		}
	}
	return -1;
}
/*Time Complexity : O(log n) 
Auxiliary Space : O(Log n) 
*/

//Best approach using iterative binary search

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

// Driver program
int main()
{
	int arr[] = { 5 ,10 ,10 ,10 ,10 ,20 ,30 };
	int n = sizeof(arr) / sizeof(int);
	
	int x = 10;
	
	findFirstAndLast(arr,n,x);
	
	printf("First Occurrence = %d\t",first(arr, 0, n - 1, x));
	
	printf("\nLast Occurrence = %d\n",last(arr, 0, n - 1, x, n));
	
	printf("First Occurrence = %d\t",first(arr,x,n));
	
	printf("\nLast Occurrence = %d\n",last(arr,x,n));


	return 0;
}
/*Time Complexity : O(log n) 
Auxiliary Space : O(1) 
*/
