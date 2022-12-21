// C++ program to demonstrate working of an algorithm that finds
// an element in an array of infinite size
#include<iostream>
using namespace std;
//Naive solution using linear search where we run the while loop till arr[i]<key
//and then check if arr[i]==key. Time complexity is O(n).
// Using unbounded Binary search algorithm
int binarySearch(int arr[], int l, int r, int x)
{
    if (r>=l)
    {
        int mid = (l + r) /2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}
 
// function takes an infinite size array and a key to be
//  searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
int findPos(int arr[], int key)
{
//	explicitly checking for index 0 as we are doubling the index until we find an element greater than 
//	or equal to key and 0*2=0
    if(arr[0]==key)
    return 0;
 
    int i=1;
    while (arr[i] < key)
    {
        i=i*2;
    }//we exit loop when arr[i] becomes >=key
    
    if(arr[i]==key)
 		return i;
 	
	//Now the only possiblity left is arr[i]>key
    return binarySearch(arr, i/2+1, i-1, key);//1 10 15 20 40 60 80 100 200 and key is 100 so first 10 is checked
    //then 15(index 2) then 40 then 200 and 200 is greater than 100 so we have an upper bound index.
    //Now we perform binary search on 60 to 100 which is i/2+1 to i-1 
}
/*
 Let p be the position of element to be searched. Number of steps for finding high index ‘h’ is O(Log p). 
 The value of ‘h’ must be less than 2*p. The number of elements between h/2 and h must be O(p). 
 Therefore, time complexity of Binary Search step is also O(Log p) and overall 
 time complexity is 2*O(Log p) which is O(Log p).
 */
// Driver program
int main()
{
    int arr[] = {1 ,10 ,15, 20 ,40 ,60 ,80 ,100 ,200};
    int ans = findPos(arr, 100);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}
