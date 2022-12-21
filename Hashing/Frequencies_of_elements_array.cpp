// CPP program to count frequencies of array items
#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>
void CountFreq(int arr[], int n)
{
	bool flag;
	// Traverse through array elements and
	// count frequencies
	for (int i = 0; i < n; i++) {
		flag=false;//make flag false for each iteration
		for(int j=0;j<i;j++)//runs from 0 to i-1
		{
			if(arr[i]==arr[j])
			{
				flag=true;
				break;
			}
		}
		// Skip this element if already processed
		if (flag == true)
			continue;

		// Count frequency
		int count = 1;
		for (int j = i + 1; j < n; j++) //runs from i+1 to n-1
		{
			if (arr[i] == arr[j]) 
				count++;
		}
		cout << arr[i] << " " << count << endl;
	}
}
//Above solution is clearly a O(N^2) solution as in worst case when all elements are distinct
//then the inner 2 loops for for a combined n times.
//Space complexity:O(1)

//Efficient solution using hashmap

void countFreq(int arr[], int n)
{
	unordered_map<int, int> mp;

	// Traverse through array elements and
	// count frequencies
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;//inserting all distinct array elements in hashmap. A distinct element will have value
					//0 so ++ is used to make value(frequency 1). For a duplicate element value is incremented.

	// Traverse through map and print frequencies
	for (auto x : mp)//keys will appear in any order because it uses internal hash functions.
		cout << x.first << " " << x.second << endl;
}
/*Time Complexity : theta(n) 
Auxiliary Space : O(n) nd not theta(N)
*/
//In above efficient solution, how to print elements in same order as they appear in input array?
void countFreq_Order(int arr[], int n)
{
    unordered_map<int, int> mp;
 
    // Traverse through array elements and
    // count frequencies
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
 
    // To print elements according to first
    // occurrence, traverse array one more time
    // print frequencies of elements and mark
    // frequencies as -1 so that same element
    // is not printed multiple times.
    for (int i = 0; i < n; i++) {
      if (mp[arr[i]] != -1)
      {
          cout << arr[i] << " " << mp[arr[i]] << endl;
          mp[arr[i]] = -1;
      }
    }
} 
int main()
{
	int arr[] = { 10, 20, 20, 10, 10, 20, 5, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	countFreq(arr, n);
	cout<<endl;
	countFreq_Order(arr,n);
	return 0;
}

