#include<stdio.h>
void Insert(int H[],int n)
{
	int i=n, temp=H[i];
	
	while(i>1&&temp>H[i/2])
	{
		H[i]=H[i/2];
		i=i/2;
	}
	H[i]=temp;
}
int Delete(int A[],int size)
{ // size stores the index of the last element in the heap
int i=1, j=2*i,temp;
temp=A[1];
A[1]=A[size];
A[size]=temp;
	while(j<size)//so that size-1 th element is compared
	{
		if(j==size-1);
		else if(A[j+1]>A[j])
		j=j+1;
		if(A[j]>A[i]){
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i=j;
			j=2*i;
		}
		else break;
	}
	return A[size];
}
void Display(int H[], int size)
{
	int i;
	for(i=1;i<=size;i++)
	{
		printf("%d ",H[i]);
	}
	printf("\n");
}
int main()
{
	int H[]={0,4284,2547,7546,6309,2809,5555,9999};
	//Since indexing is done from 0 in c/cpp so we have taken 0 at index 0.
	//Heap implemented here is using 1-based index so heap starts from index 1.
	int i,size_heap=7;
	for(i=2;i<=7;i++)
	Insert(H,i);
	Display(H,size_heap);
	for(i=7;i>1;i--)
	{
		Delete(H,i);
		size_heap-=1;
	}
	Display(H,7);
}
