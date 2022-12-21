#include<stdio.h>
#include<stdlib.h>
int asc_sort(int c[],int size);
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
	asc_sort(a,n);
	printf("\n");
	return 0;
}
int asc_sort(int *c, int size)
{
	int i=0,j=0, temp;
	for(j=1; j<size; j++)
	{
		temp=c[j];
		i=j-1;
		while(i>=0&&c[i]>temp)// we do not use c[i]>= temp so that this algo remains stable.
		{
		c[i+1]=c[i];
		i--;
		}
		c[i+1]=temp;
	}
	for(i=0;i<size;i++)
	printf("a[%d]=%d\t",i,c[i]);
}
