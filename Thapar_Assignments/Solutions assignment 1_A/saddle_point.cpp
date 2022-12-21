//A saddle point in a numerical array is a number that is larger
//than or equal to every number in its column, and smaller than or equal to every number in its row.
#include <iostream>
using namespace std;
bool column_check(int **arr,int x,int j, int m)
{
	for(int i=0;i<m;i++)
	if(x<arr[i][j])
	return 0;
	
	return 1;
}
bool row_check(int **arr,int x,int i, int n)
{
	for(int j=0;j<n;j++)
	if(x>arr[i][j])
	return 0;
	
	return 1;
}
void is_Saddle(int **arr,int m,int n){
	int i,j;
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
	if(column_check(arr,arr[i][j],j,m)&&row_check(arr,arr[i][j],i,n))
	cout<<arr[i][j]<<" is a saddle point\n";
	}
}
int main()
{
	int **arr;
	int i,j,m,n;
	cout<<"Enter the number of rows and columns: ";
	cin>>m>>n;
	arr=new int* [m];
	for(int i=0;i<m;i++)
	arr[i]=new int [n];
	cout<<"Now enter the elements of the matrix:\n";
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cin>>arr[i][j];
	}
	is_Saddle(arr,m,n);
	return 0;
}

