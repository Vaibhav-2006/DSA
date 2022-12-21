/* CPP program to find length of the largest
subarray which has all contiguous elements */
//Both solutions work for duplicate elements as well.
#include<bits/stdc++.h>
using namespace std;

//Naive approach
//Use sorting
int FindLength(int arr[], int n)
{
	sort(arr,arr+n);
	int curr=1,res=1; //10 20 30 is an array with contiguous elements subarray length=1
	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1]+1)
		{
			curr++;
			res=max(res,curr);
		}
		else if(arr[i]==arr[i-1])
		continue;//very important to handle duplicates. without this condition below case will fail:
//		arr[]=6 6 2 3 1 4 1 5 6 2 8 7 4 2 1 3 4 5 9 6
		else
		curr=1;//new subarray begins
	}
	return res;
}
//Time complexity: O(n*logn)
//Space complexity: O(1)
// This function prints all distinct elements
int findLength(int arr[], int n)
{
	int res=0,curr; // Initialize result

	for (int i=0; i<n; i++)
	{
		// Create an empty hash set and
		// add all elements to it.
		unordered_set<int> myset(arr,arr+n);

			// If current element is not the beginning of a subarray then break else find
			// the length of subarray beginning with current element if current element - 1 is not
			//present in hash set.
			if (myset.find(arr[i]-1) == myset.end())
		{
			curr=1;//since element is beginning of a subarray. set length as 1.
			
			while(myset.find(arr[i]+curr)!=myset.end())//while consecutive elements beginning with arr[i]  
			curr++;//are present increment curr.
			
			res=max(res,curr);
		}
	}
	return res; // Return result

}
//Time complexity: O(N)
//Space complexity: O(N)
//Why above solution is O(N)? Consider arr[]= 3 8 4 5 7.. insert it into hash set. then pick 3 and see that
//3-1=2 is not in hash set so 3 is beginning of a hash set so you find 4 and 5 contiguous elements beginning
//with 3.updates res to 3. So you did 3 lookups(2,4,5). Now pick 8 and since 7 is present 8 is not beginning
//of a contiguous subsequence so ignore 8. You did 1 lookup for 7. Same with 4 and 5. You found 3 and 4 
//so again 2 more lookups. Now for 7 you will look for 6 which is not present and then look for 8 which is present
// so you update curr to 2 but res remains 3. for 7 you did 2 lookups(6,8). So in general for an element
// i you are doing lookup for i-1 and i+1 and then for i+1 you only look for i and stop. In general you are
// doing 2n lookups. So this solution is O(N). Also check for arr[ 1,2,3,4,5] and arr[10 20 30].

// Driver method to test above method
int main ()
{
	int arr[] = {6, 6, 2, 3, 1 ,4 ,1 ,5 ,6 ,2 ,8 ,7 ,4 ,2 ,1, 3 ,4 ,5 ,9 ,6};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Length of the longest contiguous"
		<< " subarray is " << findLength(arr, n);
}


