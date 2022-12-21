#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}

int partition(int A[],int l,int h)
{
int pivot=A[l];
int i=l,j=h;
do
{//very similar to hoare's partition algorithm
do{i++;}while(A[i]<=pivot);
do{j--;}while(A[j]>pivot);
if(i<j)swap(&A[i],&A[j]);
}while(i<j);
swap(&A[l],&A[j]);
return j;
}

void QuickSort(int A[],int l,int h)
{
int j;
if(l<h)
{
j=partition(A,l,h);
QuickSort(A,l,j);
QuickSort(A,j+1,h);
}
}

int main()
{
int A[]={7 ,72 ,90 ,21,60,INT_MAX},n=6,i;
QuickSort(A,0,n-1);
for(i=0;i<n;i++)
printf("%d ",A[i]);
printf("\n");
return 0;
}
