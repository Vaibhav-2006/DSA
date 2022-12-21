#include<stdio.h>
#include<stdlib.h>
//For a successful search the time complexity will be Big Oh(logn) and not theta(log) n as a successful search can happen
//in 1 iteration in the best case and theta denotes a tight bound. But an unsuccesful search is always theta(log n).
int Bin(int a[], int size, int num)
{
	int beg=0, end= size-1, middle;
	while(beg<=end)
	{// 0 1 2 3 4 5  //3 5
		middle= (beg+end)/2;
		if(a[middle]==num){
	 return middle;
	 }
		else if(a[middle]>num)
		end= middle-1;
		else 
		beg= middle+1;
	}
	puts("Element not found");
	exit(0);
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
	i=Bin( a, size, num);
	printf("Element found at index: %d", i);
	return 0;
}
