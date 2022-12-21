#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int search(int *a, int size, int num)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==num)
		return i;
	}
	printf("Element not found");
return -1;
}
int min_search(int *a, int size)
{
	int i;
	int min=a[0];
	for(i=1;i<size;i++)
	{
		if(min>a[i])
		min=a[i];
	}
	return min;
}
int main()
{
int i,size,num;
	printf("Enter size of array:");
	scanf("%d",&size);
	int *a= (int*) malloc(size * sizeof(int));
	if(size<=0)
	exit(1);
	for(i=0;i<size;i++)
	{
	printf("Enter element:");
	scanf("%d",&a[i]);
}
printf("Enter the number to be searched for:");
scanf("%d",&num);
i=search(a,size,num);
if(i>=0)
printf("Element found at index:%d ",i);
printf("\nMinimum Element in the array: %d",min_search(a,size));
}


