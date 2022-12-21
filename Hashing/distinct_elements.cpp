// C++ program to count distinct elements
// in a given array
#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

int countDistinct(int arr[], int n)
{
	int res = 1;
	int j=0;
	// Pick all elements one by one
	for (int i = 1; i < n; i++) {//10 20 10 20 30, i is 1 because first element is always unique
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j])
				break;

		// If not printed earlier, then print it
		if (i == j)//j is not defined here if it is created inside for loop
			res++;
	}
	return res;
}
//Time Complexity of above solution is O(n2). We can Use Sorting to solve the problem in O(nLogn) time. 
//The idea is simple, first sort the array so that all occurrences of every element become consecutive. 
//Once the occurrences become consecutive, we can traverse the sorted array and count distinct elements 
//in O(n) time. Following is the implementation of the idea. 
int CountDistinct(int arr[], int n)
{
	// First sort the array so that all
	// occurrences become consecutive
	sort(arr, arr + n);

	// Traverse the sorted array
	int res = 1;
	for (int i = 1; i < n; i++) {
		if(arr[i]!=arr[i-1])//10 10 20 20 30
          res++;
	}

	return res;
}

//Efficient approach
int distinct(int* arr, int len)
{//unordered set works on hashing while set works on red black trees.
    unordered_set<int> S; // declaring a set container using STL
    for (int i = 0; i < len; i++) {
        S.insert(arr[i]); // inserting all distinct elements of the
                          // array into set as set allows only distinct elements.
    }
    int ans = S.size(); // calculating the size of the set
    return ans;
}
//well, we could have made a set above by simply using unordered_set<int> S(arr,arr+n) because set has
//this type of constructor that accepts iterators for initialization of the set.
// Driver program to test above function
//Time complexity: theta(N)
//Space complexity: O(N) (big Oh) because at max we will have n elements if there are all distinct elements
int main()
{
	int arr[] = { 12, 10, 9, 45, 2, 10, 10, 45 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << distinct(arr, n);
	return 0;
}

