// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;
//Naive approach O(N^2)
int maxSubArraySum(int arr[], int size)
{
	int max_sum=arr[0];
	for(int i=0;i<size;i++)
	{
		int sum=0;
		for(int j=i;j<size;j++)
		{
			sum+=arr[j];
			max_sum=max(max_sum,sum);
		}
	}
	return max_sum;
}

//Kadane's algorithm
int MaxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending = 0;

	for (int i = 0; i < size; i++)
	{
		max_ending = max(max_ending+a[i],a[i]);

		max_so_far=max(max_so_far,max_ending);
	}
	return max_so_far;
}
//Time Complexity: O(N)
/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = MaxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}


