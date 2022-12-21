// C++ program to find Majority
// element in an array
#include<iostream>
using namespace std;

//Naive approach

int majorityElement(int arr[], int n)
{
	for (int i = 0; i < n; i++) 
    {
		int count = 1;
		for (int j = i+1; j < n; j++) 
        {
			if (arr[i] == arr[j])
				count++;
        }
            if(count>n/2)
            return i;//returning index of majority element
    }
    return -1;//This will only be executed if there is no majority element
}

/*
Time Complexity: O(n*n). 
A nested loop is needed where both the loops traverse the array from start to end, 
so the time complexity is O(n^2).
Auxiliary Space: O(1). 
As no extra space is required for any operation so the space complexity is constant.
*/

//O(n*logn) approach
/*
Approach: The idea is to sort the array. Sorting makes similar elements in the array adjacent,
so traverse the array and update the count until the present element is similar to the previous one. 
If the frequency is more than half the size of the array, print the majority element.
*/

//Another approach is to solve using hashmap 
//Time: O(N), Space: O(N)

//Efficient solution using Moore's voting algorithm
/*
Approach: This is a two-step process. 
The first step gives the element that maybe the majority element in the array. If there is a 
majority element in an array, then this step will definitely return majority element, otherwise, 
it will return candidate for majority element.
Check if the element obtained from the above step is majority element. This step is necessary 
as there might be no majority element.
*/

//This process may not give the index of the first occurence of the element.

int MajorityElement(int *arr, int n)
{
	int count =1, res=0;//1st element is made majority and its count is 1
	for(int i=1;i<n;i++)
	{
		if(arr[res]==arr[i])
			count++;
		else 
			count--;
		if(count==0)//if count is made 0 then we reset count and res
			{
				res=i;
				count=1;
			}		
	} 
	//if a majority element exists for sure(if it is given in question that it exists)
	//then for sure the element res is the majority the element
	//Anyways no element other than res can be the majority
	count=0;
	for(int i=0;i<n;i++)
		if(arr[res]==arr[i])
			count++;
	if(count<=n/2)
		return -1;//res is not the majority
				  //example: 6,8,4,8,5 in this res will be 4 which is not index of majority element
	return res;//res is the majority
}
/*
Time complexity: O(N)
Space Complexity: O(1)
*/

int main()
{
	int arr[] = { 1, 1, 2 , 1, 3, 5, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function calling
	cout<<MajorityElement(arr, n);

	return 0;
}
