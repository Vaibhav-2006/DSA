// C++ program to rotate a matrix
// by 90 degrees
#include <bits/stdc++.h>
#define N 4
using namespace std;

void displayMatrix(int mat[N][N]);
//Naive approach using O(N^2) space and time
//Observe that last column becomes first row, second last column the second row and so on.
void rotate90(int mat[N][N])
{
	int temp[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			temp[N-i-1][j]=mat[j][i];//first column on mat becomes last row of temp
	}
	displayMatrix(temp);//you can copy back temp to mat but it is not done here so that next function can also be called
}

//better approach using O(1) space and O(N^2) time.
//The problem is very similar to transpose.Suppose our first row is 1 2 3 4
//the our first column after 90 degree anti clockwise roatation should be:
/*
4 
3 
2
1
*/ //but when we take transpose we get 1 2 3 4(written vertically as above). So either we can reverse the column
//after transpose or reverse the row before transpose.
// An Inplace function to
// rotate a N x N matrix
// by 90 degrees in
// anti-clockwise direction
void rotateMatrix(int mat[][N])
{ //REVERSE every row. Can be done using STL reverse(mat[i],mat[i]+N)
	for(int i=0;i<N;i++)
		{
			int low=0, high=N-1;
			while(low<high)
			{
				swap(mat[i][low],mat[i][high]);
				low++;
				high--;
			}	
		}
	displayMatrix(mat);		//just to see reversal
// Performing Transpose
		for(int i=0;i<N;i++)
		{ for(int j=i;j<N;j++)
			swap(mat[i][j],mat[j][i]);
		}
	
}

// Function to print the matrix
void displayMatrix(int mat[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%2d ", mat[i][j]);

		printf("\n");
	}
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	// Test Case 1
	int mat[N][N] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};
		displayMatrix(mat);
	// Tese Case 2
	/* int mat[N][N] = {
						{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}
					};
	*/

	// Tese Case 3
	/*int mat[N][N] = {
					{1, 2},
					{4, 5}
				};*/

	// displayMatrix(mat);

	rotate90(mat);
	rotateMatrix(mat);
	// Print rotated matrix
	displayMatrix(mat);

	return 0;
}

