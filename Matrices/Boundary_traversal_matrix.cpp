// C++ program to print boundary element of
// matrix.
#include <bits/stdc++.h>
using namespace std;
//O(N^2) naive solution:
void printBoundary(int a[][4], int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				cout << a[i][j] << " ";
			else
				cout << " "
					<< " ";
		}
		cout << "\n";
	}
}

//Better approach:
void bTraversal( int mat[4][4], int R, int C)
{
	if(R==1)//the if and else if conditions are required to tackle two boundary cases, the first one being when
	{// there is only 1 row and the second one being when there is 1 column.
		for(int i=0;i<C;i++)
			cout<<mat[0][i]<<" ";
	}
	else if(C==1)
	{
		for(int i=0;i<R;i++)
			cout<<mat[i][0]<<" ";
	}
	else
	{
		for(int i=0;i<C;i++)
			cout<<mat[0][i]<<" ";
		for(int i=1;i<R;i++)
			cout<<mat[i][C-1]<<" ";
		for(int i=C-2;i>=0;i--)
			cout<<mat[R-1][i]<<" ";
		for(int i=R-2;i>=1;i--)
			cout<<mat[i][0]<<" ";
	}
}
//Time complexity is theta(2R+2C) since we are printing two rows and two columns.
// Driver code
int main()
{
	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9,10,11,12 }, { 13, 14, 15, 16 } };
	bTraversal(a, 4, 4);
	return 0;
}

