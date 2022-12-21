#include <stdio.h>
#include <stdlib.h>
class Lower_Tri_Matrix
{
int *A;
int n;
public:
Lower_Tri_Matrix(int n){
	this->n=n;
	A=new int[n*(n+1)/2];
}
void Set(int i,int j,int x);
int Get(int i,int j);
void Display();
};
void Lower_Tri_Matrix::Set(int i,int j,int x)
{
if(i>=j)
A[i*(i-1)/2+j-1]=x;
}
int Lower_Tri_Matrix::Get(int i,int j)
{
if(i>=j)
return A[i*(i-1)/2+j-1];
else
return 0;
}
void Lower_Tri_Matrix::Display()
{
int i,j;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(i>=j)
printf("%d ",A[i*(i-1)/2+j-1]);
else
printf("0 ");
}
printf("\n");
}
}
int main()
{
int i,j,x,n;
printf("Enter Dimension:");
scanf("%d",&n);
Lower_Tri_Matrix m(n);
printf("enter all elements\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&x);
m.Set(i,j,x);
}
}
printf("\n\n");
m.Display();
return 0;
}
