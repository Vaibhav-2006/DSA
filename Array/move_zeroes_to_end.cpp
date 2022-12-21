// Simple C++ program to move zeroes to the end in array
#include<iostream>
using namespace std;
//Naive approach
void moveToEnd(int arr[],int n)
{
	for ( int i=0; i < n; i++)
	if(arr[i]==0)//if zero is found then find a non zero element in the array and swap.
	{
		bool flag=false;// to see if there are any non zero elements left 
		for(int j=i+1;j<n;j++)//because there would be no point in running the loop
		if(arr[j]!=0)//if only zeroes are left.
		{
			swap(arr[j],arr[i]);//in built std::swap()
			flag=true;	
			break;//Very important to use break here to preserve the order of non zero elements	
		}
	if(flag==false)
	break;
	}
}


//This is O(N^2) solution

//Another solution could be to use an auxillary array in which unique elements would be copied
//and then copied back to the original array making sure last all elements are zeroes so that it
//looks like zeroes have been moved to end

//Example
//arr[]=1 2 3 0 0 7 0 9
//aux array= 1 2 3 7 9, count 5
//now from 0 to count copy back to arr and from count to n use arr[i]=0

//O(N soltion with O(1) space

void pushZerosToEnd(int arr[], int n)
{
    int count = 0;  // Count of non-zero elements
 
    // Traverse the array. If element encountered is non-
    // zero, then swap the element at index 'count'
    // with this element
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            swap(arr[count++],arr[i]); // here count is
                                   // incremented
	
}
//In above program if input is
// 1 3 0 0 5
//then 1 swapped with itself and 3 does the same
//then 5 is swapped with 0 at index 2
// Driver program to test above function
int main()
{
    int arr[] = {15 ,12, 0, 0, 0, 2, 2 ,19 ,6 ,17, 16, 20, 0 ,2 ,16, 0, 10, 0, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    moveToEnd(arr, n);
    cout << "Array after pushing all zeros to end of array :\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
