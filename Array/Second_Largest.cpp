//2nd largest element in array
//3 approaches
#include <bits/stdc++.h>
using namespace std;
 
//naive approach: 
/* Function to print the second largest elements */
void print2largest(int arr[], int arr_size)
{
    int i, first, second;
 
    /* There should be atleast two elements */
    if (arr_size < 2) {
        printf(" Invalid Input ");
        return;
    }
 
    // sort the array
    sort(arr, arr + arr_size);
 
    // start from second last element
    // as the largest element is at last
    for (i = arr_size - 2; i >= 0; i--) {
        // if the element is not
        // equal to largest element
        if (arr[i] != arr[arr_size - 1]) {
            printf("The second largest element is %d\n", arr[i]);
            return;
        }
    }
 
    printf("There is no second largest element\n");
}

/*Time Complexity: O(n log n). 
Time required to sort the array is O(n log n).
Auxiliary space: O(1). 
As no extra space is required.*/

//O(N) approach by scanning the array twice

int secondLargest(int arr[], int n) {
    int largest = 0, secondLargest = -1;
 
    // finding the largest element in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[largest])
            largest = i;
    }
 
    // finding the largest element in the array excluding
    // the largest element calculated above
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[largest]) {
            // first change the value of second largest
            // as soon as the next element is found
            if (secondLargest == -1)
                secondLargest = i;
            else if (arr[i] > arr[secondLargest])
                secondLargest = i;
        }
    }
    return secondLargest;
}
/*Time Complexity: O(n). 
Two traversals of the array is needed.
Auxiliary space: O(1). 
As no extra space is required.*/

//O(N) approach by scanning the array only once


// returns the index of second largest
// if second largest does not exist return -1
int SecondLargest(int arr[], int n) {
	int first = 0, second = -1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[first]) {
			second = first;
			first = i;
		}
      //if arr[i] == arr[first] then just ignore
		else if (arr[i] < arr[first]) {
			if (second == -1 || arr[second] < arr[i])
				second = i;// if arr[second] > arr[i] then just ignore.
		}
	}
	return second;
}

int main() {
	int arr[] = {10, 12, 20, 4};//{10,10,10} has no second largest, {20,20,10} has 10 as second largest.
	int index = secondLargest(arr, sizeof(arr)/sizeof(arr[0]));
	if (index == -1)
		cout << "Second Largest didn't exist";
	else
		cout << "Second largest : " << arr[index];
}


/*Time Complexity: O(n). 
Only one traversal of the array is needed.
Auxiliary space: O(1). 
As no extra space is required.*/
