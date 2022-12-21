// C++ program to find median of a matrix
// sorted row wise
#include<bits/stdc++.h>
using namespace std;
//Simple Method: The simplest method to solve this problem is to store all the elements of the 
//given matrix in an array of size r*c. Then we can sort the array and find the 
//median element in O(r*c *log(r*c)). This method can actually be improved a bit using Quickselect method 
//which would find the median in auxillary array in O(r*c) time.
//Efficient solution
const int MAX = 100;

// function to find median in the matrix
int binaryMedian(int m[][MAX], int r ,int c)
{
	int min = INT_MAX, max = INT_MIN;
	for (int i=0; i<r; i++)
	{
		// Finding the minimum element
		if (m[i][0] < min)
			min = m[i][0];//The minimum element lies in the first column 

		// Finding the maximum element
		if (m[i][c-1] > max)
			max = m[i][c-1];//The max element lies in last column
	}

	int median_pos = (r * c + 1) / 2;
	while (min < max)
	{
		int mid = min + (max - min) / 2;//same as (min+max)/2 but used for optimization
		int mid_place = 0;//we have found a middle element.. Like when min=1 and max=40, min=20..Now 20 may or may 
					  //not lie in the matrix. We just want to find out how many elements are less than or
					  //equal to 20.
					  
		// Find count of elements smaller than mid
		for (int i = 0; i < r; ++i)
			mid_place += upper_bound(m[i], m[i]+c, mid) - m[i];//we found out the element greater than mid(20) in 
		//each row.. For row 1 it is 30. Now upper bound returns the address of 30. So we subtract
		//base address of current 1-D array(i) to get index of 30 which is 3. place=3+5+5=13.
		if (mid_place < median_pos)//if median lies towards the right of mid
			min = mid + 1;
		else
			max = mid;//we have not done max=mid-1 because mid_place could be equal to median position.
	}				  //in this case we just need to find some element between min or mid(or mid itself) which lies 
					  //in matrix because that would be the median.
	return min;//min and max are same now return any.
}
//Time complexity: O(R*log(max-min)* log(C)) We are running a while loop in which we find mid of max-min which
//explains log(max-min), also we are running a for loop for all rows which explains the R term is time complexity.
//Upper bound function basically performs binary search on elements of a row to find an element greater
//than mid and there are C elements in a row which explains the log C term.
// driver program to check above functions
int main()
{
	int r = 3, c = 5;
	int m[][MAX]= { {5,10,20,30,40}, {1,2,3,4,6}, {11,13,15,17,19} };
	cout << "Median is " << binaryMedian(m, r, c) << endl;
	return 0;
}

