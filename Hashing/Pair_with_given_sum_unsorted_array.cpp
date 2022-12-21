/*
* This C++ program tells if there exists a pair in array whose sum results in x.
*/

#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
//Naive solution

// Function to find and print pair
bool chkPair(int A[], int size, int x) {
	for (int i = 0; i < (size - 1); i++) {
		for (int j = (i + 1); j < size; j++) {
			if (A[i] + A[j] == x) {
				cout << "Pair with a given sum " << x << " is (" << A[i] << ", " << A[j] << ")"
				<< endl;

				return 1;
			}
		}
	}

	return 0;
}
//O(N^2) solution

//Better solution using sorting and two pointer approach
bool hasArrayTwoCandidates(int A[], int arr_size,int sum)
{
    int l, r;
 
    /* Sort the elements */
    sort(A, A + arr_size);
 
    /* Now look for the two candidates in
       the sorted array*/
    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum)
            return 1;
        else if (A[l] + A[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
    return 0;
}
//O(N*logN) + O(N) solution for unsorted arrays. 

//Efficient approach using hashing
bool printPairs(int arr[], int arr_size, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < arr_size; i++)
    {
        int temp = sum - arr[i];
 
        if (s.find(temp) != s.end())
        {
        	cout << "Pair with given sum "
                 << sum << " is (" << arr[i] << ","
                    << temp << ")" << endl;
                    return true;//when sum is found break.
		} 
        s.insert(arr[i]);
    }
    return false;
}
//Time complexity:O(N)
//Space complexity: O(N) (Big Oh)
//A wrong solution is to insert all array elements in the hash set and then finding an element
//equal to sum-arr[i]. This fails for case arr[]= 11, 5, 6 and sum=10 as for sum-5 we find 5 in
//hash set and this gives wrong ans. So in above solution we check if any element before arr[i] forms 
//sum=sum with arr[i] and then insert arr[i] in hash set.
int main() {
	int A[] = {11,5,6};
	int x = 10;
	int size = sizeof(A) / sizeof(A[0]);

	if (printPairs(A, size, x)) {
		cout << "Valid pair exists" << endl;
	}
	else {
		cout << "No valid pair exists for " << x << endl;
	}

	return 0;
}
