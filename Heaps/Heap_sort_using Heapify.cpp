#include <iostream>
using namespace std;


void Heapify(int A[],int i,int n)
{
	int j=2*i,max_child,temp;
	if(j<=n)
	{
		if(j==n)
		max_child=j;
		else max_child=(A[j]>A[j+1]?j:j+1);
		
		if(A[max_child]>A[i])
		{
			temp=A[i];
			A[i]=A[max_child];
			A[max_child]=temp;
			Heapify(A,max_child,n);
		}
	}
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
}


int main()
{
	int *H,n;
	cout<<"Enter the number of elements in the heap: ";
	cin>>n;
	H=new int[n+1];//1.2.3.4..n as index 0 is ignored
	cout<<"Enter the elements of the heap:\n";
	for(int i=1;i<=n;i++)
	cin>>H[i];
	for(int i=n/2;i>=1;i--){
		Heapify(H,i,n);
	}
	Display(H,n);
	cout<<"\n";
	for(int i=n;i>1;i--)
	{
		Delete(H,i);
	}	
	Display(H,n);
}
