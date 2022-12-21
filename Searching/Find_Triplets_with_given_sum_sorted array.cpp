// A C++ program to find if there is a triplet with a given sum in a sorted array. 
#include <bits/stdc++.h>
using namespace std;

//Naive approach: O(N^3) approach with three for loops.
 
// Prints all triplets in arr[] with given sum
void findTriplets(int arr[], int n,int sum)
{
    bool found = false;
    for (int i=0; i<n-2; i++)
    {
        for (int j=i+1; j<n-1; j++)
        {
            for (int k=j+1; k<n; k++)
            {
                if (arr[i]+arr[j]+arr[k] == sum)
                {
                    cout << i << " "
                         << j << " "
                         << k <<endl;
                    found = true;
                }
            }
        }
    }
 
    // If no triplet with given sum found in array
    if (found == false)
        cout << " No Triplet Exists with given sum "<<endl;
 
}
//Best approach:Two pointer approach in O(N^2) time
//The two pointer approach never misses a pair in sorted array.

bool isPair( int arr[], int left , int right, int sum)
{//no need to pass size of array
	while(left<right)
	{
		if(arr[left]+arr[right]==sum)
		{
			cout<<left<<" "<<right<<" ";
			return true;
		}
		else if(arr[left]+arr[right]>sum)
			right--;
		else
			left++; 
	}
	return false;//if left becomes equal to right 
//	NOTE: left can never be greater than right as we are moving one pointer at a time.
}

void PrintTriplets(int arr[], int n, int sum)
{
	for(int i=0;i<n-2;i++)//The loop only needs to run till the third last element
	{//2 3 4 8 9 20 40 so we will check triplets which include element 2 first.
	//Since 2 is included then the other 2 elements should have sum as sum-2 so that sum-2+2=sum
		if(isPair(arr,i+1,n-1,sum-arr[i]))//so we have passed sum-arr[i] here to check for pairs with that sum.
			cout<<i<<endl;
	}
}
int main()
{
	int arr[]={2,4,8,9,11,12,20,30};
	int n=sizeof(arr)/sizeof(arr[0]);
	findTriplets(arr,n,32);
	PrintTriplets(arr,n,32);
}
//If there is an unsorted array in this problem then we still can use this two pointer approach
//to find triplet as sorting will take O(N*logN) time and Overall this approach will take O(N^2) time
//as seen above and this is much better than O(N^3) approach and might still be better than hashing
//approach which takes O(N^2) time with O(N) space and uses hash functions. For a sorted array
//this approach is much better than hashing.
