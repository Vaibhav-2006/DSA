#include <iostream>
using namespace std;
 
void spiralPrint(int m, int n, int **a)
{
    int i, top = 0, left = 0, bottom=m-1, right=n-1;
 
    /* top - starting row index
       bottom - ending row index
       left - starting column index
       right - ending column index
    */
 
    while (top <= bottom && left <= right) {
        /* Print the first row from the remaining rows */
        for (i = left; i <= right; ++i) {
            cout << a[top][i] << " ";
        }
        top++;
 
        /* Print the last column from the remaining columns */
        for (i = top; i <= bottom; ++i) {
            cout << a[i][right] << " ";
        }
        right--;
 
        /* Print the last row from the remaining rows */
        if (top <= bottom) {// this condition is very imp in case suppose there are 5 rows then top will print row 0 1 
            for (i = right; i >= left; --i) {//bottom will print 4 3 and then in last iteration top will print row 2 and 
                cout << a[bottom][i] << " ";//bottom wont print the same row again
            }
            bottom--;
        }
 
        /* Print the first column from the remaining columns */
        if (left <= right) {
            for (i = bottom; i >= top; --i) {
                cout << a[i][left] << " ";
            }
            left++;
        }
    }
}
 

int main()
{
    int **a,k=1;
	a=new int*[5];
	for(int i=0;i<5;i++)
	{
	a[i]=new int[4];
	for(int j=0;j<4;j++)
	a[i][j]=k++;
	}
 
    spiralPrint(5, 4, a);
    return 0;
}
