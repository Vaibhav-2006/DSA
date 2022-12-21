// C++ program to count number of occurrences of
// each element in the array in O(n) time and O(1) space

#include <iostream>
using namespace std;
void findFrequencies(int ele[], int n)
{
	int freq = 1;//frequency of element at index 0 is 1 at least
	int idx = 1;
	int element = ele[0];
	while (idx < n) {
		// check if the current element is equal to
		// previous element.
		if (ele[idx - 1] == ele[idx]) {
			freq++;
			idx++;
		}
		else {
			cout << element << " " << freq << endl;
			element = ele[idx];
			idx++;
		
			// reset the frequency
			freq = 1;
		}
	}

	// print the last element and its frequency
	cout << element << " " << freq;
}

int main()
{
	cout << "---frequencies in a sorted array----" << endl;
	int arr[]
		= { 10, 20, 30, 30, 30, 40, 50, 50, 50, 50, 50 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findFrequencies(arr, n);
}


