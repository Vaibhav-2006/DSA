#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int Bin(int a[],int beg,int end,int num)//using recursion
{
	int middle= (beg+end)/2;
	if(end>=beg){
	if(a[middle]==num) 
	return middle;
	else if(a[middle]<num)// 10 20 30 40 50 60
	return Bin(a,middle+1,end,num);
	else
	return Bin(a,beg,middle-1,num);
	}
	return (signed)-1;
}
int main()
{
	int i,size,num;
	printf("Enter size of array:");
	scanf("%d",&size);
	int *a= (int*) malloc(size * sizeof(int));
	if(size<=0)
	exit(0);
	for(i=0;i<size;i++)
	{
	printf("Enter element:");
	scanf("%d",&a[i]);
}
printf("Enter the number to be searched for:");
scanf("%d",&num);
i=Bin(a,0,size-1,num);
printf("Element found at index number:%d",i);
return 0;
}
