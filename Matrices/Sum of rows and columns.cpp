#include <iostream>
using namespace std;
void row_sum(int **arr,int m, int n)
{

	int i,j,sum = 0;
	cout << "\nFinding Sum of each row:\n\n";
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			sum = sum + arr[i][j];
		}

		cout<< "Sum of the row "<< i << " = " << sum<< endl;
		sum = 0;
	}
}
void column_sum(int **arr,int m, int n)
{

	int i,j,sum = 0;

	cout << "\nFinding Sum of each column:\n\n";
	for (i = 0; i < m; ++i) {
		for (j = 0; j < n; ++j) {
			sum = sum + arr[j][i];
		}
		cout<< "Sum of the column "<< i << " = " << sum<< endl;
		sum = 0;
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
		cout<<endl;
	}
	row_sum(arr,m,n);
	column_sum(arr,m,n);
	return 0;
}

