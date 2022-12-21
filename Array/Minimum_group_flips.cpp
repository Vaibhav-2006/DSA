// C++ program to find minimum number of group filps
// to make binary array have the same elements
#include<iostream>
using namespace std;
/*
A Naive Solution is to traverse do two traversals of the array. We first traverse to find the number
of groups of 0s and the number of groups of 1.  We find the minimum of these two.  
Then we traverse the array and flip the 1s if groups of 1s are less. Otherwise, we flip 0s.
*/

/*
An Efficient Solution is based on the below facts : 

There are only two types of groups (groups of 0s and groups of 1s) which can only be present in alternating fashion.
Either the counts of both groups are same or the difference between counts is at most 1. 
For example, in {1, 1, 0, 1, 0, 0} there are two groups of 0s and two groups of 1s.  
In example, {1, 1, 0, 0, 0, 1, 0, 0, 1, 1}, count of groups of 1 is one more than the counts of 0s.
{1,1,1,1} has many ones and still count of groups of 1 is 1 more than count of groups of 0.
If the element present at index 0 is 1 then zeros will be flipped else ones will be flipped.
Because element present at index 0 will always belong to the group having the maximum or equal count.

Based on the above facts, we can conclude that if we always flip the second group and other 
groups that of the same type as the second group, we always get the correct answer.  
In the first case, when group counts are the same, it does not matter which group type we flip as 
both will lead to the correct answer.  In the second case, when there is one extra, by ignoring the 
first group and starting from the second group, we convert this case to 
first case (for subarray beginning from the second group) and get the correct answer.
*/

void printGroups(bool arr[], int n) {
   
  // Traverse through all array elements
  // starting from the second element
  for (int i = 1; i < n; i++) {
     
    // If current element is not same
    // as previous
    if (arr[i] != arr[i - 1]) {
       
      // If it is same as first element
      // then it is starting of the interval
      // to be flipped.
      if (arr[i] != arr[0])
        cout << "From " << i << " to ";
 
      // If it is not same as previous
      // and same as first element, then
      // previous element is end of interval
      else
        cout << (i - 1) << endl;
    }
  }
 
  // Explicitly handling the end of
  // last interval
  if (arr[n - 1] != arr[0])
    cout << (n - 1) << endl;
}
/*
Time Complexity:  O(n)
Auxiliary Space:  O(1)
*/
 
int main() {
  bool arr[] = {0, 1, 1, 0, 0, 0, 1, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  printGroups(arr, n);
  return 0;
}
