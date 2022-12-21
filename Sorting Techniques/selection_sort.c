#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}
void SelectionSort(int A[],int n)
{
int i,j;
for(i=0;i<n-1;i++)
{
min_index=i;
for(j=i+1;j<n;j++)
{
if(A[j]<A[min_index])
min_index=j;
}
swap(&A[i],&A[min_index]);
}
}
int main()
{
	int n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	int *a= (int*) malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("\na[%d]=",i);
		scanf("%d",&a[i]);
	}
	SelectionSort(a,n);
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}
