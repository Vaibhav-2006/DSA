#include<stdio.h>
void transpose(int a[3][3])
{
int temp,i,j;
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=i;j<3;j++)
		{
		temp=a[i][j];
		a[i][j]=a[j][i];
		a[j][i]=temp;	
		}
	}
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
}
int main()
{
	int a[3][3],i,j;
	for(i=0;i<3;i++)
	{ 	printf("\n");
		for(j=0;j<3;j++)
		{
		printf("Enter a[%d][%d]",i,j);
		scanf("%d",&a[i][j]);	
	}
	}
	for(i=0;i<3;i++)
	{ 	printf("\n");
		for(j=0;j<3;j++)
		{
			printf("a[%d][%d]= %d\t",i,j,a[i][j]);
		}}
		printf("\n\n");
	transpose(a);
}
