//Given an integer x, find it’s square root. If x is not a perfect square, then return floor(root(x)).
#include<iostream>
using namespace std;

//Naive approach
// Returns floor of square root of x
int FloorSqrt(int x)
{
    // Staring from 1, try all numbers until
    // i*i is greater than or equal to x.
    int i = 1;
    while (i*i <= x)
    {
      i++;
    }
    return i - 1;//works for x=0 and 1 also
}
/*
Complexity Analysis: 
Time Complexity: O(root n). 
Space Complexity: O(1). 
Constant extra space is needed.
*/

//Better approach using binary search

int floorSqrt(long int x)
{
    // Base cases
    if (x == 0)
        return x;
  
    long int low = 1, high = x, ans=-1;//returns -1 if x is negative
    while (low <= high) {
        long long mid = (low + high) / 2;
  
        // If x is a perfect square
        if (mid * mid == x)//a large number such as 10e6 causes overflow so use long or
            return mid;//mid==x/mid
            
        else if (mid*mid<x) 
		{
            low = mid + 1;//for x = 10 low=1 and mid=5 now 5*5>25 so then high is changed to 4 and mid is 2
            ans = mid;//2*2<10 but is still not the square root of 10 so we store 2 in ans and change low to 3
        }//to look for a better floor square root.. Now 3*3<10 is ans and then 4*4>10 and high(3)<low(4) so we exit loop
        else // If mid*mid is greater than x
            high = mid - 1;
    }
    return ans;
}
/*
Complexity Analysis: 
Time complexity: O(log n). 
The time complexity of binary search is O(log n).
Space Complexity: O(1). 
Constant extra space is needed.
*/
//The Binary Search can be further optimized to start with ‘start’ = 0 and ‘end’ = x/2.
//Floor of square root of x cannot be more than x/2 when x > 1.
int main()
{
    long long int x = 100;
    cout << floorSqrt(x) << endl;
    return 0;
}
