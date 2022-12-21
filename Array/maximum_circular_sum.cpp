#include <iostream>
using namespace std;
//Approach: Naive approach
//O(N^2)
int MaxCircularSum(int arr[],int n)
{
	int res=arr[0];
	for(int i=0;i<n;i++)//no. of passes
	{//We will find max sum for each element in curr_max
		int curr_sum=arr[i];
		int curr_max=arr[i];
		for(int j=1;j<n;j++)
		{
			int index=(i+j)%n;//circular fashion
			curr_sum+=arr[index];
			curr_max=max(curr_sum,curr_max);
		}
		res=max(res,curr_max);
	}
	return res;
}
//Now using kadane's algorithm we will solve the problem in O(N) time
int kadane(int a[], int n);
 
// The function returns maximum
// circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
    // Case 1: get the maximum sum using standard kadane's algorithm
    int max_kadane = kadane(a, n);
     // if maximum sum using standard kadane' is less than 0
     //it means all the elements are negative. In this case max_kadane is already the maximum sum.\
     // if we do not use this condition we will get wrong ans bcoz while finding the minimum sum
     // subarray we will be inverting(making negative) the array and calling kadane function.
     // in that case kadane will return the sum of the array.
    if(max_kadane < 0)
      return max_kadane;
 
    // Case 2: Now find the maximum sum that includes
    // corner elements.
    int arr_sum = 0, i;
    for (i = 0; i < n; i++) {
        arr_sum += a[i]; // Calculate array-sum
        a[i] = -a[i]; // invert the array (change sign)
    }
    //Instead of inverting the array to find the minimum subarray sum we can make a kadane's algorithm
    //that finds minimum subarray sum.
 	
    // circular_sum = total sum- (minimum subarray sum)
    int circular_sum = arr_sum + kadane(a, n);// we are adding as array has already been inverted
 	//4 -2 3  sum= 5, minimum sum subarray=-2 so circular sum = sum(4+ -2 + 3) - ( -2)
    // The maximum subarray sum will be maximum of two sums that is standard kadane's maximum subarray sum
	// or maximum circular subarray sum 
    return (circular_sum > max_kadane) ? circular_sum : max_kadane;
}
 
int kadane(int arr[], int size)
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
/*Time Complexity: O(n), where n is the number of elements in the input array. 
As only linear traversal of the array is needed.*/
/* Driver code*/
int main()
{
    int a[] = { 8,-4,3,-5,4 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum circular sum is " << maxCircularSum(a, n) << endl;
    return 0;
}

