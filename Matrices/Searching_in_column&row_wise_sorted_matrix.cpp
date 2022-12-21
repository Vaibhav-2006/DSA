// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include <bits/stdc++.h>
const int R=4, C=4;
using namespace std;
//Naive approach O(N^2)
/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
void Search(int mat[R][C], int x)
{
	if (R == 0||C==0)//if number of rows or column is zero ,return
		return;
	
	//traverse through the matrix
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		//if the element is found
		if(mat[i][j] == x)
		{
			cout<<"Element found at ("<<i << ", " << j << ")\n";
			return;
		}
	}

	cout << "n Element not found";
}
//Slighly better solution could be to perform binary search on each row but this solution doesn't use the fact that the 
//matrix is also column wise sorted. O(N*logN) approach

//Best approach using the fact that the matrix is column wise and row wise sorted.
/*                { { 10, 20, 30, 40 },
					{ 15, 25, 35, 45 },
					{ 27, 29, 37, 48 },
					{ 32, 33, 39, 50 } } find 29
					Start with 45. since 45>29. eliminate its whole column. move left to 35
					now 35>39. eliminate that column too. move left to 25. 
					25<29. eliminate all elements left of 25 in same row(basically whole row is eliminated because 
					elements lying towards right have already been checked). Move below to 29.
					29=29 so we have found the element. return.
Q) Why do we start from top right?
Because in case we start from top left. If x(element to be searched)>a[0][0] then we have two directions
in which x can lie(down and right) and we do not want this. Same is the case with bottom right.
bottom left can be used in the same way as top right. These two start points give us a singular direction to move
in case current_element is less or greater than x.*/
void search(int mat[R][C], int x)
{
    if (R== 0||C==0)
        return;
   
    int smallest = mat[0][0], largest = mat[R - 1][C - 1];
    if (x < smallest || x > largest)
        return;
   
    // set indexes for top right element
    int i = 0, j = C - 1;
    while (i < R && j >= 0)
    {
        if (mat[i][j] == x)
        {
            cout << "Found at "<< i << ", " << j;
            return;
        }
        if (mat[i][j] > x)
            j--;//if a particular element is greater then all element to its right have already been found to be greater
       			//and also we need not check for elements lying below this element in the same column because those elements
        		//will obviously be greater. So we move the column index to left by 1.
		
		// Check if mat[i][j] < x
        else
            i++;//if an element is less than x then all elements to its right are greater than x because we started 
            	//from the top RIGHT index and we reached here. Also all elements to its left are obviously less than x.
            	//So we move below in the same column towards larger elements.
    }
 
    cout << "n Element not found";
    return;
}
//In worst case we move all the way left and then all the way down.
//So time complexity is (Big Oh) O(R+C) which is linear.
// Driver code
int main()
{
	int mat[4][4] = { { 10, 20, 30, 40 },
					{ 15, 25, 35, 45 },
					{ 27, 29, 37, 48 },
					{ 32, 33, 39, 50 } };
	search(mat, 29);

	return 0;
}

