// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
using namespace std;
//Naive approach: O((m+n)*(m+n)).
//copy all elements of a[m] and b[n] into c[m+n] and then remove duplicates in c[].

//Use sorting and merge process of merge sort. Check union of sorted arrays c++ file.
//O(N*logN) 

//efficient approach using hashing
void getUnion(int a[], int n, int b[], int m)
{
	
	// Defining set container s
	unordered_set<int> s;

	// Inserting array elements in s
	for (int i = 0; i < n; i++)
	s.insert(a[i]);

	for (int i = 0; i < m; i++)
		s.insert(b[i]);
	cout << "Number of elements after union operation: " << s.size() << endl;
	cout << "The union set of both arrays is :" << endl;
	for (auto i: s)
		cout << i<< " "; // s will contain only distinct
					// elements from array a and b
}
//The above method has time complexity theta(m+n) and Space complexity O(m+n) (Big Oh)

// Driver Code
int main()
{
	int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
	int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };

	getUnion(a, 9, b, 10);
}


