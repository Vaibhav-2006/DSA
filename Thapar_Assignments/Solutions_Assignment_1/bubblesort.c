#include<stdio.h>
#include<stdlib.h>
int bubble_sort(int c[],int size);
int main()
{
	int size,k;
	int a[]={64,34,25,12,22,11,90};
	size=7;
	bubble_sort(a,size);               
	printf("\n");                   
	return 0;                       
}
int bubble_sort(int *c, int n)
{
	int i=0,j=0,temp, flag;
	for(i=0;i<n-1;i++)// n-1 is used bcoz for n elements n-1 passes are required
	{
		flag=0;// flag is used to check if list is already sorted(adaptive case)
		for(j=0;j<n-1-i;j++)
		{
			if(c[j]>c[j+1])
			{
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
				flag=1;
			}
			
		}
		if(flag==0)
		break;
	}
	for(i=0;i<n;i++)
	printf("a[%d]=%d\t",i,c[i]);
	}
